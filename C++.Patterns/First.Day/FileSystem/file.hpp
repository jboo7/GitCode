#include <iostream>
#include <memory>
#include "afsitem.hpp"

#ifndef _FILE_HPP
#define _FILE_HPP

using namespace std;

class File : public AFSItem {
  public:
    File();
    File(const string);
    virtual ~File();

    virtual void draw() const;
};

#endif