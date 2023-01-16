#include <iostream>
#include <string>
# include <iomanip>
# include <sys/time.h>
#include "../include/vector.hpp"

namespace vector
{
	static void	ft_constructor(void)
	{
		ft::vector<int> first;                                // empty vector of ints
		ft::vector<int> second (4,100);                       // four ints with value 100
		ft::vector<int> third (second.begin(),second.end());  // iterating through second
		ft::vector<int> fourth (third);                       // a copy of third

		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {16,2,77,29};
		ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

		std::cout << "The contents of fifth are:\n";
		for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
	}

	void	ft_operator_equal(void)
	{
		ft::vector<int> foo (3,0);
		ft::vector<int> bar (5,0);

		bar = foo;
		foo = ft::vector<int>();

		std::cout << "Size of foo and bar:\n" << int(foo.size()) << " and " << int(bar.size());
		std::cout << std::endl;
	}

	void	ft_begin_end(void)
	{
		ft::vector<int> myvector;
		for (int i=1; i<=5; i++) myvector.push_back(i);

		std::cout << "myvector contains:\n";
		for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
	}

	void	ft_rbegin_rend(void)
	{
		ft::vector<int> myvector (5);  // 5 default-constructed ints

		int i=0;

		ft::vector<int>::reverse_iterator rit = myvector.rbegin();
		for (; rit!= myvector.rend(); ++rit)
			*rit = ++i;

		std::cout << "myvector contains:\n";
		for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
	}

	static void	ft_size(void)
	{
		ft::vector<int> myints;
		std::cout << "size:\n" << myints.size();

		for (int i=0; i<10; i++) myints.push_back(i);
		std::cout << ", " << myints.size();

		myints.insert (myints.end(),10,100);
		std::cout << ", " << myints.size();

		myints.pop_back();
		std::cout << ", " << myints.size();
		std::cout << std::endl;
	}

	void	ft_max_size(void)
	{
		ft::vector<int> myvector;

		// set some content in the vector:
		for (int i=0; i<100; i++) myvector.push_back(i);

		std::cout << "size, capacity and max_size:\n" << myvector.size();
		std::cout << ", " << myvector.capacity();
		std::cout << " and " << myvector.max_size();
		std::cout << std::endl;
	}

	void	ft_resize(void)
	{
		ft::vector<int> myvector;

		// set some initial content:
		for (int i=1;i<10;i++) myvector.push_back(i);

		myvector.resize(5);
		myvector.resize(8,100);
		myvector.resize(12);

		std::cout << "myvector contains:\n";
		for (size_t i=0;i<myvector.size();i++)
			std::cout << ' ' << myvector[i];
		std::cout << std::endl;
	}

	void	ft_capacity(void)
	{
		ft::vector<int> myvector;

		// set some content in the vector:
		for (int i=0; i<100; i++) myvector.push_back(i);

		std::cout << "size, capacity and max_size:\n" << myvector.size();
		std::cout << ", " << myvector.capacity();
		std::cout << " and " << myvector.max_size();
		std::cout << std::endl;
	}

	static void	ft_empty(void)
	{
		ft::vector<int> myvector;
		int sum (0);

		for (int i=1;i<=10;i++) myvector.push_back(i);

		while (!myvector.empty())
		{
			sum += myvector.back();
			myvector.pop_back();
		}

		std::cout << "total:\n" << sum;
		std::cout << std::endl;
	}

	void	ft_reserve(void)
	{
		ft::vector<int>::size_type sz;

		ft::vector<int> foo;
		sz = foo.capacity();
		std::cout << "capacity changed:\n";
		for (int i=0; i<100; ++i) {
			foo.push_back(i);
			if (sz!=foo.capacity()) {
				sz = foo.capacity();
				std::cout << sz << ", ";
			}
		}
		std::cout << std::endl;

		ft::vector<int> bar;
		sz = bar.capacity();
		bar.reserve(100);   // this is the only difference with foo above
		for (int i=0; i<100; ++i) {
			bar.push_back(i);
			if (sz!=bar.capacity()) {
				sz = bar.capacity();
				std::cout << sz << ", ";
			}
		}
		std::cout << std::endl;
	}

	void	ft_operator_brackets(void)
	{
		ft::vector<int> myvector (10);   // 10 zero-initialized elements

		ft::vector<int>::size_type sz = myvector.size();

		// assign some values:
		for (unsigned i=0; i<sz; i++) myvector[i]=i;

		// reverse vector using operator[]:
		for (unsigned i=0; i<sz/2; i++)
		{
			int temp;
			temp = myvector[sz-1-i];
			myvector[sz-1-i]=myvector[i];
			myvector[i]=temp;
		}

		std::cout << "myvector contains:\n";
		for (unsigned i=0; i<sz; i++)
			std::cout << ' ' << myvector[i];
		std::cout << std::endl;
	}

	void	ft_at(void)
	{
		ft::vector<int> myvector (10);   // 10 zero-initialized ints

		// assign some values:
		for (unsigned i=0; i<myvector.size(); i++)
			myvector.at(i)=i;

		std::cout << "myvector contains:\n";
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector.at(i);
		std::cout << std::endl;
	}

	void	ft_front(void)
	{
		ft::vector<int> myvector;

		myvector.push_back(78);
		myvector.push_back(16);

		// now front equals 78, and back 16

		myvector.front() -= myvector.back();

		std::cout << "myvector.front() is now " << myvector.front();
		std::cout << std::endl;
	}

	void	ft_back(void)
	{
		ft::vector<int> myvector;

		myvector.push_back(10);

		while (myvector.back() != 0)
		{
			myvector.push_back ( myvector.back() -1 );
		}

		std::cout << "myvector contains:\n";
		for (unsigned i=0; i<myvector.size() ; i++)
			std::cout << ' ' << myvector[i];
		std::cout << std::endl;
	}

	void	ft_assign(void)
	{
		ft::vector<int> first;
		ft::vector<int> second;
		ft::vector<int> third;

		first.assign (7,100);             // 7 ints with a value of 100

		ft::vector<int>::iterator it;
		it=first.begin()+1;

		second.assign (it,first.end()-1); // the 5 central values of first

		int myints[] = {1776,7,4};
		third.assign (myints,myints+3);   // assigning from array.

		std::cout << "Size:\n" << int (first.size()) << ", " << int (second.size()) << ", " << int (third.size());
		std::cout << std::endl;
	}

	void	ft_push_back(void)
	{
		ft::vector<int> myvector;

		for (int i = 0; i < 100; i += 1)
			myvector.push_back (i);

		std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
	}

	void	ft_pop_back(void)
	{
		ft::vector<int> myvector;
		int sum (0);
		myvector.push_back (100);
		myvector.push_back (200);
		myvector.push_back (300);

		while (!myvector.empty())
		{
			sum+=myvector.back();
			myvector.pop_back();
		}

		std::cout << "The elements of myvector add up to " << sum;
		std::cout << std::endl;
	}

	static void	ft_insert(void)
	{
		ft::vector<int> myvector (3,100);
		ft::vector<int>::iterator it;

		it = myvector.begin();
		it = myvector.insert ( it , 200 );

		myvector.insert (it,2,300);

		// "it" no longer valid, get a new one:
		it = myvector.begin();

		ft::vector<int> anothervector (2,400);
		myvector.insert (it+2,anothervector.begin(),anothervector.end());

		int myarray [] = { 501,502,503 };
		myvector.insert (myvector.begin(), myarray, myarray+3);

		std::cout << "myvector contains:\n";
		for (it=myvector.begin(); it<myvector.end(); it++)
			std::cout << ' ' << *it;
		std::cout << std::endl;
	}

	static void	ft_erase(void)
	{
		ft::vector<int> myvector;

		// set some values (from 1 to 10)
		for (int i=1; i<=10; i++) myvector.push_back(i);

		// erase the 6th element
		myvector.erase (myvector.begin()+5);

		// erase the first 3 elements:
		myvector.erase (myvector.begin(),myvector.begin()+3);

		std::cout << "myvector contains:\n";
		for (unsigned i=0; i<myvector.size(); ++i)
			std::cout << ' ' << myvector[i];
		std::cout << std::endl;
	}

	static void	ft_swap(void)
	{
		ft::vector<int> foo (3,100);   // three ints with a value of 100
		ft::vector<int> bar (5,200);   // five ints with a value of 200

		foo.swap(bar);

		std::cout << "foo and bar contain:\n";
		for (unsigned i=0; i<foo.size(); i++)
			std::cout << ' ' << foo[i];

		for (unsigned i=0; i<bar.size(); i++)
			std::cout << ' ' << bar[i];
		std::cout << std::endl;
	}

	static void	ft_clear(void)
	{
		ft::vector<int> myvector;
		myvector.push_back (100);
		myvector.push_back (200);
		myvector.push_back (300);

		std::cout << "myvector contains:\n";
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector[i];

		myvector.clear();
		myvector.push_back (1101);
		myvector.push_back (2202);

		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector[i];
		std::cout << std::endl;
	}

	void	ft_get_allocator(void)
	{
		ft::vector<int> myvector;
		int * p;
		unsigned int i;

		// allocate an array with space for 5 elements using vector's allocator:
		p = myvector.get_allocator().allocate(5);

		// construct values in-place on the array:
		for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

		std::cout << "The allocated array contains:\n";
		for (i=0; i<5; i++) std::cout << ' ' << p[i];

		// destroy and deallocate:
		for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
		myvector.get_allocator().deallocate(p,5);
		std::cout << std::endl;
	}

	void	ft_relational_operators(void)
	{
		ft::vector<int> foo (3,100);   // three ints with a value of 100
		ft::vector<int> bar (2,200);   // two ints with a value of 200

		if (foo==bar) std::cout << "1";
		if (foo!=bar) std::cout << "2";
		if (foo< bar) std::cout << "3";
		if (foo> bar) std::cout << "4";
		if (foo<=bar) std::cout << "5";
		if (foo>=bar) std::cout << "6";
		std::cout << std::endl;
	}

	void	ft_swapv(void)
	{
		ft::vector<int> foo (3,100);   // three ints with a value of 100
		ft::vector<int> bar (5,200);   // five ints with a value of 200

		foo.swap(bar);

		std::cout << "foo and bar contain:\n";
		for (ft::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
			std::cout << ' ' << *it;

		for (ft::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
	}
}

void	test_header(std::string title)
{
	std::cout << "---------------------------\n";
	int space = (20 - title.length()) / 2;
	std::cout << "----";
	for (int i = 0; i < space; i += 1)
		std::cout << " ";
	std::cout << "\x1B[33m" << title << "\033[0m";
	for (int i = 0; i < space; i += 1)
		std::cout << " ";
	std::cout << "----";
	std::cout << "\n---------------------------\n";
}

void	print_timestamp(struct timeval start, struct timeval end)
{
	suseconds_t time_taken;
  
	time_taken = end.tv_usec - start.tv_usec;
	time_taken = (time_taken + (end.tv_usec - start.tv_usec));

	std::cout << "( " << std::fixed
		 << time_taken << std::setprecision(2);
	std::cout << " microsec )" << std::endl;
}

void	test(void (*ft)(void), std::string title)
{
	std::cout << std::endl;
	test_header(title);

	struct timeval start, end;
	gettimeofday(&start, NULL);
	ft();
	gettimeofday(&end, NULL);
	print_timestamp(start, end);

	std::cout << std::endl;
}

void	vector_tests(void)
{
	test(vector::ft_constructor, "constructor");
	test(vector::ft_operator_equal, "operator=");
	test(vector::ft_begin_end, "begin_end");
	test(vector::ft_rbegin_rend, "rbegin_rend");
	test(vector::ft_size, "size");
	test(vector::ft_max_size, "max_size");
	test(vector::ft_resize, "resize");
	test(vector::ft_capacity, "capacity");
	test(vector::ft_empty, "empty");
	test(vector::ft_reserve, "reserve");
	test(vector::ft_operator_brackets, "operator[]");
	test(vector::ft_at, "at");
	test(vector::ft_front, "front");
	test(vector::ft_back, "back");
	test(vector::ft_assign, "assign");
	test(vector::ft_push_back, "push_back");
	test(vector::ft_pop_back, "pop_back");
	test(vector::ft_insert, "insert");
	test(vector::ft_erase, "erase");
	test(vector::ft_swap, "swap");
	test(vector::ft_clear, "clear");
	test(vector::ft_get_allocator, "get_allocator");
	test(vector::ft_relational_operators, "operators");
	test(vector::ft_swapv, "swap (vector)");
}

int main(int argc, char** argv)
{
	vector_tests();
	return (0);
}
