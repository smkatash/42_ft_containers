#include <iostream>
#include <type_traits>

/*
 * Enable-if
 * It is used to allow function overloading based on 
 * arbitrary properties of type. Relies on SFINE
 * (if invalid argument or return type is formed during 
 * instantiation of function template, the instantiation 
 * is removed instead of compilation error).
 * Often used in C++ template metaprogramming, 
 * Boost libraries, and C++ STL.
 */

template<bool>
struct EnableIf {};

//full template specialization
template<>
struct EnableIf<true> {
	using type = void;
};

template <class T>
void foo_int(T) { 
	std::cout << "T is signed" << std::endl; 
}

template <class T, class = typename EnableIf<std::is_unsigned<T>::value>::type>
void foo_unint(T) {
	std::cout << "T is unsigned" << std::endl; 
}

struct A {};

struct B : A {};

// value : true/false
template<class T, class = typename std::enable_if<std::is_base_of<A, T>::value>::type>
struct C: T {
	bool    _created = true; 
};


int main()
{
	int x = 5;
	foo_int(x);

	unsigned int y = 5;
	foo_unint(y);

	C<B> c;
	if (c._created == true)
		std::cout << "c is constructed" << std::endl;

	// Compilation error, wrong template
	// C<int> c;

	return 0;
}