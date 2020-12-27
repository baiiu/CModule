//
// Created by baiiu on 2020/12/26.
//

#include <setjmp.h>
#include "day5_函数jump.h"

jmp_buf envBuf;

void functionB() {
    printf("bbbbbbbbbb\n");
    longjmp(envBuf, 5); // 直接跳转到envBuf
}

void functionA() {
    printf("before aaaaaaaaaa\n");
    functionB();
    printf("after aaaaaaaaaaa\n");
}

// 直接跳转
void day5_funcJump() {
    int ret = setjmp(envBuf);
    printf("ret: %d\n", ret);

    if (ret == 0) {
        functionA();
    }
    printf("ret: %d\n", ret);

}