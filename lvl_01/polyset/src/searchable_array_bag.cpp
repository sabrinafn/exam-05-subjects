#include "searchable_array_bag.hpp"

// standard constructor
searchable_array_bag::searchable_array_bag(void) {}

// copy constructor
searchable_array_bag::searchable_array_bag(const searchable_array_bag &other)
    : array_bag(other) {}

// = operator
searchable_array_bag& searchable_array_bag::operator=(const searchable_array_bag &other) {
    if (this != &other) {
        array_bag::operator=(other);
    }
    return *this;
}

// destructor
searchable_array_bag::~searchable_array_bag(void) {}

// method from bag class
bool searchable_array_bag::has(int value) const {
    bool found = false;

    for (int i = 0; i < this->size; i++) {
        if (this->data[i] == value)
            found = true;
    }
    return found;
}