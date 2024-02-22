//
// Created by ByteDance on 2024/2/20.
//

#include "Message.h"

void Message::save(Folder &folder) {
    folders.insert(&folder);
    folder.addMessage(*this);
}

void Message::remove(Folder &folder) {
    folders.erase(&folder);
    folder.removeMessage(*this);
}

void Message::add_to_folders(const Message &message) {
    for (auto &folder: message.folders) {
        folder->addMessage(*this);
    }
}

void Message::remove_from_folders() {
    for (auto &folder: folders) {
        folder->removeMessage(*this);
    }
}

void Message::move_folders(Message *m) {
    folders = std::move(m->folders); // set的移动赋值，而非拷贝
    for (auto &f: folders) {
        f->removeMessage(*m);
        f->addMessage(*this);
    }
    m->folders.clear();
}

// 拷贝构造
Message::Message(const Message &m) : contents(m.contents), folders(m.folders) {
    add_to_folders(m); // 将本消息添加到m指向的folders中
}

// 移动构造
Message::Message(Message &&m) : contents(m.contents), folders(m.folders) {
    move_folders(&m);
}

// 拷贝赋值
Message &Message::operator=(const Message &m) {
    remove_from_folders(); // 先清空
    contents = m.contents;
    folders = m.folders;
    add_to_folders(m); // 将本消息添加到m指向的folders中
    return *this;
}

// 移动赋值
Message &Message::operator=(Message &&m) {
    if (this == &m) {
        return *this;
    }

    remove_from_folders();
    contents = std::move(m.contents); // string的移动赋值
    move_folders(&m);
}

Message::~Message() {
    // 编译器自动调用string的析构函数来释放contents，并自动调用set的析构函数来清理集合成员使用的内存。
    remove_from_folders();
}