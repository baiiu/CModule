//
// Created by baiiu on 2020/11/30.
//

#ifndef TESTC_TESTSTRUCT_H
#define TESTC_TESTSTRUCT_H

#include "common.h"

#define SET_RCVTIMEO(tv, s)    struct timeval tv = {s,0}

void testStruct();

struct C {
    int c;
} C;

struct B {
    int b;
    struct C c;
} B;

struct A {
    int a;
    struct B b;
} A;


#endif //TESTC_TESTSTRUCT_H
