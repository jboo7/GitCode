#ifndef _AFSITEM_HPP
#define _AFSITEM_HPP

#include "ifsitem.hpp"

using namespace std;

class AFSItem : public IFSItem {
  public:
    AFSItem();
    AFSItem(const string);

    virtual ~AFSItem();

    void add(const shared_ptr<IElement>);
    void draw() const;

    const string getName() const;
    void setName(const string);

  private:
    string mName;
};

#endif