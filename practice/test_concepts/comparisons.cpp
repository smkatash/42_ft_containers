// // lexicographical_compare example
// #include <iostream>     // std::cout, std::boolalpha
// #include <algorithm>    // std::lexicographical_compare
// #include <cctype>       // std::tolower

// // a case-insensitive comparison function:
// bool mycomp (char c1, char c2){ 
// 	return std::tolower(c1) < std::tolower(c2);
// }

// int main (void) {
// 	char foo[]= "ca";
// 	char bar[]= "db";

// 	std::cout << std::boolalpha;
// 	std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";

// 	std::cout << "Using default comparison (operator<): ";
// 	std::cout << std::lexicographical_compare(foo, foo+2, bar, bar+2);
// 	std::cout << '\n';

// 	std::cout << "Using mycomp as comparison object: ";
// 	std::cout << std::lexicographical_compare(foo, foo+2, bar, bar+2, mycomp);
// 	std::cout << '\n';
// 	return 0;
// }

// equal algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::equal
#include <vector>       // std::vector

bool mypredicate (int i, int j) {
  return (i==j);
}

bool is_palindrome(const std::string_view& s)
{
	return std::equal(s.begin(), s.begin() + s.size()/2, s.rbegin());
}

void test(const std::string_view& s)
{
	std::cout << "\"" << s << "\" "
		<< (is_palindrome(s) ? "is" : "is not")
		<< " a palindrome\n";
}

int main (void) {
	int int_arr[] = {20,40,60,80,100};               //   int_arr: 20 40 60 80 100
	std::vector<int> vector;
	vector.push_back(20);
	vector.push_back(40);
	vector.push_back(60);
	vector.push_back(80);
	vector.push_back(100);

	// for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); ++it)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;

	std::cout << std::boolalpha;
	// using default comparison:
	std::cout << std::equal(vector.begin(), vector.end(), int_arr) << std::endl;
	vector[3]=81;	// vector: 20 40 60 81 100
	// using predicate comparison:
	std::cout << std::equal (vector.begin(), vector.end(), int_arr, mypredicate) << std::endl;
	
	test("radar");
	test("sbem");
	return 0;
}
