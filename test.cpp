#include <vector>
#include <iostream>
// #include "vector.hpp"

int main()
{
	// ft::vector<int> vector_ft;
	std::vector<int> vec{2, 5, 20, 55, 5};
	std::vector<int>::iterator ptr;

	for (ptr = vec.begin(); ptr < vec.end(); ptr++)
	{
		std::cout << *ptr << " ";
	}
}
