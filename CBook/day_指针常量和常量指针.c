//
// Created by baiiu on 2020/12/31.
//

#include "day_指针常量和常量指针.h"


void day_testConstPointer() {
    int a = 1;
    int b = 2;

    // 常量指针，指针指向的值不可用改，但指针的指向可以改
    const int *p = &a;
    // *p = b; 错误，指向的值不可用改
    p = &a; // 指针的指向可以改

    // 指针常量，指针的指向可以改，指针指向的值可以改
    int *const p2 = &a;
    *p2 = b; // 指针指向的值可以改
    // p2 = &b; 错误，指针的指向不可用改

    // const修饰指针和常量，都不可用改
    const int *const p3 = a;
    // *p3 = b;
    // p3 = &b;
}