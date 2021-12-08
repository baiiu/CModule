//
// Created by zhezhu on 2021/8/5.
//

#include "teststring.h"

void testString1(string &s) {

}

void testString2(const string &s) {

}

void testParams() {
//    testString1("11");
    testString2("11");

//    testString1(string("11"));
    testString2(string("11"));

    string s = string("11");
    testString1(s);
    testString2(s);

    s = "11";
    testString1(s);
    testString2(s);
}


void testEqual() {
    string s1 = "123";
    string s2 = "123";
    auto *s3 = new string("123");

    // 是
    printf("%p, %p， %p\n", &s1, &s2, s3); // 不同
    printf("是否相等: %d\n", (s1 == s2)); // true
    printf("是否相等: %d\n", (s1 == *s3));// true

    delete s3;
}

const string &testLocal() {
    return "123";
}

void testintarr() {
    int len = 8;
    uint8_t arr[] = {0, 1, 2, 3, 4, 5, 6, 7};
    uint8_t *data = arr;

    for (int i = 0; i < len; ++i) {
        printf("%d, ", data[i]);
    }

    printf("\n");

    char temp[len + 1];
    for (int i = 0; i < len; ++i) {
        temp[i] = '0' + data[i];
    }
    temp[len] = '\0';

    for (int i = 0; i < len + 1; ++i) {
        printf("%d, ", temp[i]);
    }
    printf("\n");

    printf("%s", temp);

}

void teststring() {
//    testParams();
//    testEqual();
//    testLocal();
    testintarr();
}