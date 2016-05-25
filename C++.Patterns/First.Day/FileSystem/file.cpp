#include "file.hpp"

File::File() : AFSItem::AFSItem() {}

File::File(const string name) : AFSItem::AFSItem(name) {}

File::~File() {}

void File::draw() const {
    for (int i = 0; i < this->getLevel(); i++) {
        cout << "  ";
    }
    cout << this->getName() << " FILE" << endl;
}