//
// Created by zhezhu on 2022/2/14.
//

#ifndef TESTCPP_HJSTAIC_H
#define TESTCPP_HJSTAIC_H

#include "../common.h"

struct A {
    int a = 5;

    A() {
        cout << "A 构造" << endl;
    }
};

class Account {
public:
    static double m_rate;
    static A a;

    static void set_rate(const double x) {
        m_rate = x;
    }
};


//class A {
//public:
//    static A &getInstance() {
//        return A::a;
//    }
//
//    void setup() {}
//
//private:
//    A() = default;;
//
//    A(const A &a) = default;
//
//    static A a;
//};

void hjStatic();

#endif //TESTCPP_HJSTAIC_H
