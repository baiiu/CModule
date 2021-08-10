//
// Created by zhezhu on 2021/8/5.
//

#include "testStatic.h"

class Solution {
private:
    static int sInt; // 必须在类外初始化
    int ctrGlobal; // 调用结束后，这个值依然有效

    int count_calls() {
        static int ctr; // 调用结束后，这个值依然有效
        cout << ctr << endl;
        ++ctrGlobal;
        return ++ctr;
    }

public:

    void threeSum() {
        for (int i = 0; i < 10; ++i) {
            count_calls();
        }

        cout << "ctrGlobal: " << ctrGlobal << endl;
    }
};

int Solution::sInt = 0;

void testStatic() {
    Solution().threeSum();
}