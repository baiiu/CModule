//
// Created by baiiu on 2021/8/2.
//

#include <cstdio>
#include "testConst.h"

void testConstReference() {

    int a = 1024;
    const int &ra = a;

    const int b = 1024;
    const int &rb = b;

    double c = 3.14;
    const int &rc = c;

    TEMP aa = &c;
    printf("aa: %f", *aa);
}

void testPointer() {
    const double PI = 3.14;
    const double *p = &PI;
}

class Person {
public:
    string name;
    mutable int age;
};

void testPerson(const Person *person) {
    person->age = 1; // 可以修改
//    person->name = "aa"; // 不可修改
}

void testPerson(const Person &person) {
    person.age = 1; // 可以修改
//    person.name = "aa"; // 不可修改
}

void testConst() {
//    testConstReference();
//    testPointer();
    Person p = {"张三", 10};
    testPerson(p);
}