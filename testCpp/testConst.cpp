//
// Created by baiiu on 2021/8/2.
//

#include "testConst.h"

void testReference(){

    int a = 1024;
    const int &ra = a;

    const int b = 1024;
    const int &rb = b;

    double c = 3.14;
    const int &rc = c;
}

void testPointer(){
    const double PI = 3.14;
    const double *p = &PI;
}


void testConst() {
    testReference();
    testPointer();
}