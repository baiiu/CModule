//
// Created by baiiu on 2020/12/23.
//

#include "day4_passpointer.h"

/*
 * 函数调用原理：值传递；实参的值赋给形参(编译原理)
 */
void change(int j) {
    printf("changing j = %d\n", j);
    j = 5;
}

void testI() {
    int i = 10;

    printf("before change: %d\n", i);
    change(i);
    printf("after change: %d\n", i);
}

/*
 * 引用传递，间接访问；
 * 传递i的地址，用指针变量接收，j存储i的地址，*j即i
 */
void changeReference(int *j) {
    printf("changing j = %d, p = %p, &j = %p\n", *j, j, &j); // j是栈上分配的变量，&j即该j的地址；j存储i传递过来的地址； *j即i
    *j = 5;
}


void testReferenceI() {
    int i = 10;

    printf("before change: %d, p = %p\n", i, &i);
    changeReference(&i);
    printf("after change: %d\n", i);
}

void day4_testPassPointer() {
//    testI();
    testReferenceI();
}