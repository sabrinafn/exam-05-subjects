#include "set.hpp"

// constructor
set::set(void) : set_bag() {}

// copy constructor
set::set(const set &other) {
    *this = other;
}

// = operator overload
set &set::operator=(const set &other) {
    if (this != &other) {
        this->set_bag = other.set_bag;
    }
    return *this;
}

//destructor
set::~set(void) {}

// constructor with parameter
set::set(searchable_bag &other) : set_bag(&other) {}

searchable_bag &set::get_bag(void) {
    return *this->set_bag;
}

void set::insert(int val) {
    if (this->set_bag->has(val))
        return;
    this->set_bag->insert(val);
}

void set::insert(int *arr, int size) {
    this->set_bag->insert(arr, size);
}

void set::print(void) const {
    this->set_bag->print();
}

void set::clear(void) {
    this->set_bag->clear();
}

bool set::has(int i) const {
    return this->set_bag->has(i);
}