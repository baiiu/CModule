//
// Created by baiiu on 2021/8/17.
//

#ifndef TESTCPP_TESTDYNAMIC_H
#define TESTCPP_TESTDYNAMIC_H

#include "common.h"

typedef struct AVInputFormat {
    const char *name;

    int (*read_close)(int a, int b);
} AVInputFormat;


void testDynamic();

#endif //TESTCPP_TESTDYNAMIC_H
