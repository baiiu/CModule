//
// Created by zhezhu on 2020/12/24.
//

#include "day4_stackoverflow.h"

#define N 2621440

/*
 * 在栈上分配超大内存，爆栈了，会抛出stackOverflow
 *
 * windows函数栈大小是1M，linux是10M。
 */
void day4_testStackOverFlow() {

    int a[N];
//    int *a = (int *) malloc(N * sizeof(int));
    a[N - 1] = 10;
    printf("%d", a[N - 1]);
}