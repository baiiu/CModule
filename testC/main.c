#include <stdio.h>
#include "hello.h"

int main() {


//    hello();
//
//    printf("\n==============\n");
//
//    hello2();
//
//    printf("\n==============\n");


    struct Object object3 = hello3("test");
    passObject(&object3);
    printObject(object3);
    printf("\n==============\n");

    struct Object *object31 = hello31("test");
    passObject(object31);
    printObject(*object31);
    printf("\n==============\n");

    struct Object *object4 = hello4("test");
    passObject(object4);
    passObject(object4);
    free(object4);
    printf("\n==============\n");

    return 0;
}
