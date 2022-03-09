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
        mData = new char[1];
        *mData = '\0';
    }

    MyString(const char *data) {
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
        mData = new char[strlen(other.mData) + 1];
        strcpy(mData, other.mData);
    }

    MyString(MyString &&other) noexcept: mData(other.mData) {
        other.mData = nullptr;
    }

    MyString &operator=(const MyString &other) {
        if (this == &other) {
            return *this;
        }

        delete[] mData;

        mData = new char[strlen(other.mData) + 1];
        strcpy(mData, other.mData);
        return *this;
    }

    MyString &operator=(MyString &&other) noexcept {
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
//    MyString s;
    MyString s("123");
    cout << s << endl;

    auto myStr = make_shared<MyString>("456");
    cout << myStr.use_count() << endl;

    auto *ptr = new MyString("789");
    delete ptr;

    shared_ptr<int> ptr1(new int(5));

    shared_ptr<MyString> ptr2(new MyString("101112"));

    unique_ptr<MyString> ptr3(new MyString("131415"));

}