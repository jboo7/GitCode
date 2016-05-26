#include <iomanip>
#include "file.hpp"

File::File() : AItem::AItem(FILETYPE) {}
File::File(const string name) : AItem::AItem(FILETYPE, name) {}
File::~File() {}

void File::accept(IVisitor& visitor) const {
    visitor.visit(*this);
}

void File::draw() const {
    cout << setw(2 * this->level() + this->name().length()) << this->name()
         << " - FILE" << endl;
}