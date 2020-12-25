//
// Created by baiiu on 2020/12/25.
//

#include "day4_指针数组.h"

void test1() {
    int i = 1;
    int j = 2;
    int *a[2] = {&i, &j}; // 指针数组
    printf("%d,%d\n", *a[0], *a[1]);
}

void test2() {
    char *a = "1";
    char *b = "2";
    char *arrA[] = {a, b}; // 字符串数组，用指针数组来表达
    char *arrB[] = {"1", "2"}; // 字符串数组，用指针数组来表达
    printf("%s,%s\n", arrA[0], arrA[1]);
    printf("%s,%s\n", arrB[0], arrB[1]);
}

// 指针数组
void day4_testPointerArr() {
    test1();

    test2();
}