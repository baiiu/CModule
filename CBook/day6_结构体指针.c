//
// Created by baiiu on 2020/12/27.
//

#include "day6_结构体指针.h"

struct student {
    int num;
    char name[20];
    char sex;
};

void day6_testStructPointer() {
    struct student s = {1001, "HH", 'M'};
    struct student sarr[3] = {1001, "HH", 'M', 1010, "LL", 'M', 1100, "MM", 'M'};

    struct student *p = &s;
//    p = &s;
    printf("%d, %s, %c\n", p->num, p->name, p->sex);
    printf("%d, %s, %c\n", (*p).num, (*p).name, (*p).sex);
    printf("%d, %s, %c\n", s.num, s.name, s.sex);

    int num;
    p = sarr;
    num = p->num++;
    printf("%d\n", num);
    printf("%d, %s, %c\n", p->num, p->name, p->sex);

    num = p++->num;
    printf("%d\n", num);
    printf("%d, %s, %c\n", p->num, p->name, p->sex);


    num = ++p->num;
    printf("%d\n", num);
    printf("%d, %s, %c\n", p->num, p->name, p->sex);

}