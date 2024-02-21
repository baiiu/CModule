//
// Created by ByteDance on 2024/2/20.
//

#ifndef TESTCPP_FOLDER_H
#define TESTCPP_FOLDER_H

#include <set>
#include <string>
#include "Folder.h"
#include "Message.h"

using namespace std;

class Folder {
    friend class Message;

public:
    // 显示构造函数
    explicit Folder(const std::string &str = "") : folderName(str) {}

    // 拷贝构造
    Folder(const Folder &);

    // 移动构造
    Folder(Folder &&);

    // 拷贝赋值
    Folder &operator=(const Folder &);
    // 移动赋值
    Folder &operator=(Folder &&);


    void addMessage(Message &);

    void removeMessage(Message &);

    ~Folder();

private:
    string folderName;
    set<Message *> messages; // 包含本Message的folders
};

#endif //TESTCPP_FOLDER_H
