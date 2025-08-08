//
// Created by ByteDance on 2025/8/7.
//
#include "testLambda.h"

class TransactionCompletedListener {
private:
    TransactionCompletedListener() = default;

    ~TransactionCompletedListener() = default;

    TransactionCompletedListener(const TransactionCompletedListener &other) = delete;

    TransactionCompletedListener &operator=(const TransactionCompletedListener &other) = delete;

    std::unordered_map<void *, std::function<void()>> mQueueStallListeners;
    std::mutex mMutex;
public:
    static TransactionCompletedListener &getInstance() {
        static TransactionCompletedListener sInstance;
        return sInstance;
    }

    void onTransactionQueueStalled() {
        cout << "onTransactionQueueStalled" << endl;

        std::unordered_map<void *, std::function<void()>> callbackCopy;
        {
            std::lock_guard<std::mutex> lock(mMutex);
            callbackCopy = mQueueStallListeners;
        }
        for (auto const &it: callbackCopy) {
            it.second();
        }
    }

    void addQueueStallListener(std::function<void()> stallListener, void *id) {
        std::lock_guard<std::mutex> lock(mMutex);
        cout << "addQueueStallListener" << endl;
        mQueueStallListeners[id] = std::move(stallListener);
    }

    void removeQueueStallListener(void *id) {
        std::lock_guard<std::mutex> lock(mMutex);
        cout << "removeQueueStallListener" << endl;
        mQueueStallListeners[id] = nullptr;
        mQueueStallListeners.erase(id);
    }
};

class BLASTBufferQueue {
public:
    std::mutex mMutex;
    std::function<void(bool)> mTransactionHangCallback = nullptr;

    BLASTBufferQueue() {
        TransactionCompletedListener::getInstance().addQueueStallListener([&]() {

            std::function<void(bool)> callbackCopy;
            {
                std::lock_guard<std::mutex> lock(mMutex);
                cout << "BLASTBufferQueue#onQueueStall: " << &mTransactionHangCallback << endl;
                callbackCopy = mTransactionHangCallback;
            }
            if (callbackCopy) callbackCopy(true);
        }, this);
    }

    ~BLASTBufferQueue() {
        TransactionCompletedListener::getInstance().removeQueueStallListener(this);
    }

    void setTransactionHangCallback(std::function<void(bool)> callback) {
        std::lock_guard<std::mutex> lock(mMutex);
        cout << "BLASTBufferQueue#setTransactionHangCallback: " << &callback << ", " << &mTransactionHangCallback<< endl;
        mTransactionHangCallback = std::move(callback);
    }
};

class MyObject {
private:
    char *mName;
public:
    explicit MyObject(const char *name) {
        cout << "构造函数" << endl;
        mName = new char[strlen(name) + 1];
        strcpy(mName, name);
    };

    MyObject(const MyObject &other) {
        cout << "拷贝构造" << endl;
        mName = new char[strlen(other.mName) + 1];
        strcpy(mName, other.mName);
    }

    void doSomething(bool success) const {
        cout << "doSomething: " << mName << ", " << std::strlen(mName) << endl;
        printf("%s", mName);
    }

    ~MyObject() {
        cout << "~MyObject(): " << mName << ", " << std::strlen(mName) << endl;
        delete[] mName;
        mName = nullptr;
    }
};

void testFunction2() {

//    {
//        MyObject obj("test1");
//        obj.doSomething(true);
//    }
//
//    {
//        MyObject obj("AAAAA");
//        TransactionCompletedListener::getInstance().addQueueStallListener([obj]() {
//            obj.doSomething(true);
//        }, (void *) 1);
//        TransactionCompletedListener::getInstance().onTransactionQueueStalled();
//        TransactionCompletedListener::getInstance().removeQueueStallListener((void *) 1);
//    }
//
//    {
//        shared_ptr<MyObject> obj = make_shared<MyObject>("AAA");
//        TransactionCompletedListener::getInstance().addQueueStallListener([obj]() {
//            obj->doSomething(true);
//        }, (void *) 1);
//        TransactionCompletedListener::getInstance().onTransactionQueueStalled();
//        TransactionCompletedListener::getInstance().removeQueueStallListener((void *) 1);
//    }
//
//    {
//        std::shared_ptr<MyObject> p1 = std::make_shared<MyObject>("A");
//        BLASTBufferQueue queue;
//        queue.setTransactionHangCallback([p1](bool flag) {
//            if (flag) {
//                p1->doSomething(flag);
//            }
//            cout << "test" << endl;
//        });
//        TransactionCompletedListener::getInstance().onTransactionQueueStalled();
//    }


//    {
//        BLASTBufferQueue queue;
//        {
//            auto *obj = new MyObject("A");
//            queue.setTransactionHangCallback([obj](bool flag) {
//                if (flag) {
//                    obj->doSomething(flag);
//                }
//                cout << "test" << endl;
//            });
//            delete obj;
//        }
//        TransactionCompletedListener::getInstance().onTransactionQueueStalled();
//    }

    // 新增测试用例：lambda捕获即将失效的栈对象
//    {
//        BLASTBufferQueue queue;
//        {
//            MyObject stackObj("StackObject"); // 栈对象将在作用域结束时析构
//            queue.setTransactionHangCallback([&](bool flag) { // 危险：捕获栈对象引用
//                if (flag) {
//                    stackObj.doSomething(true);
//                }
//            });
//        } // stackObj 在此处析构
//    }

    {
        BLASTBufferQueue *queue = new BLASTBufferQueue();
        MyObject *heapObj = new MyObject("HeapObject");
        queue->setTransactionHangCallback([heapObj](bool flag) { // 原始指针捕获
            if (flag) {
                heapObj->doSomething(true);
            }
        });
        delete heapObj; // 提前释放对象
        delete queue;   // 触发监听器移除，此时std::function析构会访问已释放的heapObj
    }


}
