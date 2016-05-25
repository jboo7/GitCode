#include "afsitem.hpp"

AFSItem::AFSItem() {}

AFSItem::AFSItem(const string name) : mName(name) {}

AFSItem::~AFSItem() {}

void AFSItem::add(shared_ptr<IElement> e) {
    return;
}

void AFSItem::draw() const {
    cout << this->getName() << endl;
}

const string AFSItem::getName() const {
    return mName;
}

void AFSItem::setName(const string name) {
    mName.clear();
    mName.append(name);
}