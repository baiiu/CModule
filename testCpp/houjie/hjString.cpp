//
// Created by baiiu on 2022/2/13.
//

#include "hjString.h"
#include "../common.h"

void testString() {
    String s1;
    String s2("hello");

    String s3(s2);
    cout << s3 << endl;

    s1 = s3;
    cout << s1 << endl;
}