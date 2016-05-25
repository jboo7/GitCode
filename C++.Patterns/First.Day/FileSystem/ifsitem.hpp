#ifndef _FSITEM_HPP
#define _FSITEM_HPP

#include <iostream>
#include <memory>

#include "ielement.hpp"

using namespace std;

class IFSItem : public IElement {
public:
    const string getName() const;
    void setName(const string);
};

#endif