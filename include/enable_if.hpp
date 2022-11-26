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
* Specializations
* Two typedefs for the common case where T is bool are provided:
*/
	typedef integral_constant<bool, true>	true_type;
	typedef integral_constant<bool, false>	false_type;


}; // namespace ft

#endif
