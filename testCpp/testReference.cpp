//
// Created by baiiu on 2022/2/7.
//

#include "testReference.h"


void test01() {

    int a = 1;
    int &ra = a; // 引用必须要初始化

    int c = 2;
    ra = c; // 赋值操作，把c赋值给b，即赋值给a
// &rb = c; 引用在初始化后，不可以改变

// Non-const lvalue reference to type 'int' cannot bind to a temporary of type 'int'
    const int e = 10;
// int &re = e; // 引用类型的初始值必须是一个对象
    const int &re = e;

    double d = 10.0F;
// Non-const lvalue reference to type 'int' cannot bind to a value of unrelated type 'double'
// int &rd = d; // 引用类型必须和绑定的对象的类型一致，添加const后可以
    double &rd = d;
    const int &rd1 = d; // 正确，Clang-Tidy: Narrowing conversion from 'double' to 'int'


}


void testReference() {
    test01();
}