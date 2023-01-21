#ifndef BASE_HPP
#define BASE_HPP
# include <iostream>
# include <string>
# include <cstdlib>
# include <sys/time.h>
// my STL 
# include "../../include/vector.hpp"
# include "../../include/map.hpp"
# include "../../include/stack.hpp"
// std::STL 
# include <vector>
# include <map>
# include <stack>
# define T_SIZE_TYPE typename NAMESPACE::vector<T>::size_type

// CHANGE HERE [std or ft]
# define NAMESPACE ft


void	 vconstructors();
void	viterators();
void	vmodifiers();
void	vaccess();
void	vmemory();
void	vothers();
void	vrelational_operators();

void	mconstructors();
void	miterators();
void	maccess();
void	mothers();
void	mmemory();
void	mrelational_operators();

void	sconstructors();
void	smodifiers();
void	srelational_operators();


template <typename T>
class TestClass {
	public:
		typedef T	value_type;

		TestClass(void) : value(), _verbose(false) { };
		TestClass(value_type src, const bool verbose = false) : value(src), _verbose(verbose) { };
		TestClass(TestClass const &src, const bool verbose = false) : value(src.value), _verbose(verbose) { };
		~TestClass(void) { if (this->_verbose) std::cout << "~TestClass::TestClass()" << std::endl; };
		void m(void) { std::cout << "TestClass::m called [" << this->value << "]" << std::endl; };
		void m(void) const { std::cout << "TestClass::m const called [" << this->value << "]" << std::endl; };
		TestClass &operator=(value_type src) { this->value = src; return *this; };
		TestClass &operator=(TestClass const &src) {
			if (this->_verbose || src._verbose)
				std::cout << "TestClass::operator=(TestClass) CALLED" << std::endl;
			this->value = src.value;
			return *this;
		};
		value_type	getValue(void) const { return this->value; };
		void		switchVerbose(void) { this->_verbose = !(this->_verbose); };

		operator value_type(void) const {
			return value_type(this->value);
		}
	private:
		value_type	value;
		bool		_verbose;
};

template <typename T>
std::ostream	&operator<<(std::ostream &o, TestClass<T> const &bar) {
	o << bar.getValue();
	return o;
}
// --- End of class TestClass

template <typename T>
T	inc(T it, int n)
{
	while (n-- > 0)
		++it;
	return (it);
}

template <typename T>
T	dec(T it, int n)
{
	while (n-- > 0)
		--it;
	return (it);
}

#endif