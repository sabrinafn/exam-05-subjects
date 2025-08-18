#include "searchable_tree_bag.hpp"

// standard constructor
searchable_tree_bag::searchable_tree_bag(void) {}

// copy constructor
searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &other)
    : tree_bag(other) {}

// = operator
searchable_tree_bag& searchable_tree_bag::operator=(const searchable_tree_bag &other) {
    if (this != &other) {
        tree_bag::operator=(other);
    }
    return *this;
}

// destructor
searchable_tree_bag::~searchable_tree_bag(void) {}

// method from bag class
bool searchable_tree_bag::has(int value) const {
    bool found = false;
    
    node *n = this->tree;
    while (n)
	{
        if (value == n->value) {
            found = true;
            break;
        }
		else if (value < n->value)
			n = n->l;
		else if (value > n->value)
			n = n->r;
	}
    return found;
}