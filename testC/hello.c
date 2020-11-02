//
// Created by baiiu on 2020/9/18.
//

#include "hello.h"


void passObject(Object *obj) {
    printf("%s,%s\n", obj->str, obj->strArr);
    obj->str = "123";
}

void printObject(Object obj) {
    printf("%s,%s\n", obj.str, obj.strArr);
    obj.str = "123";
}

void hello() {
    Object *object = malloc(sizeof(Object));

    memset(object, 0, sizeof(Object));

    object->str = "str";

    passObject(object);
    passObject(object);
}

void hello2() {
    struct Object object;
    object.str = "str222";
    strncpy(object.strArr, "test", strlen("test"));

    passObject(&object);
    passObject(&object);
}

Object hello3(char *str) {
    struct Object object;
    object.str = str;
    strcpy(object.strArr, "test");
    return object;
}

// 野指针
Object *hello31(char *str) {
    struct Object object; // 栈上分配内存
    object.str = str;
    strcpy(object.strArr, "test");
    return &object;
}

// 堆上分配内存
Object *hello4(char *str) {
    Object *object = malloc(sizeof(Object));

    memset(object, 0, sizeof(Object));

    object->str = str;
    strncpy(object->strArr, str, strlen(str));

    return object;
}


void testHello() {

//    hello();
//    printf("\n==============\n");
//    hello2();
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

}

