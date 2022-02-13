//
// Created by baiiu on 2022/2/9.
//

#ifndef TESTCPP_TESTOPERATOR_H
#define TESTCPP_TESTOPERATOR_H

#include <iostream>

using namespace std;

class complex {
public:
    complex();

    complex(double real, double imag);

    // 成员函数重载
    complex &operator+=(const complex &x);

    // 友元函数，可以访问private值
    friend complex operator+(const complex &x, const complex &y);

    inline double real() const {
        return re;
    }

    inline double imag() const {
        return im;
    }

    inline void display() const {
        cout << re << "+" << im << "i" << endl;
    }

private:
    double re;
    double im;
};

complex::complex() : re(0), im(0) {}

complex::complex(double real, double imag) : re(real), im(imag) {}

inline complex &
complex::operator+=(const complex &x) {
    this->re += x.re;
    this->im += x.im;
    return *this;
}

// 任何一种函数都可以在成员函数里还是全局函数里实现
inline double real(const complex &x) {
    return x.real();
}

inline double imag(const complex &x) {
    return x.imag();
}

// 共轭复数
inline complex conj(const complex &x) {
    return {real(x), -imag(x)};
}




/*
 * 在全局范围内重载
 *
 * 在操作符重载时考虑成员函数内重载 or 全局函数重载
 *
 * 如下加法重载，放在全局函数
 */

// 加法，两个参数
inline complex operator+(const complex &x, const complex &y) {
    //    complex result;
    //    result.re = x.re + y.re;
    //    result.im = x.im + y.im;
    //    return result;

    return {real(x) + real(y), imag(x) + imag(y)};
}

inline complex operator+(const complex &x, double y) {
    return {real(x) + y, imag(x)};
}

inline complex operator+(double x, const complex &y) {
    return {x + real(y), imag(y)};
}

// 正号
inline complex operator+(const complex &x) {
    return x;
}

// 负数
inline complex operator-(const complex &x) {
    return {-real(x), -imag(x)};
}

// 相等
inline bool operator==(const complex &x, const complex &y) {
    return real(x) == real(y) && imag(x) == imag(y);
}

// 特殊的操作符<< 只能全局函数重载
ostream &operator<<(ostream &out, const complex &x) {
    return out << x.real() << "+" << x.imag() << "i";
}

void testOperator();

#endif //TESTCPP_TESTOPERATOR_H
