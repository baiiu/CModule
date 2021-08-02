//
// Created by baiiu on 2021/7/19.
//

#include "testPointer.h"


void hasRes(char **res) {
    *res = "123";
}

void testDoublePointer() {
    char *msg;
    hasRes(&msg);
    printf("testPointer msg: %s\n", msg);


    char res[100];
    char *p = "";
    hasRes(&p);
    printf("testPointer res: %s\n", p);
    hasRes((char **) &res);
    printf("testPointer res: %s\n", res);
}