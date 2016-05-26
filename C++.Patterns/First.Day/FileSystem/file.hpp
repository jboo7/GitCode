#ifndef _FILE_HPP
#define _FILE_HPP

#include "aitem.hpp"

class File : public AItem {
  public:
    File();
    File(const string);
    virtual ~File();

  public:
    virtual void accept(IVisitor&) const;

    virtual void draw() const;
};

#endif