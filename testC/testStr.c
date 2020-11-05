//
// Created by baiiu on 2020/11/3.
//

#include "testStr.h"

void testatoi() {
    char *str = "123abc";

    int p2 = atoi(str);
    printf("%d\n", p2);

    str = str + 1;
    printf("%s\n", str);
}

void testStr() {
    testatoi();
}