//
// Created by zhezhu on 2020/12/17.
//

#include "day2.h"

void day2() {

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