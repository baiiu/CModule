//
// Created by zhezhu on 2021/8/5.
//

#include "teststring.h"

void testString1(string &s) {

}

void testString2(const string &s) {

}

void teststring() {

//    testString1("11");
    testString2("11");

//    testString1(string("11"));
    testString2(string("11"));

    string s = string("11");
    testString1(s);
    testString2(s);

    s = "11";
    testString1(s);
    testString2(s);

}