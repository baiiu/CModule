//
// Created by ByteDance on 2024/2/20.
//

#include "Folder.h"

void Folder::addMessage(Message &m) {
    messages.insert(&m);
}

void Folder::removeMessage(Message &m) {
    messages.erase(&m);
}

Folder::Folder(const Folder &f) : folderName(f.folderName), messages(f.messages) {

}

Folder::Folder(Folder &&f) : folderName(f.folderName), messages(f.messages) {
    f.messages.clear();
    f.folderName = nullptr;
}

Folder &Folder::operator=(const Folder &f) {
    folderName = f.folderName;
    messages = f.messages;
}

Folder &Folder::operator=(Folder &&f) {
    if (this == &f) {
        return *this;
    }

    folderName = f.folderName;
    messages = std::move(f.messages);
    f.folderName = nullptr;
    f.messages.clear();
    return *this;
}


Folder::~Folder() {

}