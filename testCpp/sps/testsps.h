//
// Created by baiiu on 2021/12/6.
//

#ifndef TESTCPP_TESTSPS_H
#define TESTCPP_TESTSPS_H

#include "common.h"


typedef struct AVCodecContext {
    uint8_t *extradata;
    int extradata_size;
} AVCodecContext;

typedef struct Spspps {
    uint8_t data[4096];
    int spspps_size;
    int position;
} Spspps;

typedef struct Sps {
    uint8_t data[4096];
    int sps_size;
    int position;
} Sps;


void skipBytes(Spspps *spspps, int bytes);

unsigned char readByte(Spspps *spspps);

unsigned short readShort(Spspps *spspps);

void testSps();


#endif //TESTCPP_TESTSPS_H
