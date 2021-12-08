//
// Created by baiiu on 2021/12/7.
//

#include "spspps.h"

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


/*
 * 解析sps
 */
void parseSpspps(Spspps *spspps) {
    skipBytes(spspps, 4);
    unsigned char byte = readByte(spspps);

    int nalUnitLengthFieldLength = (byte & 0x3) + 1;
    printf("byte: %x, nalUnitLengthFieldLength: %d\n", byte, nalUnitLengthFieldLength);

    if (nalUnitLengthFieldLength == 3) {
        return;
    }

    byte = readByte(spspps);
    int numSequenceParameterSets = byte & 0x1F;
    printf("byte: %x, numSequenceParameterSets: %d\n", byte, numSequenceParameterSets);
    if (numSequenceParameterSets > 1) {
        // 有两个sps/pps? 让ffmpeg本身处理吧
        return;
    }

    unsigned short spsLength = readShort(spspps);
    printf("byte: %x, %d\n", spsLength, spsLength);

    /*
     * 找到了sps，开始解析sps
     */
    Sps sps;
    bzero(&sps, sizeof(sps));
    sps.sps_size = spsLength;
    memcpy(sps.data, &spspps->data[spspps->position], spsLength);
    for (int i = 0; i < spsLength; ++i) {
        printf("%0x, ", sps.data[i]);
    }
    printf("\n");

    parseSps(&sps);
}


bool shouldSkipByte(Sps *sps, int offset) {
    return offset >= 2
           && offset < sps->sps_size
           && sps->data[offset] == 0x03
           && sps->data[offset - 1] == 0x00
           && sps->data[offset - 2] == 0x00;
}

// Reads up to 32 bits.
unsigned int readBits(Sps *sps, int numBits) {
    unsigned int returnedValue = 0;

    sps->bitOffset += numBits;
    while (sps->bitOffset > 8) {
        sps->bitOffset -= 8;
        returnedValue |= ((sps->data[sps->byteOffset]) << sps->bitOffset);
        sps->byteOffset += shouldSkipByte(sps, sps->byteOffset + 1) ? 2 : 1;
    }

    returnedValue |= (sps->data[sps->byteOffset] >> (8 - sps->bitOffset));
    returnedValue &= (0xFFFFFFFF >> (32 - numBits));

    if (sps->bitOffset == 8) {
        sps->bitOffset = 0;
        sps->byteOffset += shouldSkipByte(sps, sps->byteOffset + 1) ? 2 : 1;
    }

    return returnedValue;
}

bool readBit(Sps *sps) {
    bool returnValue = (sps->data[sps->byteOffset] & (0x80 >> sps->bitOffset)) != 0;
    skipBit(sps);
    return returnValue;
}

void skipBit(Sps *sps) {
    if (++sps->bitOffset == 8) {
        sps->bitOffset = 0;
        sps->byteOffset += shouldSkipByte(sps, sps->byteOffset + 1) ? 2 : 1;
    }
}

unsigned int readUnsignedExpGolombCodedInt(Sps *sps) {
    return readExpGolombCodeNum(sps);
}

signed int readSignedExpGolombCodedInt(Sps *sps) {
    unsigned int codeNum = readExpGolombCodeNum(sps);
    return ((codeNum % 2) == 0 ? -1 : 1) * ((codeNum + 1) / 2);
}

int readExpGolombCodeNum(Sps *sps) {
    int leadingZeros = 0;
    while (!readBit(sps)) {
        leadingZeros++;
    }

    return (1 << leadingZeros) - 1 + (leadingZeros > 0 ? readBits(sps, leadingZeros) : 0);
}

void skipScalingList(Sps *sps, int size) {
    int lastScale = 8;
    int nextScale = 8;
    for (int i = 0; i < size; i++) {
        if (nextScale != 0) {
            int deltaScale = readSignedExpGolombCodedInt(sps);
            nextScale = (lastScale + deltaScale + 256) % 256;
        }
        lastScale = (nextScale == 0) ? lastScale : nextScale;
    }
}

void parseSps(Sps *sps) {
    unsigned int nal_unit = readBits(sps, 8);
    printf("nal_unit: %x\n", nal_unit);

    unsigned int profileIdc = readBits(sps, 8); // profileIdc: 0x42, 66
    printf("profileIdc: %x\n", profileIdc);

    unsigned int constraint_bits = readBits(sps, 8);
    printf("constraint_bits: %x\n", constraint_bits);

    unsigned int level_idc = readBits(sps, 8);
    printf("level_idc: %x\n", level_idc);

    unsigned int seqParameterSetId = readUnsignedExpGolombCodedInt(sps);
    printf("seqParameterSetId: %x\n", seqParameterSetId);

    unsigned int chromaFormatIdc = 1; // Default is 4:2:0
    bool separateColorPlaneFlag = false;

    if (profileIdc == 100 || profileIdc == 110 || profileIdc == 122 || profileIdc == 244
        || profileIdc == 44 || profileIdc == 83 || profileIdc == 86 || profileIdc == 118
        || profileIdc == 128 || profileIdc == 138) {
        chromaFormatIdc = readUnsignedExpGolombCodedInt(sps);
        if (chromaFormatIdc == 3) {
            separateColorPlaneFlag = readBit(sps);
        }
        readUnsignedExpGolombCodedInt(sps); // bit_depth_luma_minus8
        readUnsignedExpGolombCodedInt(sps); // bit_depth_chroma_minus8
        skipBit(sps); // qpprime_y_zero_transform_bypass_flag
        bool seqScalingMatrixPresentFlag = readBit(sps);
        if (seqScalingMatrixPresentFlag) {
            int limit = (chromaFormatIdc != 3) ? 8 : 12;
            for (int i = 0; i < limit; i++) {
                bool seqScalingListPresentFlag = readBit(sps);
                if (seqScalingListPresentFlag) {
                    skipScalingList(sps, i < 6 ? 16 : 64);
                }
            }
        }
    }

    unsigned int frameNumLength = readUnsignedExpGolombCodedInt(sps) + 4; // log2_max_frame_num_minus4 + 4
    unsigned int picOrderCntType = readUnsignedExpGolombCodedInt(sps);
    unsigned int picOrderCntLsbLength = 0;
    bool deltaPicOrderAlwaysZeroFlag = false;
    if (picOrderCntType == 0) {
        // log2_max_pic_order_cnt_lsb_minus4 + 4
        picOrderCntLsbLength = readUnsignedExpGolombCodedInt(sps) + 4;
    } else if (picOrderCntType == 1) {
        deltaPicOrderAlwaysZeroFlag = readBit(sps); // delta_pic_order_always_zero_flag
        readSignedExpGolombCodedInt(sps); // offset_for_non_ref_pic
        readSignedExpGolombCodedInt(sps); // offset_for_top_to_bottom_field
        long numRefFramesInPicOrderCntCycle = readUnsignedExpGolombCodedInt(sps);
        for (int i = 0; i < numRefFramesInPicOrderCntCycle; i++) {
            readUnsignedExpGolombCodedInt(sps); // offset_for_ref_frame[i]
        }
    }
    readUnsignedExpGolombCodedInt(sps); // max_num_ref_frames
    skipBit(sps); // gaps_in_frame_num_value_allowed_flag

    unsigned int picWidthInMbs = readUnsignedExpGolombCodedInt(sps) + 1;
    unsigned int picHeightInMapUnits = readUnsignedExpGolombCodedInt(sps) + 1;
    bool frameMbsOnlyFlag = readBit(sps);
    unsigned int frameHeightInMbs = (2 - (frameMbsOnlyFlag ? 1 : 0)) * picHeightInMapUnits;
    if (!frameMbsOnlyFlag) {
        skipBit(sps); // mb_adaptive_frame_field_flag
    }

    skipBit(sps); // direct_8x8_inference_flag
    unsigned int frameWidth = picWidthInMbs * 16;
    unsigned int frameHeight = frameHeightInMbs * 16;
    bool frameCroppingFlag = readBit(sps);
    if (frameCroppingFlag) {
        unsigned int frameCropLeftOffset = readUnsignedExpGolombCodedInt(sps);
        unsigned int frameCropRightOffset = readUnsignedExpGolombCodedInt(sps);
        unsigned int frameCropTopOffset = readUnsignedExpGolombCodedInt(sps);
        unsigned int frameCropBottomOffset = readUnsignedExpGolombCodedInt(sps);
        int cropUnitX;
        int cropUnitY;
        if (chromaFormatIdc == 0) {
            cropUnitX = 1;
            cropUnitY = 2 - (frameMbsOnlyFlag ? 1 : 0);
        } else {
            int subWidthC = (chromaFormatIdc == 3) ? 1 : 2;
            int subHeightC = (chromaFormatIdc == 1) ? 2 : 1;
            cropUnitX = subWidthC;
            cropUnitY = subHeightC * (2 - (frameMbsOnlyFlag ? 1 : 0));
        }
        frameWidth -= (frameCropLeftOffset + frameCropRightOffset) * cropUnitX;
        frameHeight -= (frameCropTopOffset + frameCropBottomOffset) * cropUnitY;
    }

    printf("frameWidth: %d, frameHeight: %d, frameCroppingFlag: %d\n", frameWidth, frameHeight, frameCroppingFlag);

    float pixelWidthHeightRatio = 1;
    bool vuiParametersPresentFlag = readBit(sps);
    printf("pixelWidthHeightRatio: %f, vuiParametersPresentFlag: %d\n", pixelWidthHeightRatio,
           vuiParametersPresentFlag);

    if (vuiParametersPresentFlag) {
        bool aspectRatioInfoPresentFlag = readBit(sps);
        if (aspectRatioInfoPresentFlag) {
            unsigned int aspectRatioIdc = readBits(sps, 8);
            if (aspectRatioIdc == EXTENDED_SAR) {
                unsigned int sarWidth = readBits(sps, 16);
                unsigned int sarHeight = readBits(sps, 16);
                if (sarWidth != 0 && sarHeight != 0) {
                    pixelWidthHeightRatio = (float) sarWidth / sarHeight;
                }
            } else if (aspectRatioIdc < 17) {
                pixelWidthHeightRatio = ASPECT_RATIO_IDC_VALUES[aspectRatioIdc];
            } else {
                printf("Unexpected aspect_ratio_idc value: " + aspectRatioIdc);
            }
        }
    }

}