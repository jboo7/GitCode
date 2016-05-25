#include "folder.hpp"

Folder::Folder() : AFSItem::AFSItem() {}

Folder::Folder(const string name) : AFSItem::AFSItem(name) {}

Folder::~Folder() {}

void Folder::add(const shared_ptr<IElement> e) {}

void Folder::draw() const {}