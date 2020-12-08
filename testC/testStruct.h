//
// Created by baiiu on 2020/11/30.
//

#ifndef TESTC_TESTSTRUCT_H
#define TESTC_TESTSTRUCT_H

#include "common.h"

#define SET_RCVTIMEO(tv, s)    struct timeval tv = {s,0}

void testStruct();

// 4
struct C {
    int c;
} C;


// 8
struct B {
    int b;
    struct C c;
} B;


// 12
struct A {
    int a;
    struct B b;
} A;


// 4
struct CC {
    int cc;
} CC;

// 8
struct BB {
    struct CC *cc;
};

// 16,有对齐的操作
struct AA {
    struct CC *cc;
    int aa;
} AA;

#endif //TESTC_TESTSTRUCT_H
