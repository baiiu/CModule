//
// Created by baiiu on 2020/12/7.
//

#ifndef TESTC_TESTDEFINE_H
#define TESTC_TESTDEFINE_H

#include "common.h"

#define EIJK_INVALID_STATE      -3

#define MPST_RET_IF_EQ_INT(real, expected, errcode) \
    do { \
        if ((real) == (expected)) return (errcode); \
    } while(0)

#define MPST_RET_IF_EQ(real, expected) \
    MPST_RET_IF_EQ_INT(real, expected, EIJK_INVALID_STATE)


int testDefine();

#endif //TESTC_TESTDEFINE_H
