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
    printf("str: %s\n", str);

    char *str1 = "123";
    printf("str1: %s\n", str1);

//    *str = *str1; // 因为在常量区啊，没法赋值
    printf("===str: %s", str);

    str = str1;
    printf("======str: %s", str);

}

void testStr() {
//    testatoi();
    printLen();
}