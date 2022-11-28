#include <iterator>
#include <iostream>
#include <vector>


// int	main(void)
// {
// 	std::vector<int> v(4);
// 	v[0] = 1;
// 	v[1] = 2;
// 	v[2] = 3;
// 	v[3] = 4;
// 	typedef std::vector<int>::iterator iter_type;

// 	iter_type start(v.begin());
// 	iter_type end(v.end());
// 	std::reverse_iterator<iter_type> rev_until (start);
// 	std::reverse_iterator<iter_type> rev_from (end);
// 	while (rev_from != rev_until)
// 		std::cout << ' ' << *rev_from++;
// 	std::cout << std::endl;
// }

// free operator+ (reverse_iterator) example
#include <iostream>     // std::cout
#include <iterator>     // std::reverse_iterator
#include <vector>       // std::vector

int main (void) {
	std::vector<int> vector;
	for (int i=0; i<10; i++)
	vector.push_back(i);	// vector: 0 1 2 3 4 5 6 7 8 9

	typedef std::vector<int>::iterator iter_type;
	std::reverse_iterator<iter_type> rev_it;
	std::reverse_iterator<iter_type> diff = vector.rbegin();
	rev_it = 5 + diff;

	std::cout << "rbegin: " << *diff << '\n';
	std::cout << "The fourth element from the end is: " << *rev_it << '\n';
	return 0;
}