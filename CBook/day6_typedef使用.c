//
// Created by baiiu on 2020/12/28.
//

#include "day6_typedef使用.h"

typedef struct {
    int num;
    char name[20];
    char sex;
} stu, *p_stu;

void day6_testtypedef() {
    stu s = {1, "HH", 'M'};
    p_stu p = &s;

    printf("%d, %s, %c", p->num, p->name, p->sex);

}