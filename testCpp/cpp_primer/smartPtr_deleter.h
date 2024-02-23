//
// Created by ByteDance on 2024/2/23.
//

#ifndef TESTCPP_SMARTPTR_DELETER_H
#define TESTCPP_SMARTPTR_DELETER_H

#include <string>
#include <utility>
#include <iostream>

using namespace std;

class Connection {
public:
    explicit Connection(string name) : _name(std::move(name)) {
    }

    ~Connection() {
        cout << _name << "~析构函数" << endl;
    }

    string get_name() const {
        return _name;
    }

private:
    string _name;
};

inline void close(Connection *connection) {
    cout << string("关闭") + connection->get_name() + "管理的连接中..." << endl;
}

void testDeleter();


#endif //TESTCPP_SMARTPTR_DELETER_H
