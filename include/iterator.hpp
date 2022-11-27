#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include "enable_if.hpp"

namespace ft
{
	// Iterator_trait ===================================================//
	// src: https://www.codeproject.com/Articles/36530/An-Introduction-to-Iterator-Traits
	template <class T>
	struct iterator_traits {
		typedef typename T::value_type				value_type;
		typedef typename T::difference_type			difference_type;
		typedef typename T::iterator_category		iterator_category;
		typedef typename T::pointer					pointer;
		typedef typename T::reference				reference;
	};
/**
 * ptrdiff_t : Like in size_t, ptrdiff_t can safely store a pointer except 
 * for a pointer to a class function. Also, ptrdiff_t is the type of the result 
 * of an expression where one pointer is subtracted from the other (ptr1-ptr2). 
 * https://pvs-studio.com/en/blog/posts/cpp/a0050/
 */

/**
 * std::random_access_iterator_tag: Each tag is an empty type and corresponds 
 * to one of the five iterator categories:
 * Input_iterator_tag corresponds to InputIterator.
 * Output_iterator_tag corresponds to OutputIterator.
 * Forward_iterator_tag corresponds to ForwardIterator.
 * Bidirectional_iterator_tag corresponds to BidirectionalIterator.
 * Random_access_iterator_tag corresponds to RandomAccessIterator.
 */

	template <class T>
	struct iterator_traits<T*> {
		typedef T									value_type;
		typedef ptrdiff_t							difference_type;
		typedef std::random_access_iterator_tag		iterator_category;
		typedef T*									pointer;
		typedef T&									reference;
	};

	template <class T>
	struct iterator_traits< const T*> {
		typedef T									value_type;
		typedef ptrdiff_t							difference_type;
		typedef std::random_access_iterator_tag		iterator_category;
		typedef T*									pointer;
		typedef T&									reference;
	};

	template<typename InputIterator>
	typename iterator_traits<InputIterator>::difference_type distance(InputIterator first, InputIterator last, \
	typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = nullptr)
	{
		typename iterator_traits<InputIterator>::difference_type n = 0;
		while (first != last) {
			++n;
			++first;
		};
		return n;
	}
}

#endif