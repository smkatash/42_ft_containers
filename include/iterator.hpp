#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include "enable_if.hpp"

namespace ft {
	// Iterator_traits ===================================================//
	// src: https://www.codeproject.com/Articles/36530/An-Introduction-to-Iterator-Traits
/**
 * Returns basic information about an iterator.
 * The iterator_traits template and specialization 
 * allows algorithms to access information about a particular iterator 
 * in a uniform way. 
 */
	template <class Iterator>
	struct iterator_traits {
		typedef typename Iterator::value_type				value_type;
		typedef typename Iterator::difference_type			difference_type;
		typedef typename Iterator::iterator_category		iterator_category;
		typedef typename Iterator::pointer					pointer;
		typedef typename Iterator::reference				reference;
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
	struct iterator_traits<const T*> {
		typedef T									value_type;
		typedef ptrdiff_t							difference_type;
		typedef std::random_access_iterator_tag		iterator_category;
		typedef T*									pointer;
		typedef T&									reference;
	};
/**
 * distance() for input, forward, and bidirectional iterator
 * Input iterator tag only is used, forward and bidirectional iterator 
 * are also be in this bucket, because they inherit from InputIterator.
 */
	template<typename InputIterator>
	typename iterator_traits<InputIterator>::difference_type distance(InputIterator first, InputIterator last, \
	typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = nullptr)
	{
		typename iterator_traits<InputIterator>::difference_type n = 0;
		while (first != last) {
			++first;
			++n;
		};
		return n;
	}

	// Iterators ===================================================//

	template <class T>
	class iterator {
		public:
			typedef T									value_type;
			typedef ptrdiff_t							difference_type;
			typedef std::random_access_iterator_tag		iterator_category;
			typedef T*									pointer;
			typedef const T*							const_pointer;
			typedef T&									reference;
			typedef const T&							const_reference;
			typedef iterator <const T>					const_iterator;

			iterator(void) : 					_it()				{};
			iterator(pointer it) : 				_it(it)				{};
			iterator(const iterator& other) : 	_it(other._it)		{};
			~iterator(void)											{};

			pointer	base() const {
				return _it;
			};

			/** Assignment operators */
			iterator		operator=(const iterator& other)		{
				this->_it = other.base();
				return *this;
			};

			iterator&		operator+=(difference_type n)			{
				this->_it += n;
				return *this;
			};

			iterator&		operator-=(difference_type n)			{
				this->_it -= n;
				return *this;
			};

			/** Arithmetic operators */
			iterator		operator+(difference_type n) const		{
				return iterator(base() + n);
			};

			iterator		operator-(difference_type n) const		{
				return iterator(base() - n);
			};

			/** Increment and Decrement operators */
			iterator&		operator++()							{
				this->_it += 1;
				return *this;
			};

			iterator&		operator--()							{
				this->_it -= 1;
				return *this;
			};

			iterator		operator++(int)							{
				iterator	tmp(*this);
				this->_it += 1;
				return tmp;
			};

			iterator		operator--(int)							{
				iterator	tmp(*this);
				this->_it -= 1;
				return tmp;
			};

			/** Dereference operators */
			reference		operator*()								{
				return *(this->_it);
			};

			const_reference	operator*() const 						{
				return *(this->_it);
			};

			/** Pointer operators */
			pointer			operator->()							{
				return &(operator*());
			}

			const_pointer	operator->() const						{
				return &(operator*());
			}

			/** Array Index Operators */
			reference		operator[] (difference_type n)			{
				return base()[n];
			};

			const_reference	operator[] (difference_type n) const	{
				return base()[n];
			};

			/** Const Iterator */
			operator		const_iterator () const					{
				return const_iterator(this->_it);
			};

		private:
			pointer	_it;
	};
}; // end of namespace ft

#endif