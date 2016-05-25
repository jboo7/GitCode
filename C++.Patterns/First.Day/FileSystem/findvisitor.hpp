#include "ifsvisitor.hpp"

#ifndef _FINDVISITOR_HPP
#define _FINDVISITOR_HPP

class FindVisitor : public IFSVisitor {
public:
    virtual void visit(const shared_ptr<IFSItem>);
}

#endif