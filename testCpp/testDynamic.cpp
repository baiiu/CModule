//
// Created by baiiu on 2021/8/17.
//

#include "testDynamic.h"

int flv_close(int a, int b) {
    return 0;
}

AVInputFormat flv = {
        .name = "flv",
        .read_close =flv_close,
};

void testDynamic() {

    AVInputFormat flv2;
    flv2.name = "a";
    flv2.read_close = flv_close;

    cout << flv.name << ", " << flv.read_close << endl;

}