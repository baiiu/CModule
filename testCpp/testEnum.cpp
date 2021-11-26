//
// Created by baiiu on 2021/11/15.
//

#include "testEnum.h"
#include "common.h"

enum RACE_RESULT {
    ONE = 2,
    TWO = 3,
    THREE = 33,
    MAX,
};


class A {
public:
    int a;

    A(int a) {
        this->a = a;
    }
};

void passValue(int a) {
    cout << a << endl;
}

void testEnum() {
    RACE_RESULT a = ONE;
    int aa = a;
    cout << a << endl;
    cout << aa << endl;

    passValue(a);
    passValue(THREE);

    A aaa(3);
    A bbb(RACE_RESULT::THREE);

}