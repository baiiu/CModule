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

void test0() {
    char *str = (char *) malloc(10 * sizeof(char));
    memset(str, 65, 10); // memset是设置的真实的 Unicode-8进去的

    printf("str: %s\n", str); // AAAAAAAAAA
    printf("sizeof *str: %lu\n", sizeof(*str)); // 1
    printf("sizeof str: %lu\n", sizeof(str)); // 8
    printf("strlen: %lu\n", strlen(str)); // 10

    memcpy(str, "123", 2); // 只拷贝1、2
    printf("str: %s\n", str); // 12AAAAAAAA
    printf("strlen: %lu\n", strlen(str)); // 10


    memcpy(str, "123", 4); // 拷贝1、2、3，第4位补0
    printf("str: %s\n", str); // 123
    printf("strlen: %lu\n", strlen(str)); // 3


    strcpy(str, "123456"); // 会把\0也拷贝进去
    printf("str: %s\n", str); // 123456
    printf("strlen: %lu\n", strlen(str)); // 6


}

void testStr() {
//    testatoi();
//    printLen();
    test0();
}