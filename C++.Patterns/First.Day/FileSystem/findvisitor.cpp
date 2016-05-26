#include "findvisitor.hpp"

FindVisitor::FindVisitor(const string name) : mFoundNames(), mFoundTypes(), mName(name) {}
FindVisitor::~FindVisitor() {}

void FindVisitor::visit(const IItem& item) {
    
}