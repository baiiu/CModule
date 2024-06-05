//
// Created by ByteDance on 2024/6/5.
//

#include "testLambda.h"

using Task = std::function<void()>;

class Test {
public:
    int a = 1;

    // this, 函数体内可以使用Lambda所在类中的成员变量。
    void fun05(const std::vector<string> &vec) {
        Task task = [this, vec]() {
            ++a;
            cout << a << ", vec: " << &vec << endl; // 2, vec: 0x600001b74280
        };
        task();
    }
};


void fun04() {
    // 引用变量
    string i = "a";
    string &ri = i;
    auto fun = [&ri]() mutable {
        ri.append("b");
    };
    fun();
    cout << ri << endl; // ab

    // 调用类lambda
    vector<string> vector;
    vector.emplace_back("aaa");
    Test test;
    test.fun05(vector);
    cout << "vector: " << &vector << endl; // vector: 0x16d167130
}

// 隐式捕获
void fun03() {
    int a = 1, b = 2;
    std::string sa = "1", sb = "2";

    // Cannot assign to a variable captured by copy in a non-mutable lambda
    // 对于一个值被拷贝的变量，lambda不会改变其值。如果我们希望能改变一个被捕获的变量的值，就必须在参数列表首加上关键字mutable。
    auto fun = [a, &b, sa, &sb]() mutable {
        a = 3;
        b = 3;
        sa = "3";
        sb = "3";
    };
    fun();
    cout << a << ", " << b << ", " << sa << ", " << sb << endl; // 1, 3, 1, 3

    // 隐式捕获，同fun，a和sa拷贝，b和sb引用
    auto fun1 = [=, &b, &sb]()mutable {
        a = 4;
        b = 4;
        sa = "4";
        sb = "4";
    };
    fun1();
    cout << a << ", " << b << ", " << sa << ", " << sb << endl; // 1, 4, 1, 4
}

void fun02() {
    // 值捕获
    int i = 100;
    auto fun1 = [i]() {
        // 必须要捕获sz进来，否则报错
        return i + 1;
    };
    // 引用捕获
    auto fun2 = [&i]() {
        // 必须要捕获sz进来，否则报错
        return i + 1;
    };
    i = 0;
    int j1 = fun1();
    int j2 = fun2();
    cout << i << ", " << j1 << ", " << j2 << endl;  // 0, 101, 1
}

// 空捕获列表表明此lambda不使用它所在函数中的任何局部变量。
void fun01() {
    auto fun = []() { return 42; };
    int ret = fun(); // 直接返回右值赋值给ret
    cout << ret << endl; // 42

    // 返回值为string
    auto fun1 = [](const string &a, const string &b) {
        return a + "" + b;
    };
    // 返回值为bool
    auto fun2 = [](const string &a, const string &b) {
        return a.size() < b.size();
    };
    // 指定返回值
    auto fun3 = [](const string &a, const string &b) -> int {
        return a.size() - b.size();
    };
    cout << fun1("a", "bc") << endl; // abc
    cout << fun2("a", "bc") << endl; // 1
    cout << fun3("a", "bc") << endl; // -1
}

void testLambda() {
//    fun01();
//    fun02();
//    fun03();
    fun04();
}