#ifndef EXAM_ASSIGNMENTS_ARRAY_BAG_HPP
#define EXAM_ASSIGNMENTS_ARRAY_BAG_HPP
#include "bag.hpp"

class array_bag : virtual public bag {
protected:
	int *data;
	int size;
public:
	array_bag(); 
	array_bag(const array_bag &); 
	array_bag &operator=(const array_bag &other); 
	~array_bag(); 

	void insert(int); 
	void insert(int *, int); // insert multiple elements from an array of elements
	void print() const; 
	void clear();
};

#endif
