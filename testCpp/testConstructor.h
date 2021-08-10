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

void testConstructor();

#endif //TESTCPP_TESTCONSTRUCTOR_H
