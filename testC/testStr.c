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

void testPointer() {
    char *str = malloc(1316);
    printf("sizeof str: %lu\n", sizeof(str)); // 8
    printf("sizeof str: %lu\n", sizeof(*str)); // 1
    printf("sizeof str: %lu\n", strlen(str)); // 0

    memset(str, 0, 1316);
    printf("sizeof str: %lu\n", sizeof(str)); // 8
    printf("sizeof str: %lu\n", sizeof(*str)); // 1
    printf("sizeof str: %lu\n", strlen(str)); // 0

    free(str);


    char str2[1316];
//    printf("sizeof str2: %lu\n", sizeof(*str2)); // 1
//    printf("sizeof str2: %lu\n", strlen(str2)); // 0

    char src[50] = "123";
    printf("sizeof src: %lu\n", sizeof(*src)); // 1
    printf("sizeof src: %lu\n", strlen(src)); // 3
    for (int i = 0; i < 50; ++i) {
        printf("%d, ", (int) src[i]);
    }
    printf("\n");

    memset(str2, 1, 1316);
    memcpy(str2, src, strlen(src) + 1); // 需要多加一位，拷贝'\0'
//    str2[0] = '0';
//    str2[1] = '0';

    printf("sizeof str2: %lu\n", sizeof(*str2)); // 1
    printf("sizeof str2: %lu, %s\n", strlen(str2),
           str2); // 1317, 1230
    for (int i = 0; i < 1316; ++i) {
        printf("%d, ", (int) str2[i]); // 49, 50, 51, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    }
    printf("\n");
}

void testmemcopy() {
//    char *buf = malloc(2000);
//    memset(buf, 1, 2000);
//
//    int len = 2000;
//    char *toff = malloc(1317);

    char *temp = "0123456789";

    char *test = temp;
    test++;
    printf("test: %s\n", test);

    int len = 10;

    int SIZE = 5;

    char *buf = malloc(SIZE + 1);
    while (len > 0) {
        memset(buf, 0, SIZE + 1);
        memcpy(buf, temp, SIZE);
        buf[SIZE] = '\0';
        len -= SIZE;
        temp += SIZE;

        for (int i = 0; i <= SIZE; ++i) {
            printf("%c, %d --> ", buf[i], (int) buf[i]);
        }
        printf("\n");
        printf("%s", buf);
        printf("\n");
    }
    free(buf);

}

void testcmp() {
    char *str = "rtmpe";
    printf("rtmpe: %d\n",strcmp(str, "rtmpe"));
    printf("rtmpte: %d\n",strcmp(str, "rtmpte"));
}

void testStr() {
//    testatoi();
//    printLen();
//    test0();
//    testPointer();
//    testmemcopy();
    testcmp();
}