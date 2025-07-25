#include "searchable_tree_bag.hpp" // TO DO
#include "searchable_array_bag.hpp" // TO DO
#include <cstdlib>
#include <iostream>
#include "set.hpp" // TO DO

int main(int ac, char **av)
{
	if (ac == 1)
		return 1;
	searchable_bag *t = new searchable_tree_bag;
	searchable_bag *a = new searchable_array_bag;
	for (int i = 1; i < ac; i++)
	{
		t->insert(atoi(av[i]));
		a->insert(atoi(av[i]));
	}
	std::cout << "print tree: ";
	t->print();
	std::cout << "print array: ";
	a->print();
	//for (int i = 1; i < ac; i++)
	//{
	//	std::cout << "tree value to find: " << atoi(av[i]) << ". return from function: " << t->has(atoi(av[i])) << std::endl;
	//	std::cout << "array value to find: " << atoi(av[i]) << ". return from function: " << a->has(atoi(av[i])) << std::endl;
	//	std::cout << "tree value to find: " << atoi(av[i]) - 1 << ". return from function: " << t->has(atoi(av[i]) - 1) << std::endl;
	//	std::cout << "array value to find: " << atoi(av[i]) - 1 << ". return from function: " << a->has(atoi(av[i]) - 1) << std::endl;
	//	std::cout << std::endl;
	//}
	t->clear();
	a->clear();
	
	const searchable_array_bag tmp(static_cast<searchable_array_bag &>(*a));
	std::cout << "print array const: ";
	tmp.print();
	std::cout << "array const has value 1? ";
	std::cout << tmp.has(1) << std::endl;
	set sa(*a);
	set st(*a);
	for (int i = 1; i < ac; i++)
	{
		st.insert(atoi(av[i]));
		sa.insert(atoi(av[i]));
	}
	sa.has(atoi(av[1]));
	sa.print();
	sa.get_bag().print();
	st.print();
	sa.clear();
	sa.insert((int[]){1, 2, 3, 4}, 4);
}