//
// Created by baiiu on 2021/12/7.
//

#ifndef TESTCPP_SPSPPS_H
#define TESTCPP_SPSPPS_H

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

    // The byte offset is never equal to the offset of the 3rd byte in a subsequence [0, 0, 3].
    int byteOffset;
    int bitOffset;
} Sps;

/*
 * parseSpspps
 */

void skipBytes(Spspps *spspps, int bytes);

unsigned char readByte(Spspps *spspps);

unsigned short readShort(Spspps *spspps);

void parseSpspps(Spspps *context);


/*
 * parseSps
 */
const int EXTENDED_SAR = 0xFF;

const float ASPECT_RATIO_IDC_VALUES[17] = {
        1.0f /* Unspecified. Assume square */,
        1.0f,
        12.0f / 11.0f,
        10.0f / 11.0f,
        16.0f / 11.0f,
        40.0f / 33.0f,
        24.0f / 11.0f,
        20.0f / 11.0f,
        32.0f / 11.0f,
        80.0f / 33.0f,
        18.0f / 11.0f,
        15.0f / 11.0f,
        64.0f / 33.0f,
        160.0f / 99.0f,
        4.0f / 3.0f,
        3.0f / 2.0f,
        2.0f
};

unsigned int readBits(Sps *sps, int numBits);

bool readBit(Sps *sps);

void skipBit(Sps *sps);

unsigned int readUnsignedExpGolombCodedInt(Sps *sps);

signed int readSignedExpGolombCodedInt(Sps *sps);

int readExpGolombCodeNum(Sps *sps);

bool shouldSkipByte(Sps *sps, int offset);

void parseSps(Sps *sps);


#endif //TESTCPP_SPSPPS_H
