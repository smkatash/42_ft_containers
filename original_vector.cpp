#include <iostream>
#include <unistd.h>
#include <vector>
using namespace std;

void checkLeaks() {
	system("leaks a.out");
}


void	iterators()
{
	vector<int> v1;

	for (int i = 0; i <= 20; i++) {
		v1.push_back(i * 2);
	}
	vector<int>::iterator it = v1.begin();
	for (; it != v1.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	vector<int>::reverse_iterator rit = v1.rbegin();
	for (; rit != v1.rend(); rit++) {
		std::cout << *rit << " ";
	}
}

struct node {
	std::string _name;
	int			_age;
	float		_gpa;
	node(std::string name, int age, float gpa): _name(name), _age(age), _gpa(gpa) {}
};

void	constructors() {
	vector<int> empty;
	vector<std::string> v(5, "hello");
	vector<int> vfill(24, 42);
	vector<node>  vfill2(2, node("Bob", 25, 2.4));

	// SEGfault correct
	// std::cout << empty[0] << std::endl;

	std::cout << " String range fill " << std::endl;
	vector<std::string>::iterator it = v.begin();
	for (; it != v.end(); it++) {
		std::cout << *it << " ";
	}

	std::cout << std::endl;
	std::cout << " Range fill " << std::endl;

	vector<int>::iterator itfill = vfill.begin();
	for (; itfill != vfill.end(); itfill++) {
		std::cout << *itfill << " ";
	}

	std::cout << std::endl;
	std::cout << " Range fill with Node " << std::endl;

	for (int i = 0; i < 2; i++) {
		std::cout << vfill2[i]._name << " " << vfill2[i]._age << " " << vfill2[i]._gpa << std::endl;
	}

	std::cout << std::endl;
	std::cout << " Range fill with iterator " << std::endl;
	vector<int> vfillcopy(vfill.begin(), vfill.end());

	vector<int>::iterator itcopy = vfillcopy.begin();
	for (; itcopy != vfillcopy.end(); itcopy++) {
		std::cout << *itcopy << " ";
	}

	std::cout << std::endl;
	std::cout << " Copy constructor " << std::endl;
	vector<int> vcopy(vfillcopy);

	vector<int>::iterator itcp = vcopy.begin();
	for (; itcp != vcopy.end(); itcp++) {
		std::cout << *itcp << " ";
	}
	std::cout << std::endl;
	std::cout << " Assignmnet operator " << std::endl;

	vector<std::string> assign = v;
	vector<std::string>::iterator ita = assign.begin();
	for (; ita != assign.end(); ita++) {
		std::cout << *ita << " ";
	}
}

void	assign() {
	vector<int> first;
	vector<int> second;
	vector<int> third;

	first.assign (7,100);             // 7 ints with a value of 100

	vector<int>::iterator it;
	it = first.begin() + 1;

	second.assign (it,first.end()-1); // the 5 central values of first

	int myints[] = {1776,7,4};
	third.assign (myints,myints+3);   // assigning from array.

	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';
	std::cout << "Size of third: " << int (third.size()) << '\n';
}


void	allocation() {
	vector<int> v;
	std::vector<int> std_v;
	std::allocator<int> alloc;

	v.reserve(5);
	std_v.reserve(5);

	std::cout << "my vector " << v.max_size() << std::endl;
	std::cout << "original vector " << std_v.max_size() << std::endl;
	std::cout << "allocator " << alloc.max_size() << std::endl;

	vector<std::string> v2;
	std::vector<std::string> std_v2;
	std::allocator<std::string> alloc2;
	std::cout << "my vector " << v2.max_size() << std::endl;
	std::cout << "original vector " << std_v2.max_size() << std::endl;
	std::cout << "allocator " << alloc2.max_size() << std::endl;

	std::cout << std::endl << "---------------------------" << std::endl;
	std::cout << "capacity " << v.capacity() << std::endl;
	std::cout << "size " << v.size() << std::endl;
	std::cout << "capacity " << std_v.capacity() << std::endl;
	std::cout << "size " <<  std_v.size() << std::endl;

	for (int i = 0; i < 10; i++) {
		v.push_back(i * 2);
		std_v.push_back(i * 2);
	}

	std::cout << std::endl << "---------------------------" << std::endl;
	std::cout << "capacity " << v.capacity() << std::endl;
	std::cout << "size " << v.size() << std::endl;
	std::cout << "capacity " << std_v.capacity() << std::endl;
	std::cout << "size " <<  std_v.size() << std::endl;

	vector<std::string> empty_test;
	vector<std::string> reserved_test;
	reserved_test.reserve(2);
	std::cout << std::boolalpha << empty_test.empty() << std::endl;
	std::cout << std::boolalpha << reserved_test.empty() << std::endl;
	std::cout << std::boolalpha << v.empty() << std::endl;

	std::cout << std::endl << "---------------------------" << std::endl;
	std::vector<std::string> empty;
	std::vector<std::string> reserved;
	reserved.reserve(2);
	std::cout << std::boolalpha << empty.empty() << std::endl;
	std::cout << std::boolalpha << reserved.empty() << std::endl;
	std::cout << std::boolalpha << std_v.empty() << std::endl;
}

void access() {
	vector<int> myvector (10);   // 10 zero-initialized ints

	// assign some values:
	for (unsigned i = 0; i < myvector.size(); i++)
		myvector.at(i) = i;

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector.at(i);
	std::cout << std::endl;

	vector<std::string> vat;
	std::string h = "hello";
	vat.push_back(h);
	std::cout << "end" << std::endl;
	std::cout << vat.at(0) << std::endl;
	std::cout << vat.at(1) << std::endl;

}

int main() {

	constructors();
	iterators();
	assign();
	allocation();
	access();
	// atexit(checkLeaks);
	return 0;
}