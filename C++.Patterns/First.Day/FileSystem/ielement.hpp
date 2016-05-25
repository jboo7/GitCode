#include <memory>

using namespace std;

#ifndef _IELEMENT_HPP
#define _IELEMENT_HPP

class IElement {
  public:
    virtual void add(shared_ptr<IElement>&) = 0;
    virtual void draw() const = 0;

    virtual const int getLevel() const = 0;
    virtual void setLevel(const int) = 0;
};

#endif