#ifndef _IELEMENT_HPP
#define _IELEMENT_HPP

#include <memory>

using namespace std;

class IElement {
public:
    void add(const shared_ptr<IElement>);
    void draw() const;
};

#endif