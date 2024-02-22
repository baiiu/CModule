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
        cout << "单参构造函数" << endl;
        mData = new char[strlen(data)];
        strcpy(mData, data);
    }

    ~MyString() {
        cout << mData << "析构函数" << endl;
        if (mData) {
            delete[] mData;
            mData = nullptr;
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
};

ostream &operator<<(ostream &out, MyString &myStr) {
    return out << myStr.mData;
}

void testSmartPtr() {
    MyString s; // 默认初始化，栈对象
    MyString s1 = "123"; // 隐式类型转换，栈对象
    MyString s2("123"); // 值初始化，栈对象
//    cout << s2 << endl;

    shared_ptr<MyString> p1; // 声明一个指针，未进行初始化，默认初始化的智能指针中保存着一个空指针

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

}