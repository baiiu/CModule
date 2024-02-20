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

Folder &Folder::operator=(const Folder &f) {
    folderName = f.folderName;
    messages = f.messages;
}


Folder::~Folder() {

}