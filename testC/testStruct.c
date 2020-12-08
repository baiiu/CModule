//
// Created by baiiu on 2020/11/30.
//

#include "testStruct.h"


void testStruct() {

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