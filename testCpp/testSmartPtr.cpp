//
// Created by baiiu on 2022/3/7.
//

#include <cstring>
#include "testSmartPtr.h"

class MyString {
private:
    char *mData;

    friend ostream &operator<<(ostream &out, MyString &myStr);

public:
    MyString() {
        cout << "默认无参构造函数" << endl;
        mData = new char[1];
        *mData = '\0';
    }

    MyString(const char *data) {
        cout << "单参构造函数-隐式类型转换" << endl;
        mData = new char[strlen(data)];
        strcpy(mData, data);
    }

    ~MyString() {
        if (mData) {
            cout << mData << "~析构函数" << endl;
            delete[] mData;
            mData = nullptr;
        } else {
            cout << "~析构函数" << endl;
        }
    }

    MyString(const MyString &other) {
        cout << "拷贝构造函数" << endl;
        mData = new char[strlen(other.mData) + 1];
        strcpy(mData, other.mData);
    }

    MyString(MyString &&other) noexcept: mData(other.mData) {
        cout << "移动构造函数" << endl;
        other.mData = nullptr;
    }

    MyString &operator=(const MyString &other) {
        cout << "拷贝赋值函数" << endl;
        if (this == &other) {
            return *this;
        }

        delete[] mData;

        mData = new char[strlen(other.mData) + 1];
        strcpy(mData, other.mData);
        return *this;
    }

    MyString &operator=(MyString &&other) noexcept {
        cout << "移动赋值函数" << endl;
        if (this == &other) {
            return *this;
        }

        delete[] mData;
        mData = other.mData;
        other.mData = nullptr;
        return *this;
    }

    bool empty() const {
        return mData == nullptr || std::strlen(mData) == 0;
    }
};

ostream &operator<<(ostream &out, MyString &myStr) {
    return out << myStr.mData;
}

void testSmartPtr() {
//    {
//        MyString s; // 默认初始化，栈对象
//        MyString s1 = "s1"; // 隐式类型转换，栈对象
//        MyString s2("s2"); // 值初始化，栈对象
////    s1 = s2; // 左值拷贝，拷贝赋值函数
//        s1 = std::move(s2); // 右值移动，移动赋值函数
//        cout << s1 << endl;
////    cout << s2 << endl; // 移动源对象不可再使用
//    }

    {
        // 原始指针使用方式
        MyString *p;
        p = new MyString("p"); // 单参构造函数
        delete p; // p~析构函数
        p = nullptr; // 一定要重置为nullptr，减少出错

        shared_ptr<MyString> p1; // 声明一个指针，未进行初始化时他是一个空指针，直接使用会npe
        if (p1 == nullptr) {
            cout << "npe" << endl; // npe，声明一个指针的时候默认值是nullptr
        }
        shared_ptr<MyString> p01 = shared_ptr<MyString>(new MyString("p01")); // 单参构造函数，
        shared_ptr<MyString> p02 = make_shared<MyString>("p02"); // 单参构造函数，给该智能指针赋值
//        shared_ptr<MyString> p11 = new MyString("p11"); // 错误，因为shared_ptr禁用了隐式类型转换
        shared_ptr<MyString> p03(new MyString("p03")); // 正确，直接初始化,单参构造函数
    }
//    p03~析构函数
//    p02~析构函数
//    p01~析构函数

//    {
//        auto p1 = make_shared<MyString>("p1"); // 单参构造函数，给该智能指针赋值
//        cout << p1 << ", " << *p1 << ", " << p1->empty() << ", " << p1.use_count() << endl; // 0x6000012544b8, p1, 0, 1
//
//        shared_ptr<MyString> p2 = p1; // 当进行拷贝赋值操作时，每个shared_ptr都会记录有多少个其他shared_ptr指向相同的对象：
//        cout << p2 << ", " << *p2 << ", " << p2->empty() << ", " << p1.use_count() << endl; // 0x6000012544b8, p1, 0, 2
//
//        auto p3 = make_shared<MyString>("p3");
//        p3 = p1; // p3~析构函数
//        cout << p3 << ", " << *p3 << ", " << p3->empty() << ", " << p1.use_count() << ", " << p3.use_count()
//             << endl; // 0x6000012544b8, p1, 0, 3, 3
//    }
    // p1~析构函数


//    {
//        unique_ptr<MyString> p1;
//        if (p1 == nullptr) {
//            cout << "npe" << endl; // npe
//        }
//        unique_ptr<MyString> p2(new MyString("p2")); // 直接初始化，unique_ptr也禁用了隐式类型转换，单参构造函数
//
//        // unique_ptr无法拷贝构造和拷贝赋值
////        unique_ptr<MyString> p3(p2); // 错误，不支持拷贝
////        unique_ptr<MyString> p3 = p2; // 错误，不支持赋值
//
//        // 可以通过调用release或reset将指针的所有权从一个（非const）unique_ptr转移给另一个unique
//        unique_ptr<MyString> p3(p2.release()); // release将p2置为空
//        cout << p2 << "," << p3 << ", " << *p3 << endl; // 0x0,0x600000f58000, p2
//    }
    // p2~析构函数

//    weak_ptr<MyString> pOuter;
//    {
//        auto p1 = make_shared<MyString>("p1");
//        pOuter = p1;
//
//        weak_ptr<MyString> wp(p1); // 直接初始化
//        weak_ptr<MyString> wp2 = p1; // 赋值初始化
//        cout << p1 << ", " << *p1 << ", " << p1.use_count() << ", " << wp.use_count() << endl; // 0x600001b45218, p1, 1, 1
//
//        // lock返回一个指向共享对象的shared_ptr，可以被使用
//        auto p2 = wp.lock();
//        cout << (p1 == p2) << endl; // true
//    }
//    // p1~析构函数
//    cout << "weak_ptr<MyString> count: " << pOuter.use_count() << endl; // weak_ptr<MyString> count: 0



//    *p1 = MyString("p2");

//    shared_ptr<MyString> p2 = shared_ptr<MyString>(new MyString("123"));

//    auto myStr = make_shared<MyString>("456");
//    cout << myStr.use_count() << endl;
//
//    auto *ptr = new MyString("789");
//    delete ptr;
//
//    shared_ptr<int> ptr1(new int(5));
//    shared_ptr<int> ptr11 = make_shared<int>(1);
//
//    shared_ptr<MyString> ptr2(new MyString("101112"));
//
//    unique_ptr<MyString> ptr3(new MyString("131415"));

//    默认无参构造函数
//    单参构造函数-隐式类型转换
//    单参构造函数-隐式类型转换
//    移动赋值函数
//            s2
//    ~析构函数
//    s2~析构函数
//    ~析构函数
}