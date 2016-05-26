#ifndef _FOLDER_HPP
#define _FOLDER_HPP

#include <vector>
#include <memory>
#include <iostream>
#include "aitem.hpp"

using namespace std;

class Folder : public AItem {
  public:
    Folder();
    Folder(const string);
    virtual ~Folder();

  public:
    virtual void accept(IVisitor&) const;

    virtual void add(const shared_ptr<ITreeElement>);
    virtual void draw() const;

  private:
    vector<shared_ptr<ITreeElement>> mChildren;
};

#endif