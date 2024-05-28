//
// Created by ByteDance on 2024/4/2.
//

#include "testVirtualPtr.h"

class A {
    int a{};
};

class B {
    int a{};

    virtual ~B() = default;
};

void testVirtualSize() {
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
}