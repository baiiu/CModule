//
// Created by baiiu on 2021/5/12.
//

#include "testVoid*.h"


void testVoid() {
    void *obj;

    int a = 1;
    int *pa = &a;
    printf("%lu, %lu, %lu, %lu\n", sizeof(int), sizeof(&a), sizeof(pa), sizeof(int *));
    obj = pa;
    int aObj = *((int *) obj);
    printf("%d\n", aObj);

    long b = 1;
    long *pb = &b; // 指向b的指针，指针类型为long，但该真正还是一个int *指针，解引用的时候类型要对上才行
    printf("%lu, %lu, %lu, %lu\n", sizeof(long), sizeof(&b), sizeof(pb), sizeof(long *));
    obj = pb;
    int bObj = *((int *) obj);
    printf("%d\n", bObj);

    char *s = "char123";
    AVAppHttpEvent event = {0};
    event.obj = s;
    char *s_ = event.obj;
    printf("%p, %s\n", event.obj, s_);


    int64_t time = 123;
//    int64_t *pTime = &time;
    event.obj = &time;
    int64_t timeObj = *((int *) event.obj);
    printf("%p, %lld\n", event.obj, timeObj);

}