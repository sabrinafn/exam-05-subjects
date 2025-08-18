#ifndef SET_HPP
#define SET_HPP

#include "searchable_bag.hpp"

// set do not allow duplicates

class set {

    private:
        searchable_bag *set_bag;
    public:
        set(void); // constructor
        set(const set &other); // copy constructor
        set &operator=(const set &other); // = operator overload
        ~set(void);

        set(searchable_bag &other); // constructor with parameter

        searchable_bag &get_bag(void);

        void insert(int val);
	    void insert(int *arr, int size);
	    void print(void) const;
	    void clear(void);
        bool has(int i) const;
};

#endif