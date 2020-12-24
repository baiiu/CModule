//
// Created by zhezhu on 2020/12/24.
//

#include "day4_栈和堆差别.h"

/*
 * 在堆上分配的栈空间，函数出栈后即被回收
 */
char *print_stack() {
    char c[] = "I am stack";
    return c;
}

/*
 * 堆不会因为函数执行结束而释放
 */
char *print_malloc() {
    char *p = (char *) malloc(20 * sizeof(char)); // 在堆上分配
    strcpy(p, "I am malloc");
    return p;
}

void day4_testMallocAndStack() {
    char *p;
    p = print_stack();
    puts(p);

    p = print_malloc();
    puts(p);
}
