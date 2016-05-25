#include <memory>
#include <vector>
#include "afsitem.hpp"

#ifndef _FOLDER_HPP
#define _FOLDER_HPP

using namespace std;

class Folder : public AFSItem {
  public:
    Folder();
    Folder(const string);
    virtual ~Folder();

    virtual void add(shared_ptr<IElement>&);
    virtual void draw() const;

  private:
    vector<shared_ptr<IElement>> mChildren;
};

#endif