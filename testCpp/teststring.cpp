//
// Created by zhezhu on 2021/8/5.
//

#include "teststring.h"

void testString1(string &s) {

}

void testString2(const string &s) {

}

void testParams() {
//    testString1("11");
    testString2("11");

//    testString1(string("11"));
    testString2(string("11"));

    string s = string("11");
    testString1(s);
    testString2(s);

    s = "11";
    testString1(s);
    testString2(s);
}


void testEqual() {
    string s1 = "123";
    string s2 = "123";
    auto *s3 = new string("123");

    // 是
    printf("%p, %p， %p\n", &s1, &s2, s3); // 不同
    printf("是否相等: %d\n", (s1 == s2)); // true
    printf("是否相等: %d\n", (s1 == *s3));// true

    delete s3;
}

const string &testLocal() {
    return "123";
}

void testintarr() {
    int len = 8;
    uint8_t arr[] = {0, 1, 2, 3, 4, 5, 6, 7};
    uint8_t *data = arr;

    for (int i = 0; i < len; ++i) {
        printf("%d, ", data[i]);
    }

    printf("\n");

    char temp[len + 1];
    for (int i = 0; i < len; ++i) {
        temp[i] = '0' + data[i];
    }
    temp[len] = '\0';

    for (int i = 0; i < len + 1; ++i) {
        printf("%d, ", temp[i]);
    }
    printf("\n");

    printf("%s", temp);

}

void teststring() {
//    testParams();
//    testEqual();
//    testLocal();
    testintarr();
}


class MyString {
private:
    char *mData;
public:
    MyString() {
        mData = new char[1];
        *mData = '\0';
    }

    // 构造函数
    MyString(const char *str) {
        if (str) {
            int len = strlen(str);
            mData = new char[len + 1];
            memcpy(mData, str, len);
            mData[len] = '\0';
        } else {
            mData = new char[1];
            *mData = '\0';
        }
    }


    // 析构函数
    ~MyString() {
        if (mData) {
            delete[] mData;
            mData = nullptr;
        }
    }


    // 拷贝构造
    MyString(const MyString &other) {
        int len = strlen(other.mData);

        mData = new char[len + 1];
        strcpy(mData, other.mData);
    }

    // 拷贝赋值
    MyString &operator=(const MyString &other) {
        if (this == &other) {
            return *this;
        }

        delete[] mData;

        int len = strlen(other.mData);
        mData = new char[len + 1];
        strcpy(mData, other.mData);

        return *this;
    }

    // 移动构造
    MyString(MyString &&other) noexcept {
        mData = other.mData;
        other.mData = nullptr;
    }

    // 移动赋值
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