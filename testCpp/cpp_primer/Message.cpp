//
// Created by ByteDance on 2024/2/20.
//

#include "Message.h"

void Message::save(Folder &folder) {
    folders.insert(&folder);
    folder.addMessage(this);
}

void Message::remove(Folder &folder) {
    folders.erase(&folder);
    folder.removeMessage(this);
}

void Message::add_to_folders(const Message &message) {
    for (auto &folder: message.folders) {
        folder->addMessage(this);
    }
}

void Message::remove_from_folders() {
    for (auto &folder: folders) {
        folder->removeMessage(this);
    }
}

// 拷贝构造
Message::Message(const Message &m) : contents(m.contents), folders(m.folders) {
    add_to_folders(m); // 将本消息添加到m指向的folders中
}

// 拷贝赋值
Message &Message::operator=(const Message &m) {
    remove_from_folders(); // 先清空
    contents = m.contents;
    folders = m.folders;
    add_to_folders(m); // 将本消息添加到m指向的folders中
    return *this;
}

Message::~Message() {
    // 编译器自动调用string的析构函数来释放contents，并自动调用set的析构函数来清理集合成员使用的内存。
    remove_from_folders();
}