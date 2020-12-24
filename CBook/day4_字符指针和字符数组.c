//
// Created by baiiu on 2020/12/23.
//

#include "day4_字符指针和字符数组.h"


// 字符指针和字符数组
void day4_testCharPointerArr() {
    char *p = "hello"; // 字符串常量池地址赋值给p，即p指向了字符串常量池的hello
    char *p1 = "hello";
    char c[10] = "hello"; // 是把字符串常量池里的hello strcpy给了c

    printf("%p, %p, %p\n", p, p1, c); // p和p1指向同一个地方
    printf("%d, %d, %d, %d\n", (p == p1), (*p == *p1), (c == p), (*c == *p));
    printf("%c, %c\n", *c, *p);

    c[0] = 'H'; // 可以赋值，在栈空间上
//    p[0] = 'H'; // 会崩溃，在常量池里，不可写
    puts(c);

    char *p2 = malloc(10 * sizeof(char));
    strcpy(p2, "hello");
    p2[0] = 'H';
    puts(p2); // 可以修改，在堆上分配

    printf("===");

    char *p3 = malloc(10 * sizeof(char));
    p3 = "hello"; // 把常量池hello地址赋给p3，造成内存泄露，刚才在堆上分配的10个空间大小没法释放
//    p3[0] = 'H'; // 不能修改，因为是常量池的
    puts(p3); // 可以修改，在堆上分配

    p = "world";
    strcpy(c, "world"); // 重新给c赋值
    puts(p);
    puts(c);
}