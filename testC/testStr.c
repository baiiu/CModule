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

void printLen() {
    char *str = "rtmp://mtplatform-tx-origin.meituan.com/mtplatform/ddddd123";
    printf("str len: %d\n", strlen(str));
    printf("str len: %d\n", sizeof(str));
    printf("str len: %d\n", sizeof(*str));
}

void testStr() {
//    testatoi();
    printLen();
}