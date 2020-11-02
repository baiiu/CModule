//
// Created by baiiu on 2020/9/18.
//

#ifndef TESTC_HELLO_H
#define TESTC_HELLO_H

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct Object {
    char *str;
    char strArr[20];
} Object;

void testHello();

#endif //TESTC_HELLO_H
