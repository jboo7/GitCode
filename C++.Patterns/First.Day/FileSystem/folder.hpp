#ifndef _FOLDER_HPP
#define _FOLDER_HPP

#include "afsitem.hpp"

class Folder : public AFSItem {
public:
    Folder();
    Folder(const string);

    virtual ~Folder();

    void add(const shared_ptr<IElement>);
    void draw() const;
};

#endif