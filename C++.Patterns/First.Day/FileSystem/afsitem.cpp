#include "afsitem.hpp"

AFSItem::AFSItem() : mLevel(0), mName() {}

AFSItem::AFSItem(const string name) : mLevel(0), mName(name) {}

AFSItem::~AFSItem() {}

void AFSItem::add(shared_ptr<IElement>& e) {}

void AFSItem::draw() const {}

const int AFSItem::getLevel() const {
    return mLevel;
}

void AFSItem::setLevel(const int level) {
    mLevel = level;
}

const string AFSItem::getName() const {
    return mName;
}

void AFSItem::setName(const string name) {
    mName.clear();
    mName.append(name);
}