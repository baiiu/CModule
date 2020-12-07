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


}