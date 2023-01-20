# include "base.hpp"
// as STL for stack to check for compatibility
#include <deque>
#include <algorithm>
#include <iostream>
#include <list>

void sconstructors() {
	std::deque<int>					mydeque(3,100);
	std::list<int>					mylist(4, 100);
	NAMESPACE::vector<int>			empty_vector;
	NAMESPACE::vector<int>			myvector(2,200);

	NAMESPACE::stack<int> 								def;
	NAMESPACE::stack<int, std::deque<int> >				deq(mydeque);
	NAMESPACE::stack<int, std::list<int> >				lst(mylist);
	NAMESPACE::stack<int, NAMESPACE::vector<int> >		vct(myvector);

	std::cout << "size of empty vector: " << empty_vector.size() << std::endl;
	std::cout << "size of empty stack: " << def.size() << std::endl;

	std::cout << "size of deque: " << mydeque.size() << std::endl;
	std::cout << "size of deque stack: " << deq.size() << std::endl;

	std::cout << "size of list: " << mylist.size() << std::endl;
	std::cout << "size of list stack: " << lst.size() << std::endl;

	std::cout << "size of vector: " << myvector.size() << std::endl;
	std::cout << "size of vector stack: " << vct.size() << std::endl;
}

void	smodifiers() {
	NAMESPACE::stack<char> mystack;

	for (char i = 97; i <= 122; ++i)
		mystack.push(i);

	std::cout << "Empty: " << std::boolalpha << mystack.empty() << std::endl;
	std::cout << "Size: " <<  mystack.size() << std::endl;
	std::cout << "Popping out elements...";
	while (!mystack.empty())
	{
		std::cout << ' ' << mystack.top();
		mystack.pop();
	}
	std::cout << std::endl;
	std::cout << "Empty: " << std::boolalpha << mystack.empty() << std::endl;
	std::cout << "Size: " <<  mystack.size() << std::endl;

	std::cout << "<-------------------------------------->" << std::endl;

	std::deque<std::string>									mydeque(10,"42Heilbronn");
	NAMESPACE::stack<std::string, std::deque<std::string> > deqstack(mydeque);

	std::cout << "Empty: " << std::boolalpha << deqstack.empty() << std::endl;
	std::cout << "Size: " <<  deqstack.size() << std::endl;
	std::cout << "Popping out elements...";
	while (!deqstack.empty())
	{
		std::cout << ' ' << deqstack.top();
		deqstack.pop();
	}
	std::cout << std::endl;
	std::cout << "Empty: " << std::boolalpha << deqstack.empty() << std::endl;
	std::cout << "Size: " <<  deqstack.size() << std::endl;
}

template <class T_STACK>
void	cmp(const T_STACK &lhs, const T_STACK &rhs)
{
	static int i = 0;

	std::cout << " [" << i++ << "] "  << std::endl;
	std::cout << "equal: " << std::boolalpha << (lhs == rhs) << " | not equal: " << std::boolalpha << (lhs != rhs) << std::endl;
	std::cout << "lhs <  rhs: " << std::boolalpha <<  (lhs <  rhs) << " | lhs <= rhs: " << std::boolalpha <<  (lhs <= rhs) << std::endl;
	std::cout << "lhs >  rhs: " << std::boolalpha <<  (lhs >  rhs) << " | lhs >= rhs: " <<  std::boolalpha <<  (lhs >= rhs) << std::endl;
}

void	srelational_operators() {
	std::list<int> mylist;
	mylist.push_back(21);
	mylist.push_back(42);
	mylist.push_back(1337);
	mylist.push_back(19);
	mylist.push_back(0);
	mylist.push_back(183792);

	NAMESPACE::stack<int,std::list<int> >	stck(mylist);
	NAMESPACE::stack<int,std::list<int> >	stck2(mylist);

	cmp(stck, stck);
	cmp(stck, stck2);

	stck2.push(60);
	stck2.push(61);
	stck2.push(62);

	cmp(stck, stck2);
	cmp(stck2, stck);

	stck.push(42);

	cmp(stck, stck2);
	cmp(stck2, stck);

	stck.push(100);

	cmp(stck, stck2);
	cmp(stck2, stck);
}
