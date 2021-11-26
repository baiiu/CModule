//
// Created by baiiu on 2021/8/10.
//

#ifndef TESTCPP_TESTCONSTRUCTOR_H
#define TESTCPP_TESTCONSTRUCTOR_H

#include "common.h"

struct Person {
private:
    const static int count0 = 10;
    constexpr static int count1 = 10;
//    static int count2 = 10; // Non-const static data member must be initialized out of line
    static int count3;

    int member = 0;

public:
    Person() = default;

    Person(int a) : member(a) {
        cout << "调用构造函数a" << endl;
    }

    Person(int a, int b) : member(a + b) {
        cout << "调用构造函数a, b" << endl;
    }

    Person(Person &p) : member(p.getMember()) {
        cout << "调用拷贝构造函数" << endl;
    }

    Person(Person &&p) : member(p.getMember()) {
        cout << "调用移动构造函数" << endl;
    }

    Person &operator=(const Person &p) {
        cout << "调用拷贝运算符" << endl;
        this->member = p.member;
        return *this;
    }

    int getMember() {
        return member;
    }
};


class ConstRef {
public:
//    ConstRef(int a) {
//        this->a = a;
//        ca = a; // Constructor for 'ConstRef' must explicitly initialize the const member 'ca'
//        ra = a; // Constructor for 'ConstRef' must explicitly initialize the reference member 'ra'
//    }

    ConstRef(int number) : a(number), ca(number), ra(number) {};

private:
    int a;
    const int ca;
    int &ra;
};


void testConstructor();

#endif //TESTCPP_TESTCONSTRUCTOR_H
