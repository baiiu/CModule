//
// Created by baiiu on 2020/11/30.
//

#include "testStruct.h"

/*
 * 结构体嵌套，sizeof看看
 * 全都分配上了，如果是指针，则分配一个指针长度，需要重新分配指针所指向的对象
 */
void testStructSizeof() {

    struct A *a = malloc(sizeof(A));
    struct B *b = malloc(sizeof(B));
    struct C *c = malloc(sizeof(C));

    printf("%d, sizeofa\n", sizeof(*a));
    printf("%d, sizeofb\n", sizeof(*b));
    printf("%d, sizeofc\n", sizeof(*c));


    if (a) {
        printf("11111111\n");
    }

    int num;
    printf("%d, sizeofNum\n", sizeof(num));
    int *p;
    printf("%d, sizeofP\n", sizeof(p));


    printf("==========================\n");


    struct CC cc;
    struct BB bb;
    struct AA aa;
    printf("%d, sizeofAA\n", sizeof(cc));
    printf("%d, sizeofAA\n", sizeof(bb));
    printf("%d, sizeofAA\n", sizeof(aa));

    if (aa.cc) {
        printf("22222222");
    }

    printf("==========================\n");

    struct AA *aaa = malloc(sizeof(AA));
    printf("%d, sizeofaaa\n", sizeof(*aaa));
    if (aaa->cc) {
        printf("33333333");
    }


}

/*
 * 把一指针变量赋值给另一个指针变量 *a = *b;
 * 有点类似 memcpy过去，地址不变，内容全变了
 */
void testStructAssign() {
    struct C *c1 = malloc(sizeof(C));
    c1->c = 1;
    printf("c1: %d\n", c1->c);

    struct C *c2 = malloc(sizeof(C));
    c2->c = 2;
    printf("c2: %d\n", c2->c);

    printf("c1: %p, c2: %p\n", c1, c2);

    *c1 = *c2;
    printf("===c1: %d\n", c1->c);
    printf("===c1: %p, c2: %p\n", c1, c2);

    c1 = c2;
    printf("=====c1: %d\n", c1->c);
    printf("=====c1: %p, c2: %p\n", c1, c2);
}

void testStructAssign2() {
    struct B *b1 = malloc(sizeof(B));
    b1->c.c = 1;
    printf("b1: %d\n", b1->c.c);

    struct B *b2 = malloc(sizeof(B));
    b2->c.c = 2;
    printf("b2: %d\n", b2->c.c);

    printf("b1: %p, b2: %p\n", b1, b2);

    // 两个指针变量赋值，感觉像是memcpy过去了，地址并没有变化，内容变化了
    *b1 = *b2;
    printf("===b1: %d\n", b1->c.c);
    printf("===b1: %p, b2: %p\n", b1, b2);

    b1 = b2;
    printf("=====b1: %d\n", b1->c.c);
    printf("=====b1: %p, b2: %p\n", b1, b2);
}

void testStructAssign3() {
    struct AA *b1 = malloc(sizeof(AA));
    b1->aa = 1;
    b1->cc = malloc(sizeof(CC));
    b1->cc->cc = 1;
    printf("b1: %d, %d\n", b1->cc->cc, b1->aa);

    struct AA *b2 = malloc(sizeof(AA));
    b2->aa = 2;
    b2->cc = malloc(sizeof(CC));
    b2->cc->cc = 2;
    printf("b2: %d, %d\n", b2->cc->cc, b2->aa);

    printf("b1: %p, b2: %p\n", b1, b2);

    // 两个指针变量赋值，感觉像是memcpy过去了，地址并没有变化，内容变化了
    *b1 = *b2;
    printf("===b1: %d,  %d\n", b1->cc->cc, b1->aa);
    printf("===b1: %p, b2: %p\n", b1, b2);

    b1 = b2;
    printf("=====b1: %d, %d\n", b1->cc->cc, b1->aa);
    printf("=====b1: %p, b2: %p\n", b1, b2);
}


void testStruct() {
//    testStructSizeof();

//    testStructAssign();
//    testStructAssign2();
    testStructAssign3();
}