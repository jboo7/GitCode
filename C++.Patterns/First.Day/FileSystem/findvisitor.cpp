#include "findvisitor.hpp"

FindVisitor::FindVisitor(const string name) : mFoundNames(), mFoundTypes(), mName(name) {}
FindVisitor::~FindVisitor() {}

void FindVisitor::visit(const IItem& item) {
    if (!mName.compare(item.name())) {
        mFoundNames.push_back(item.name());
        mFoundTypes.push_back(item.type());
    }
}

void FindVisitor::show() const {
    for (int i = 0; i < mFoundNames.size(); i++) {
        cout << mFoundNames[i] << " : " << mFoundTypes[i] << endl;
    }
}