//
// Created by baiiu on 2022/2/7.
//

#include "testReference.h"


void test01() {

    int a = 1;
    int &ra = a; // 引用必须要初始化
//    int &ra2 = 1; // 错误，引用只能绑定在对象上，而不能与字面值或某个表达式的计算结果绑定在一起
//    int &&rra = a; // 错误，不能将一个右值引用绑定到左值上
//    int &ra3 = a * 42; // 错误，引用只能绑定在对象上，而不能与字面值或某个表达式的计算结果绑定在一起，a * 42是一个右值
    const int &ra3 = a * 42; // 正确，可以将一个const引用绑定到一个右值上
    int &&rra2 = a * 42; // 正确，将rra2绑定到一个右值上
//    int &&rrra = rra2; // 错误，表达式rra2是左值，变量是左值
    int &&rrra = std::move(rra2); // 正确，使用std::move将左值显式的变为右值

    int c = 2;
    ra = c; // 赋值操作，把c赋值给b，即赋值给a
    // &ra = c; // 错误，引用在初始化后，不可以改变

// Non-const lvalue reference to type 'int' cannot bind to a temporary of type 'int'
    const int e = 10;
// int &re = e; // 错误，引用类型的初始值必须是一个对象
    const int &re = e;
//    int &re1 = e * 42; // 错误，引用只能绑定在对象上，而不能与字面值或某个表达式的计算结果绑定在一起，a * 42是一个右值
    const int &re1 = e * 42; // 正确，可以将一个const引用绑定到一个右值上

    double d = 10.0F;
// Non-const lvalue reference to type 'int' cannot bind to a value of unrelated type 'double'
// int &rd = d; // 错误，引用类型必须和绑定的对象的类型一致，添加const后可以
    double &rd = d;
    const int &rd1 = d; // 正确，Clang-Tidy: Narrowing conversion from 'double' to 'int'


}


void testReference() {
    test01();
}