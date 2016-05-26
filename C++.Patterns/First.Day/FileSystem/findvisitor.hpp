#ifndef _FINDVISITOR_HPP
#define _FINDVISITOR_HPP

#include <vector>
#include <memory>
#include "ivisitor.hpp"
#include "itemtype.hpp"

using namespace std;

class IVisitor;

class FindVisitor : public IVisitor {
public:
    FindVisitor(const string);
    virtual ~FindVisitor();

public:
    virtual void visit(const IItem&);
    void show() const;

private:
    vector<string> mFoundNames;
    vector<ItemType> mFoundTypes;
    string mName;
};

#endif