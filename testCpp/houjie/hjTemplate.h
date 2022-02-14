//
// Created by zhezhu on 2022/2/14.
//

#ifndef TESTCPP_HJTEMPLATE_H
#define TESTCPP_HJTEMPLATE_H

template<typename T>
class complex {
public:
    complex(T r, T i) : re(r), im(i) {
    }

    T real() const { return re; }

    T imag() const { return im; }

private:
    T re, im;
};

template<typename T>
inline const T &min(const T &a, const T &b) {
    return a < b ? a : b;
}

void testTemplate();

#endif //TESTCPP_HJTEMPLATE_H
