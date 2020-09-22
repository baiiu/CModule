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
}

void hello2() {

    struct Object object;
    object.str = "str222";
    strncpy(object.strArr, "test", strlen("test"));

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


Object *hello4(char *str) {
    Object *object = malloc(sizeof(Object));

    memset(object, 0, sizeof(Object));

    object->str = str;
    strncpy(object->strArr, str, strlen(str));

    return object;
}

