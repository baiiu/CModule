//
// Created by baiiu on 2022/3/9.
//

#include "testSingleton.h"
#include <mutex>
#include <iostream>

using namespace std;

class Singleton {
private:
    Singleton() {};

    Singleton(const Singleton &other) {};

public:
    static std::atomic<Singleton *> mInstance;
    static std::mutex m_mutex;

    static Singleton *getInstance();
};

std::atomic<Singleton *> Singleton::mInstance;
std::mutex Singleton::m_mutex;


Singleton *Singleton::getInstance() {
    Singleton *temp = mInstance.load(std::memory_order_relaxed);
    std::atomic_thread_fence(std::memory_order_acquire); // 获取内存fence

    if (temp == nullptr) {
        std::lock_guard<std::mutex> lock(m_mutex);
        temp = mInstance.load(std::memory_order_relaxed);

        if (temp == nullptr) {
            temp = new Singleton;
            std::atomic_thread_fence(std::memory_order_release); // 释放内存fence
            mInstance.store(temp, std::memory_order_relaxed);
        }
    }

    return temp;
}


class SimpleSingleton {
private:
    static SimpleSingleton *sInstance;

    SimpleSingleton();

    SimpleSingleton(const SimpleSingleton &other);

public:
    // 线程非安全版本
    static SimpleSingleton *getInstance();
};


SimpleSingleton *SimpleSingleton::sInstance = nullptr;

SimpleSingleton::SimpleSingleton() {}

SimpleSingleton::SimpleSingleton(const SimpleSingleton &other) {}

SimpleSingleton *SimpleSingleton::getInstance() {
    if (sInstance == nullptr) {
        sInstance = new SimpleSingleton;
    }

    return sInstance;
}

// 在类内实现
class ASimpleSingleton {
private:
    static ASimpleSingleton *instance;
private:
    ASimpleSingleton() {};

    ~ASimpleSingleton() {};

    ASimpleSingleton(const ASimpleSingleton &);

    ASimpleSingleton &operator=(const ASimpleSingleton &);

public:
    static ASimpleSingleton *getInstance() {
        if (instance == NULL)
            instance = new ASimpleSingleton();
        return instance;
    }
};

// init static member
ASimpleSingleton *ASimpleSingleton::instance = NULL;

// call_once
class SingleWithPtr {
private:
    SingleWithPtr(const SingleWithPtr &other) = delete;

    SingleWithPtr &operator=(const SingleWithPtr &other) = delete;

public:
    SingleWithPtr() = default;

    ~SingleWithPtr() {}

    static std::shared_ptr<SingleWithPtr> getInstance() {
        static std::shared_ptr<SingleWithPtr> sInstance;
        static std::once_flag flag;
        std::call_once(flag, [&]() {
            sInstance = std::make_shared<SingleWithPtr>();
        });

        return sInstance;
    }
};

class SingletonOnce {
private:
    SingletonOnce() = default;

    SingletonOnce(const SingletonOnce &other) = delete;

    SingletonOnce &operator=(const SingletonOnce &other) = delete;

public:
    ~SingletonOnce() = default;

    void print() {
        std::cout << "123" << std::endl;
    }

    static std::shared_ptr<SingletonOnce> getInstance() {
        static std::shared_ptr<SingletonOnce> _instance;
        static std::once_flag s_flag;
        std::call_once(s_flag, [&]() {
            _instance = std::shared_ptr<SingletonOnce>(new SingletonOnce);
        });
        return _instance;
    }
};


class BestSingle {
private:

    BestSingle() {}

    ~BestSingle() {}

    BestSingle(const BestSingle &other) = delete;

    BestSingle &operator=(const BestSingle &other) = delete;

public:
    static BestSingle &getInstance() {
        static BestSingle sInstance;
        return sInstance;
    }
};


void testSingleton() {
    ASimpleSingleton *a = ASimpleSingleton::getInstance();
    SimpleSingleton *b = SimpleSingleton::getInstance();
    Singleton *c = Singleton::getInstance();
    cout << "single: " << a << ", " << b << ", " << c << endl;


    BestSingle &d = BestSingle::getInstance();
    cout << &d << endl;

    SingleWithPtr::getInstance();

    std::shared_ptr<SingletonOnce> ptr = SingletonOnce::getInstance();
    ptr->print();

}