#include <iomanip>
#include "folder.hpp"

Folder::Folder() : AItem::AItem(FOLDERTYPE) {}
Folder::Folder(const string name) : AItem::AItem(FOLDERTYPE, name) {}
Folder::~Folder() {}

void Folder::accept(IVisitor& visitor) const {
    visitor.visit(*this);
    for (vector<shared_ptr<ITreeElement>>::const_iterator it =
             mChildren.begin();
         it != mChildren.end(); it++) {
        (*it)->accept(visitor);
    }
}

void Folder::add(const shared_ptr<ITreeElement> element) {
    mChildren.push_back(element);
    element->level(this->level() + 1);
}

void Folder::draw() const {
    cout << setw(2 * this->level() + this->name().length()) << this->name()
         << " - DIR" << endl;
    for (vector<shared_ptr<ITreeElement>>::const_iterator it =
             mChildren.begin();
         it != mChildren.end(); it++) {
        (*it)->draw();
    }
}