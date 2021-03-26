//
// Created by baiiu on 2021/3/10.
//

#ifndef TESTC_TESTCOMMON_H
#define TESTC_TESTCOMMON_H

#include "common.h"

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode2 {
    int val;
    struct ListNode2 *next;
} ListNode2;


void testCommon();

#endif //TESTC_TESTCOMMON_H
