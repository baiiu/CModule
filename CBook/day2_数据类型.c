//
// Created by zhezhu on 2020/12/17.
//

#include "day2_数据类型.h"

// 整型
void testInt() {

    int i = 0x80fb0000; // 首位为符号位
    unsigned int ui = 0x80fb0000;
    short j = 32767; // 0111 1111 1111 1111
    long k = 0;

    printf("%d， %d, %d\n", sizeof(j), sizeof(i), sizeof(k));
    printf("%d, %u\n", i, ui); // 使用%u输出unsiged

    printf("%d\n", j);
    ++j;
    printf("%d", j); // 溢出

}

// 浮点型
void testFloat() {
    // float 4字节， double 8字节

    float a = 0.001; // 小数形式 1e-3
    float b = 1e3;  // 指数形式  1000

    double c = 1e-3;

    printf("%f, %f\n", a, b);
    printf("%d, %d\n", sizeof(a), sizeof(c));

    float f = 1.23456789e10; // 精度丢失
    printf("%f\n", f);

    float f1 = 1.456; // 精度丢失，浮点数存储
    if (f1 == 1.456) {
        printf("true");
    } else {
        printf("false");
    }

    printf("\n");
}

void testChar() {
    char c = 'c'; // 1字节
    printf("%c\n", c);

    printf("abc\rd\n"); // \r回到行首，只输出d

    printf("abc\b\b"); // 退格

    char a = '\0'; // 空字符，用于标示字符串结尾，不是空格，打印不出
    printf("%c", a);
}

// 字符串常量，存储在字符串常量区，C语言内存模型
void testStr() {
    char c = "a"; // 且占两个字节,\0,字符串常量的地址赋值给了对应的变量，且只赋值了一个字节
    printf("%c\n", c);

    char *p = "hello";
    printf("%c\n", p);
    printf("%s\n", p);

}

// 混合运算
void testAll() {
    int i = 5;
    float f = i / 2;
    printf("%f\n", f); // 输出2.0

    float f1 = (float) i / 2;
    printf("%f", f1);
}

void testScanf() {
    int i;
    int ret;

    double d;
    scanf("%lf", &d); // 需要lf
    printf("%f\n", d);

    char tc;
    scanf("%lf %c", &d, &tc); // 读取字符前要有一个空格
    printf("%f,%c\n", d, tc);

    // 每次输入前清空缓冲区
    while (fflush(stdin), (ret = scanf("%d", &i)) != EOF) {
        printf("i = %d\n", i);
    }

    char c;
    while ((ret = scanf("%c", &c)) != EOF) {
        printf("%c", c);
    }
}

// 运算符
void test() {

    int i = -1;
    int j;

    j = i++ > -1;
    printf("%d,%d\n", i, j);

    printf("%d\n", i >= 0);
    printf("%d\n", i > 0 );
}

void day2() {
//    testInt();
//    testFloat();
//    testChar();
//    testStr();
//    testAll();
//    testScanf();
    test();
}