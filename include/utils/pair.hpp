/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:41:57 by ktashbae          #+#    #+#             */
/*   Updated: 2023/01/21 09:37:56 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
	// Class template: pair =================================//
	template<class T1, class T2>
	class pair
	{
		public:
			/** Member types */
			typedef T1 		first_type;
			typedef T2 		second_type;

			/** Member objects */
			first_type		first;
			second_type		second;

			/** Member functions */
			pair(void): first(), second()				{}

			pair(const first_type& x, const second_type& y): \
				first(x), second(y)						{}

			template<class U1, class U2>
			pair(const pair<U1, U2>& p): \
				first(p.first), second(p.second)		{}

			~pair(void)									{}

			/** Assignment operator */
			pair&	operator=(pair const& pr)
			{
				if (this != &pr)
				{
					first = pr.first;
					second = pr.second;
				}
				return *this;
			}
	};
	
	// Function template: make pair ==========================//
	template <class T1, class T2>
	pair<T1,T2> make_pair (T1 x, T2 y)					{
		return pair<T1, T2>(x, y);
	}

	// Non-member functions: comparison =====================//

/** src: https://en.cppreference.com/w/cpp/utility/pair/operator_cmp
 * 1) true if both lhs.first == rhs.first and lhs.second == rhs.second, otherwise false
 * 2) !(lhs == rhs)
 * 3) If lhs.first<rhs.first, returns true. Otherwise, if rhs.first<lhs.first, returns false. 
 * Otherwise, if lhs.second<rhs.second, returns true. Otherwise, returns false.
 * 4) !(rhs < lhs)
 * 5) rhs < lhs
 * 6) !(lhs < rhs)
 */
	template <class T1, class T2>
	bool	operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)	{
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}

	template <class T1, class T2>
	bool	operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)	{
		return !(lhs == rhs);
	}

/**
 * Compares the first elements and only if they are equivalent,
 * compares the second elements.
 */
	template <class T1, class T2>
	bool	operator<(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)		{
		return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
	}

	template <class T1, class T2>
	bool	operator>(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)		{
		return lhs.first > rhs.first || (!(rhs.first > lhs.first) && lhs.second > rhs.second);
	}

	template<class T1, class T2>
	bool operator<=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)		{
		return !(rhs < lhs);
	}

	template< class T1, class T2 >
	bool operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)			{
		return !(lhs < rhs);
	}
}; // end of namespace ft

#endif