//
// Created by baiiu on 2021/8/10.
//

#include "testConstructor.h"


void testConstructor() {
    Person person(10);
    Person person2(); // Empty parentheses interpreted as a function declaration
    Person person1 = 10;


    ConstRef ref(10);
}