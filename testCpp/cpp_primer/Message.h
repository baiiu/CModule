//
// Created by ByteDance on 2024/2/20.
//

#ifndef TESTCPP_MESSAGE_H
#define TESTCPP_MESSAGE_H

#include <set>
#include <string>
#include "Folder.h"

using namespace std;

class Message {
    friend class Folder;

public:
    // 显示初始化
    explicit Message(const std::string &str = "") : contents(str) {};

    // 拷贝构造函数
    Message(const Message &);

    // 移动构造
    Message(Message &&);

    // 拷贝赋值
    Message &operator=(const Message &);

    // 移动赋值
    Message &operator=(Message &&);

    ~Message();

    // 从给定Folder添加/删除本Message
    void save(Folder &);

    void remove(Folder &);

private:
    string contents; // 实际的消息文本
    set<Folder *> folders; // 包含本Message的folders

    void add_to_folders(const Message &); //将本Message添加到参数m指定的Folders

    void remove_from_folders(); // 从folders中移除本Message

    void move_folders(Message *);
};

#endif //TESTCPP_MESSAGE_H
