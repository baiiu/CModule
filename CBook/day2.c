//
// Created by zhezhu on 2020/12/17.
//

#include "day2.h"

// 整型
void testInt() {

    int i = 0x80fb0000; // 首位为符号位
    unsigned int ui = 0x80fb0000;
    short j = 32767; // 0111 1111 1111 1111
    long k = 0;

    printf("%d， %d, %d\n", sizeof(j), sizeof(i), sizeof(k));
    printf("%d, %u\n", i, ui); // 使用%u输出unsiged

    printf("%d\n", j);
    ++j;
    printf("%d", j); // 溢出

}

// 浮点型
void testFloat() {
    // float 4字节， double 8字节

    float a = 0.001; // 小数形式 1e-3
    float b = 1e3;  // 指数形式  1000

    double c = 1e-3;

    printf("%f, %f\n", a, b);
    printf("%d, %d\n", sizeof(a), sizeof(c));

}


void day2() {
    testFloat();
}