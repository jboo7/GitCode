#include <iostream>
#include <memory>
#include "ifsitem.hpp"

#ifndef _AFSITEM_HPP
#define _AFSITEM_HPP

using namespace std;

class AFSItem : public IFSItem {
  public:
    AFSItem();
    AFSItem(const string);
    virtual ~AFSItem();

    virtual void add(shared_ptr<IElement>&);
    virtual void draw() const;

    virtual const int getLevel() const;
    virtual void setLevel(const int);

    virtual const string getName() const;
    virtual void setName(const string);

  private:
    int mLevel;
    string mName;
};

#endif