//
// Created by ByteDance on 2024/2/23.
//

#include "smartPtr_deleter.h"

void Deleter(Connection *connection) {
    close(connection);
    delete connection;
}

void testDeleter() {
    {
        // 直接使用智能指针无法调用close函数
        shared_ptr<Connection> pts = make_shared<Connection>("111");
        unique_ptr<Connection> ptu(new Connection("222"));
    }
    // 222~析构函数
    // 111~析构函数

    {
        shared_ptr<Connection> sp(new Connection("shared_ptr"), Deleter);
        unique_ptr<Connection, decltype(Deleter) *> up(new Connection("unique_ptr"), Deleter);
    }
//    关闭unique_ptr管理的连接中...
//    unique_ptr~析构函数
//    关闭shared_ptr管理的连接中...
//    shared_ptr~析构函数

    auto DeleterLambda = [](Connection *connection) {
        close(connection);
        delete connection;
    };

    shared_ptr<Connection> sp2(new Connection("shared_ptr"), DeleterLambda);
    unique_ptr<Connection, decltype(DeleterLambda)> up2(new Connection("unique_ptr"), DeleterLambda);
//    关闭unique_ptr管理的连接中...
//    unique_ptr~析构函数
//    关闭shared_ptr管理的连接中...
//    shared_ptr~析构函数

}