#include <iostream>
#include <stdexcept>

void gotoN_impl(std::integral_constant<int,0>::type)
{
	std::cout << "GoTo 0" << '\n';
}

void gotoN_impl(std::integral_constant<int,1>::type)
{
	std::cout << "GoTo 1" << '\n';
}

void gotoN_impl(std::integral_constant<int,2>::type)
{
	std::cout << "GoTo 2" << '\n';
}

void gotoN_impl(std::integral_constant<int,3>::type)
{
	std::cout << "GoTo 3" << '\n';
} 

template<int N>
void gotoN()
{
	gotoN_impl(typename std::integral_constant<int, N>::type());
}


// template <class T, T v>
// struct integral_constant {
//   static constexpr T value = v;
//   typedef T value_type;
//   typedef integral_constant<T,v> type;
//   constexpr operator T() { return v; }
// };


//compile with -std=c++11 for constexpr auto

/**
 * This template is designed to provide compile-time constants as types.
 * It is used by several parts of the standard library as the base class 
 * for trait types, especially in their bool variant: see true_type and false_type.
 */

int main()
{
	gotoN<0>();
	gotoN<1>();
	gotoN<2>();
	gotoN<3>();

	constexpr auto x = 2;

	gotoN<x<4?x:3>(); // with a ternary operator
}