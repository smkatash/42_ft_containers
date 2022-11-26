#ifndef ENABLE_IF
# define ENABLE_IF

namespace ft
{
	template <bool value, class T = void>
	struct enable_if 			{ };

	template<class T>
	struct enable_if<true, T>	{ typedef T type; };

	// src: https://en.cppreference.com/w/cpp/types/integral_constant
/**
* This template is designed to provide compile-time constants as types.
* Member types && Member Constants
*/
	template <class T, T v>
	struct integral_constant
	{
		static const T	value = v;
		T				value_type;
		typedef	integral_constant<T, v> type;
	};

/**
* Specializations for integral_constant
* Two typedefs for the common case where T is bool are provided:
*/
	typedef integral_constant<bool, true>	true_type;
	typedef integral_constant<bool, false>	false_type;

/**
* False type when enabling undefined typename for std
*/
	template <class T>
	struct is_integral : public false_type							{};

/**
* Specialization for typenames
*/
	template <class T> 
	struct is_integral<const T> : public is_integral<T>				{};
	
	template <class T> 
	struct is_integral<volatile const T>	:	public is_integral<T>	{};
	
	template <class T> 
	struct is_integral<volatile T>			:	public is_integral<T>	{};


/**
* Specialization for integral types (represent integer numbers. ):
* char , signed char , unsigned char -8 bits. short int , signed short int , 
* and unsigned short int -16 bits. int , signed int , and unsigned int -32 bits.
*/
	template <> 
	struct is_integral<unsigned char>		:	public true_type		{};
	
	template <> 
	struct is_integral<unsigned short>		:	public true_type		{};
	
	template <> 
	struct is_integral<unsigned int>		:	public true_type		{};
	
	template <> 
	struct is_integral<unsigned long>		:	public true_type		{};
	
	template <> 
	struct is_integral<unsigned long long> 	:	public true_type		{};
	
	template <> 
	struct is_integral<signed char>			:	public true_type		{};
	
	template <> 
	struct is_integral<short>				:	public true_type		{};
	
	template <> 
	struct is_integral<int>					:	public true_type		{};
	
	template <> 
	struct is_integral<long>				:	public true_type		{};
	
	template <> 
	struct is_integral<long long>			:	public true_type		{};
	
	template <> 
	struct is_integral<char>				:	public true_type		{};
	
	template <> 
	struct is_integral<bool>				:	public true_type		{};
}; // namespace ft

#endif
