//
// Created by ByteDance on 2024/6/4.
//

#include "more02.h"

class Widget {
public:
    // 必须要添加，dynamic_cast需要baseClass是多态的。
    // 否则error: 'Widget' is not polymorphic
    virtual ~Widget() = default;
};

class SpecialWidget : public Widget {
public:
    ~SpecialWidget() override = default;
};

void update(SpecialWidget *psw) {};

void update2(SpecialWidget &psw) {};


void testMore02() {
    SpecialWidget sw;
    const SpecialWidget &csw = sw;

    // update(&csw); // 错误，函数参数非const
    update(const_cast<SpecialWidget *>(&csw)); // 使用const_cast改变表达式中的常量性
    update((SpecialWidget *) &csw); // 旧式语法直接转换
    update2(const_cast<SpecialWidget &>(csw));
    update2((SpecialWidget &) csw); // 旧式语法直接转换

    Widget *pw = new SpecialWidget;
    // update(pw); // 错误，函数需要SpecialWidget
    update(dynamic_cast<SpecialWidget *>(pw));
    update2(dynamic_cast<SpecialWidget &>(*pw));
}
