//
// Created by ByteDance on 2025/8/7.
//

#include "testLambda.h"

class MyListener {
private:
    std::function<void(bool)> callback;

public:
    void setCallBack(std::function<void(bool)> cb) {
        this->callback = cb;
    }

    void onCallback(bool success) {
        if (callback) {
            callback(success);
        }
    }
};


void testFunction() {
    MyListener myListener;

    {
        myListener.setCallBack([&](bool success) {
            return false;
        });
    }

    myListener.onCallback(true);

}