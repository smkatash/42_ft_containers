/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:41:51 by ktashbae          #+#    #+#             */
/*   Updated: 2023/01/02 15:30:17 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP
# define EQUAL_HPP

namespace ft {

	// Equality comparison ===================================//
	template <class InputIterator1, class InputIterator2>
/**
 * The range used is [first1,last1), which contains 
 * all the elements between first1 and last1, including 
 * the element pointed by first1 but not the element pointed by last1.
 * first2 initial position of the second sequence. 
 * The comparison includes up to as many elements of this sequence 
 * as those in the range [first1,last1].
 *  src: https://www.enseignement.polytechnique.fr/informatique/INF478/docs/Cpp/en/cpp/algorithm/equal.html
 */
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		for (; first1 != last1; ++first1, ++first2) {
			if (!(*first1 == *first2))
				return false;
		}
		return true;
	};

	/** Predicate*/
	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
	{
		for (; first1 != last1; ++first1, ++first2) {
			if (!pred(*first1 == *first2))
				return false;
		}
		return true;
	};

	// Lexicographical comparison ===========================//
/**
 *  Compare sequentially the elements that have the same position 
 * in both ranges against each other until one element is not equivalent to the other.
 * The result of comparing these first non-matching elements is the 
 * result of the lexicographical comparison.
 * Considered equivalent if (!(a<b) && !(b<a)) or if (!comp(a,b) && !comp(b,a)),
 * true if the range [first1,last1) compares lexicographically less than the range [first2,last2).
 */
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, \
									InputIterator2 first2, InputIterator2 last2)
	{
		for ( ; (first1 != last1) && (first2 != last2); ++first1, ++first2) {
			if (first2 == last2 || *first2 < *first1) 
				return false;
			else if (*first1 < *first2)
				return true;
		}
		return (first2 != last2);
	};

/**
 * Binary function that accepts two arguments of the types pointed by the iterators,
 * and returns a value convertible to bool. The value returned indicates whether 
 * the first argument is considered to go before the second in the specific strict 
 * weak ordering it defines.
 */
	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, \
								InputIterator2 first2, InputIterator2 last2, Compare comp)
	{
		for ( ; (first1 != last1) && (first2 != last2); ++first1, ++first2) {
			if (comp(*first1, *first2)) 
				return true;
			if (comp(*first2, *first1))
				return false;
		}
		return (first2 != last2);
	};
}; // end of namespace ft

#endif