#include "../../include/vector.hpp"
#include <iostream>
#include <unistd.h>
#include <sstream>
#include <vector>
using namespace ft;

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
	std::cout << vat.at(0) << std::endl;
	try {
		std::cout << vat.at(1) << std::endl;
	} catch (std::out_of_range &r) {
		std::cerr << r.what();
	}
	std::cout << std::endl << "---------------------------" << std::endl;
}

void access2() {
	
	vector<int> vec;
	for (int i = 0; i < 20; i++) {
		vec.push_back(i + 1);
	}
	std::cout << vec.back() << std::endl;
	std::cout << vec.front() << std::endl;
	std::cout << *vec.begin() << std::endl;
	std::cout << *(vec.end() - 1) << std::endl;
	std::cout << *vec.rbegin() << std::endl;
	std::cout << *(vec.rend() - 1) << std::endl;

	std::cout << std::endl << "---------------------------" << std::endl;
	std::cout << std::boolalpha << vec.empty() << std::endl;
	vec.clear();
	std::cout << std::boolalpha << vec.empty() << std::endl;
	std::cout << std::endl << "---------------------------" << std::endl;
}


void	modification() {
	vector<int> v;

	for (int i = 0; i < 20; i++) {
		v.push_back(i + 1);
	}
	vector<int>::iterator it = v.begin();
	v.erase(it, it + 9);

	for (; it != v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl << "---------------------------" << std::endl;
}

void	allocator() {
	vector<int> myvector;
	int * p;
	unsigned int i;

	// allocate an array with space for 5 elements using vector's allocator:
	p = myvector.get_allocator().allocate(5);

	// construct values in-place on the array:
	for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

	std::cout << "The allocated array contains:";
	for (i=0; i<5; i++) std::cout << ' ' << p[i];
	std::cout << '\n';

	// destroy and deallocate:
	for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
	myvector.get_allocator().deallocate(p,5);
}

void inserter() {
	vector<int> myvector (3,100);
	vector<int>::iterator it;

	it = myvector.begin();
	it = myvector.insert ( it , 200 );

	myvector.insert (it,2,300);

	// "it" no longer valid, get a new one:
	it = myvector.begin();

	vector<int> anothervector (2,400);
	myvector.insert (it+2,anothervector.begin(),anothervector.end());

	int myarray [] = { 501,502,503 };
	myvector.insert (myvector.begin(), myarray, myarray+3);

	std::cout << "myvector contains:";
	for (it=myvector.begin(); it<myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << std::endl << "---------------------------" << std::endl;

	vector<int> foo (3,0);
	vector<int> bar (5,0);

	bar = foo;
	foo = vector<int>();

	std::cout << "Size of foo: " << int(foo.size()) << '\n';
	std::cout << "Size of bar: " << int(bar.size()) << '\n';
}

void utils() {
	vector<int> v1;

	for (int i = 0; i < 20; i++) {
		v1.push_back(i * 2);
	}
	std::cout << v1.size() << std::endl;
	v1.pop_back();
	v1.pop_back();
	v1.pop_back();
	v1.pop_back();
	v1.pop_back();
	vector<int>::iterator it = v1.begin();
	for (; it != v1.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << v1.size() << std::endl;

	std::cout << std::endl << "---------------------------" << std::endl;
	vector<int> myvector;
	// set some initial content:
	for (int i=1;i<10;i++) myvector.push_back(i);

	myvector.resize(5);
	myvector.resize(8,100);
	myvector.resize(12);

	std::cout << "myvector contains:";
	for (int i=0;i<myvector.size();i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

}

void terminatordiff() {
	vector<char> v;

	std::istringstream str("1 2 3 4 5 6 7");
	std::istreambuf_iterator<char> it(str), end;
	v.assign(it, end);

	for (vector<char>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << " ";
	}
}

void	deepcopy() {
	vector<double> v1;

	for (int i = 1; i <= 10; i++) {
		v1.push_back(i * 12.3332);
	}

	vector<double> v2(v1);
	if (&v1[0]== &v2[0])
		std::cout << "They are equal";
	else
		std::cout << "They are NOT equal";
	std::cout << &v1[0] << " " << &v2[0] << std::endl;

	std::cout << "------------------" << std::endl;

	std::vector<double> vcopy1;

	for (int i = 1; i <= 10; i++) {
		vcopy1.push_back(i * 12.3332);
	}

	std::vector<double> vcopy2(vcopy1);
	std::cout << vcopy1[0] << " " << vcopy2[0];
	if (&vcopy1[0] == &vcopy2[0])
		std::cout << "They are equal";
	else
		std::cout << "They are NOT equal";
	std::cout << &vcopy1[0] << " " << &vcopy2[0] << std::endl;
}

struct abc {
    int data[1024];
    long num;
};

void	sizes() {
	std::cout << "---------------My Vector ------------" << std::endl;
	std::cout << vector<unsigned char>().max_size() << std::endl;
	std::cout << vector<char>().max_size() << std::endl;
	std::cout << vector<int>().max_size() << std::endl;
	std::cout << vector<long>().max_size() << std::endl;
	std::cout << vector<short>().max_size() << std::endl;
	std::cout << vector<abc>().max_size() << std::endl;
	std::cout << vector<float>().max_size() << std::endl;
	
	std::cout << "--------------STD Vector-------------" << std::endl;

	std::cout << std::vector<unsigned char>().max_size() << std::endl;
	std::cout << std::vector<char>().max_size() << std::endl;
	std::cout << std::vector<int>().max_size() << std::endl;
	std::cout << std::vector<long>().max_size() << std::endl;
	std::cout << std::vector<short>().max_size() << std::endl;
	std::cout << std::vector<abc>().max_size() << std::endl;
	std::cout << std::vector<float>().max_size() << std::endl;

	std::cout << "---------------Allocator-----------" << std::endl;

	std::cout << std::allocator<unsigned char>().max_size() << std::endl;
	std::cout << std::allocator<char>().max_size() << std::endl;
	std::cout << std::allocator<int>().max_size() << std::endl;
	std::cout << std::allocator<long>().max_size() << std::endl;
	std::cout << std::allocator<short>().max_size() << std::endl;
	std::cout << std::allocator<abc>().max_size() << std::endl;
	std::cout << std::allocator<float>().max_size() << std::endl;
}

void	check_capacity_print(vector<int>& v) {
	vector<int>::iterator it = v.begin();

	std::cout << "Size " << v.size() << " capacity: " << v.capacity() << std::endl;
	for (; it != v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	std_check_capacity_print(std::vector<int>& v) {
	std::vector<int>::iterator it = v.begin();

	std::cout << "Size " << v.size() << " capacity: " << v.capacity() << std::endl;
	for (; it != v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}


void	insert_size() {
	vector<int> v;
	v.insert(v.begin(), 0, 64);
	check_capacity_print(v);
	v.insert(v.end(), 0, 64);
	check_capacity_print(v);
	v.insert(v.end(), 10, 64);
	check_capacity_print(v);
	v.insert(v.begin(), 5, -1);
	check_capacity_print(v);
	v.insert(v.begin() + 1, 1, -9);
	check_capacity_print(v);
	v.insert(v.begin() + 7, 21, 88);
	check_capacity_print(v);
	v.insert(v.begin(), 0, 2);
	check_capacity_print(v);
	v.insert(v.end(), 0, 4);
	check_capacity_print(v);
	v.insert(v.end(), 18, 420);
	check_capacity_print(v);
	v.insert(v.end(), 8, 4242);
	check_capacity_print(v);
}

void	std_insert_size() {
	std::vector<int> v;
	v.insert(v.begin(), 0, 64);
	std_check_capacity_print(v);
	v.insert(v.end(), 0, 64);
	std_check_capacity_print(v);
	v.insert(v.end(), 10, 64);
	std_check_capacity_print(v);
	v.insert(v.begin(), 5, -1);
	std_check_capacity_print(v);
	v.insert(v.begin() + 1, 1, -9);
	std_check_capacity_print(v);
	v.insert(v.begin() + 7, 21, 88);
	std_check_capacity_print(v);
	v.insert(v.begin(), 0, 2);
	std_check_capacity_print(v);
	v.insert(v.end(), 0, 4);
	std_check_capacity_print(v);
	v.insert(v.end(), 18, 420);
	std_check_capacity_print(v);
	v.insert(v.end(), 8, 4242);
	std_check_capacity_print(v);
}


void	string_check_capacity_print(vector<std::string>& v) {
	vector<std::string>::iterator it = v.begin();

	std::cout << "Size " << v.size() << " capacity: " << v.capacity() << std::endl;
	for (; it != v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

std::string b_string[64] = {                                                                   \
        "uvg6KqtcgduR31n3ajsv", "wbiAcjgojb9JOagZwyMn", "ATZKCzaPOqgkhPjwuGlf",                    \
        "MOhaJs56yjOw8f6nLPRA", "0gyB2Tr42v6awMw2nK7J", "e6GsiLFUuoDpVFEhJKZ1",                    \
        "z0jXAhiV9keBsaLOY0Xf", "P68p2ZAosHJdmoZh1C7N", "Pu3EuZVeY0TCO3ojdK0t",                    \
        "z7jCHMooHCS73M8GygKB", "uT4KoK83JrZxZjkul7ty", "g8gfrZoY5XwfzRusvHvv",                    \
        "7PGmkM0OSRnYREt9mFIP", "q1od7mBIpPEsCtpF9kdw", "XQo0LWId5TdZnLnpUNOb",                    \
        "U0m1R0kFFhAFyS6hmHHw", "K0lPKfxJxIOnE8QB90xn", "cZ5xyQifMJhrKxqBK9A7",                    \
        "cFBiwjfYw7Js6qEGy5Kt", "1tW0KWfXxeFO69tByqcE", "3Fvq9NxBrhPXHe0IlIVx",                    \
        "MSRDjdFRvHAhFGhiMtDe", "zGm2joMh71jQkYzg5L4V", "Mq4RRaeLvSAO0z2ibp8Q",                    \
        "WnLFYnQKP8TNJkqVVbUg", "E98UphbbVSzrW5Mzurmg", "F8HRxeEcaTZDkFPkioij",                    \
        "jmUVl4Q8X5BwVNzXN219", "n7Xp4w4FwzGKit7AI4SO", "4MxXYr6rKOcXLt9UkVd2",                    \
        "4RVTDsADtRyboaai9d29", "XaSqsrrtdhAfFoJIc5KK", "9Z9jdVCrTT09bg348ceb",                    \
        "I6uqLG9dO5mfNdSMwOYm", "UwMTzJPlbnhgwbHpDi6w", "DebjMP9afncYE6GhhO00",                    \
        "YGPuscYDiGfAjY1UWST0", "K6gbvgGjVZgEFUDlkdSk", "8xCBPI0w6TpC0RA62c2W",                    \
        "fYMxkNwmKg3moP8KvD9v", "QpPdhwhEYjIugg3OPcPH", "qQBXjSn43I3EMP54SyxZ",                    \
        "7qvdKwoW1CQEZTWPvuSC", "rCT212rdYO0zTGHXesKg", "dBHvlHsBwcR9MkkenYYG",                    \
        "NQiSlergqR8fVbOeivLj", "xYVqsV147UIe7jVBVwXo", "tcxayO4DdEJ885TbqUMy",                    \
        "9TGSMTD8U8ksRpHqq0cL", "TIJ16jCv9BSUiWvhbF9T", "BM9GL2ig1hePkA6lM6Ck",                    \
        "TfJTYB9JQMU6CGcYg20Q", "Fg6e5YT2FQbpTZNTDqdo", "LI5q6ml40MeE9H1dPb93",                    \
        "OaxJUSm3nYN9Y8Ela7sS", "BgBeODAwXz7xJo50Rwqd", "xdkgKj1dEoJ6zuVhkvvo",                    \
        "olIewtUEvXJgs1lB9bCn", "dTsPDS0x2uXtcgOIJHb8", "DYvJ2phLppGNZKboTBrd",                    \
        "DjNFMtt9PxkzqvWBHI6j", "1Z3YkeTFlPniKnzFhzgu", "76XqQg6hqMf5IXxKPOEs",                    \
        "gzaapTWW7i9EZjjzLeK6"                                                                     \
    };                         


void	resize() {
			vector<std::string> v;

			v.resize(14, "HelloWorld");

			string_check_capacity_print(v);

			v.resize(6, "ABC");

			string_check_capacity_print(v);

			v.resize(14, b_string[18]);

			string_check_capacity_print(v);

			v.resize(15, b_string[57]);

			string_check_capacity_print(v);

			v.resize(64, "I-like-vectors");

			string_check_capacity_print(v);
}

void	std_string_check_capacity_print(std::vector<std::string>& v) {
	std::vector<std::string>::iterator it = v.begin();

	std::cout << "Size " << v.size() << " capacity: " << v.capacity() << std::endl;
	for (; it != v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}


void	std_resize() {
			std::vector<std::string> v;

			v.resize(14, "HelloWorld");

			std_string_check_capacity_print(v);

			v.resize(6, "ABC");

			std_string_check_capacity_print(v);

			v.resize(14, b_string[18]);

			std_string_check_capacity_print(v);

			v.resize(15, b_string[57]);

			std_string_check_capacity_print(v);

			v.resize(64, "I-like-vectors");

			std_string_check_capacity_print(v);
}


int main() {

	// constructors();
	// iterators();
	// assign();
	// allocation();
	// access();
	// access2();
	// modification();
	// allocator();
	// inserter();
	// utils();
	// atexit(checkLeaks);
	// terminatordiff();
	// deepcopy();
	// sizes();
	//insert_size();
	//std_insert_size();
	resize();
	std_resize();
	return 0;
}