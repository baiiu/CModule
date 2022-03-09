//
// Created by baiiu on 2022/2/13.
//

#ifndef TESTCPP_HJSTRING_H
#define TESTCPP_HJSTRING_H

#include <cstring>
#include <iostream>

using namespace std;

class String {
public:
    String(const char *cstr = nullptr);

    // 拷贝构造,参数添加const，即不会改变原理的str
    String(const String &str);

    // 移动构造，不能加const，因为要修改str，避免双重free
    String(String &&str) noexcept;

    // 拷贝赋值
    String &operator=(const String &str);

    // 移动赋值，不能加const，因为要修改str，避免双重free
    String &operator=(String &&str) noexcept;

    ~String();

    inline char *get_c_str() const {
        return m_data;
    };

private:
    char *m_data;
};

inline ostream &operator<<(ostream &out, const String &str) {
    return out << str.get_c_str();
}

/*
 * 构造函数
 *
 * 示例：String(); String("hello");
 */
inline String::String(const char *cstr) {
    cout << "String构造函数" << endl;

    if (cstr) {
        m_data = new char[strlen(cstr) + 1];
        strcpy(m_data, cstr);
    } else {
        m_data = new char[1];
        *m_data = '\0';
    }
}

// 析构函数，清除指针，避免内存泄露
inline String::~String() {
    cout << "String析构函数" << endl;
    delete[] m_data;
}

// 拷贝构造
inline String::String(const String &str) {
    cout << "String拷贝构造" << endl;

    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
}

// 移动构造
inline String::String(String &&str) noexcept: m_data(str.m_data) {
    cout << "String移动构造" << endl;

    str.m_data = NULL; // 重要，避免双重free，即浅移动
}


// 拷贝赋值
inline String &String::operator=(const String &str) {
    cout << "String拷贝赋值" << endl;

    // 检测自我赋值，必须要添加，否则程序出错
    if (this == &str) {
        return *this;
    }

    delete[] m_data;
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
    return *this;
}

// 移动赋值
inline String &String::operator=(String &&str) noexcept {
    cout << "String移动赋值" << endl;

    // 检测自我赋值，必须要添加，否则程序出错
    if (this == &str) {
        return *this;
    }

    if (m_data) {
        delete[] m_data;
    }

    m_data = str.m_data;
    str.m_data = NULL;

    return *this;
}


void testString();

#endif //TESTCPP_HJSTRING_H
