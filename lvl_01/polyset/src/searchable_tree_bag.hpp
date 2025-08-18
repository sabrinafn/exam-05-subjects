#ifndef SEARCHABLE_TREE_BAG_HPP
#define SEARCHABLE_TREE_BAG_HPP

#include "tree_bag.hpp"
#include "searchable_bag.hpp"

class searchable_tree_bag : public tree_bag, public searchable_bag {

    private:
        
    public:
        searchable_tree_bag(void); // standard constructor
        searchable_tree_bag(const searchable_tree_bag &other); // copy constructor
        searchable_tree_bag& operator=(const searchable_tree_bag &other); // = operator
        ~searchable_tree_bag(void); // destructor

        bool has(int value) const; // method from bag class
};

#endif