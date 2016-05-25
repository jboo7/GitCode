#include <memory>
#include "ielement.hpp"

#ifndef _IFSVISITOR_HPP
#define _IFSVISITOR_HPP

class IFSVisitor { 
public: 
    virtual void visit(const shared_ptr<IFSItem>) = 0;
};

#endif