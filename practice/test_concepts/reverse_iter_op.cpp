#include <complex>
#include <iostream>
#include <iterator>
#include <vector>

int main (void) {
	std::vector<int> vector;
	for (int i=0; i<10; i++) 
		vector.push_back(i);

	typedef std::vector<int>::iterator iter_type;
	iter_type start(vector.begin());
	iter_type end(vector.end());
	std::reverse_iterator<iter_type> rend (start);
	std::reverse_iterator<iter_type> rbegin (end);
	std::cout << "rbegin " << *rbegin << std::endl;
	std::cout << "rbegin.base() " << *rbegin.base() << std::endl;
	std::cout << "Iter " << *start << std::endl;
	std::cout << "Base iter " << start.base() << std::endl;
	std::cout << std::endl << std::endl;
	
	std::vector<int>::iterator test;
	std::vector<int>::iterator tmp;
	// tmp = end - 1;
	tmp = end;
	test = end;
	std::cout << "vec_start " << *start << std::endl;
	std::cout << "vec_end " << *end << std::endl;
	std::cout << "temp " << *(--tmp) << std::endl;
	std::cout << "test " << *test << std::endl;


	std::cout << "vector:";
	while (rbegin != rend)
	std::cout << ' ' << *rbegin++;
	std::cout << '\n';

	return 0;
}
