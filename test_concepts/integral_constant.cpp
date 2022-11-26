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


int main()
{
	gotoN<0>();
	gotoN<1>();
	gotoN<2>();
	gotoN<3>();

	constexpr auto x = 99;

	gotoN<x<4?x:3>(); // with a ternary operator
}