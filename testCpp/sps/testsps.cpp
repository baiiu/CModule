//
// Created by baiiu on 2021/12/6.
//

#include "testsps.h"

void skipBytes(Spspps *spspps, int bytes) {
    spspps->position += bytes;
}

unsigned char readByte(Spspps *spspps) {
    return spspps->data[spspps->position++];
}

unsigned short readShort(Spspps *spspps) {
    return spspps->data[spspps->position++] << 8
           | spspps->data[spspps->position++];
}

void testSps() {
    /*
     * 0x01+sps[1]+sps[2]+sps[3]+0xFF+0xE1+sps size+sps+01+pps size+pps
     * 其中sps size和pps size各占两个字节
     */
    uint8_t data[] = {
            0x01, 0x42, 0xc0, 0x1f, 0xff, 0xe1,
            0x00, 0x1b,
            0x67, 0x42, 0xc0, 0x1f, 0xda, 0x02, 0xd0, 0x28, 0x69, 0xa8, 0x08, 0x08, 0x0a, 0x00, 0x00, 0x03, 0x00, 0x02,
            0x00, 0x00, 0x03, 0x00, 0x65, 0x1e, 0x30, 0x65, 0x40,
            0x01,
            0x00, 0x04,
            0x68, 0xce, 0x3c, 0x80
    };
    AVCodecContext avCodecContext;
    avCodecContext.extradata = data;
    avCodecContext.extradata_size = sizeof(data);

    /*
     * 解析spspps
     */
    Spspps spspps;
    spspps.spspps_size = avCodecContext.extradata_size;
    memcpy(spspps.data, avCodecContext.extradata, spspps.spspps_size);

    skipBytes(&spspps, 4);
    unsigned char byte = readByte(&spspps);

    int nalUnitLengthFieldLength = (byte & 0x3) + 1;
    printf("byte: %x, nalUnitLengthFieldLength: %d\n", byte, nalUnitLengthFieldLength);

    if (nalUnitLengthFieldLength == 3) {
        return;
    }

    byte = readByte(&spspps);
    int numSequenceParameterSets = byte & 0x1F;
    printf("byte: %x, numSequenceParameterSets: %d\n", byte, numSequenceParameterSets);
    if (numSequenceParameterSets > 1) {
        // 有两个sps/pps? 让ffmpeg本身处理吧
        return;
    }

    unsigned short spsLength = readShort(&spspps);
    printf("byte: %x, %d\n", spsLength, spsLength);

    /*
     * 找到了sps，开始解析sps
     */
    Sps sps;
    sps.sps_size = spsLength;
    memcpy(sps.data, &spspps.data[spspps.position], spsLength);
    for (int i = 0; i < spsLength; ++i) {
        printf("%0x, ", sps.data[i]);
    }

    

}