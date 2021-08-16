//
// Created by baiiu on 2021/8/10.
//

#ifndef TESTCPP_TESTCONSTRUCTOR_H
#define TESTCPP_TESTCONSTRUCTOR_H


class Person {
private:
    int member = 0;

public:
    Person() = default;

    Person(int a) : member(a) {}
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
