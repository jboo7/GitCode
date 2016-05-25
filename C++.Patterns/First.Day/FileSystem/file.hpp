#ifndef _FILE_HPP
#define _FILE_HPP

#include <memory>

#include "afsitem.hpp"

using namespace std;

class File : public AFSItem {
public:
    File();
    File(const string);

    virtual ~File();
};

#endif