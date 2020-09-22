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

void passObject(Object *obj);

void printObject(Object obj);

void hello();

void hello2();

Object hello3(char *str); //指针函数
Object *hello31(char *str); //指针函数
Object *hello4(char *str); //指针函数

#endif //TESTC_HELLO_H
