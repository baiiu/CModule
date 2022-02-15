//
// Created by baiiu on 2022/2/15.
//

#include "hjVirtual.h"
#include "vector"
#include <iostream>

using namespace std;

struct Observer {
public:
    virtual void onNotify() = 0;
};

class Subject {
public:
    void addObserver(Observer *observer) {
        m_views.push_back(observer);
    }

    void notify() const {
        for (auto obj : m_views) {
            obj->onNotify();
        }
    }

private:
    vector<Observer *> m_views;
};


void testVirtual() {
    Subject subject;

    class MyObserver : public Observer {
        void onNotify() override {
            cout << "MyObserver onNotify" << endl;
        }
    };
    MyObserver observer;

    subject.addObserver(&observer);
    subject.notify();
}