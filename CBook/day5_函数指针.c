//
// Created by baiiu on 2020/12/25.
//

#include "day5_函数指针.h"

void b() {
    printf("function b is called");
}

// 传递函数指针，传递一种行为
void a(void (*p)()) {
    p();
}

void day5_testFunPointer() {
    void (*p)(); // 定义函数指针
    p = b;
    a(p);
}