//
// Created by zhezhu on 2020/12/24.
//

#include "day4_stackoverflow.h"

#define N 8192

/*
 * 在栈上分配超大内存，爆栈了，会抛出stackOverflow
 *
 * windows函数栈大小是1M，linux是10M,通过 ulimit -a 查看
 */
void day4_testStackOverFlow() {
    int a[N * sizeof(int) * 1024 * 8]; // 在栈上，8192kbytes
//    int *a = (int *) malloc(N * sizeof(int)); // 在堆上分配
    a[N - 1] = 10;
    printf("%d", a[N - 1]);
}