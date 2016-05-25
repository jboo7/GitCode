#include "folder.hpp"

Folder::Folder() : AFSItem::AFSItem(), mChildren() {}

Folder::Folder(const string name) : AFSItem::AFSItem(name), mChildren() {}

Folder::~Folder() {}

void Folder::add(shared_ptr<IElement>& e) {
    mChildren.push_back(e);
    e->setLevel(this->getLevel() + 1);
}

void Folder::draw() const {
    for (int i = 0; i < this->getLevel(); i++) {
        cout << "  ";
    }
    cout << this->getName() << " DIR" << endl;
    for (vector<shared_ptr<IElement>>::const_iterator it = mChildren.begin();
         it != mChildren.end(); it++) {
        (*it)->draw();
    }
}