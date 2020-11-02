//
// Created by baiiu on 2020/11/2.
//

#include "hookFunction.h"


void (*fun)();

void fun1() {
    printf("fun1");
}

void fun2() {
    printf("fun2");
}

int RegisterFun(void (*pFun)()) {
    fun = pFun;
    return 0;
}

void testHook() {

    // 挂勾子
    RegisterFun(fun1);
    fun();

    // 挂勾子
    RegisterFun(fun2);
    fun();

}