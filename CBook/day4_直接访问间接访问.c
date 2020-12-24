//
// Created by baiiu on 2020/12/22.
//

#include "day4_直接访问间接访问.h"


void testPointer() {
    int i = 10;
    int *i_pointer = &i;

    printf("i = %d\n", i); // 直接访问
    printf("*i_pointer = %d\n", *i_pointer); // 间接访问，指针变量的本质
}


// 指针
void day4() {
    testPointer();
}