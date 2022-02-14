//
// Created by zhezhu on 2022/2/14.
//

#include "hjStaic.h"

double Account::m_rate = 0.0;
A Account::a;

void hjStatic() {
    Account::set_rate(5.0);
    cout << Account::m_rate << endl;

    cout << Account::a.a << endl;

//    A::getInstance().setup();
}