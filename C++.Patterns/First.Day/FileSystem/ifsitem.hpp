#include <memory>
#include "ielement.hpp"

#ifndef _FSITEM_HPP
#define _FSITEM_HPP

using namespace std;

class IFSItem : public IElement {
  public:
    virtual const string getName() const = 0;
    virtual void setName(const string) = 0;
};

#endif