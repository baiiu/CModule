//
// Created by baiiu on 2023/2/28.
//

#include <setjmp.h>
#include <printf.h>
#include "testJump.h"
#include "common.h"

jmp_buf jmpbuffer;

static void print_0(int i) {
    printf("print_0 start : i = %d\n", i);
    i += 10;
    printf("print_0 end : i = %d\n", i);

    longjmp(jmpbuffer, 1);
    printf("print_0 return");
}

static void print_1(int i) {
    printf("print_1 start : i = %d\n", i);
    i += 11;
    printf("print_1 end : i = %d\n", i);

    longjmp(jmpbuffer, 2);
    printf("print_1 return");
}

static void print_2(int i) {
    printf("print_2 start : i = %d\n", i);
    i += 12;
    printf("print_2 end : i = %d\n", i);

    longjmp(jmpbuffer, 3);
    printf("print_2 return");
}

static void print_3(int i) {
    printf("print_3 start : i = %d\n", i);
    i += 13;
    printf("print_3 end : i = %d\n", i);

    printf("print_3 return\n");
}

void testJump() {
    int i = 0;
    int flag;

    int start = av_gettime();
    flag = setjmp(jmpbuffer);
    int end = av_gettime();
    printf("cost %d\n", end - start);

    if (flag == 0) {
        print_0(i);
    } else if (flag == 1) {
        print_1(i);
    } else if ((flag == 2)) {
        print_2(i);
    } else {
        print_3(i);
    }
}