/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:42:01 by ktashbae          #+#    #+#             */
/*   Updated: 2023/01/02 16:14:22 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "enable_if.hpp"
#include "iterator.hpp"

namespace ft {

/**
 * Iterator adaptor that reverses the direction of a given iterator. 
 * In other words, when provided with a bidirectional iterator, 
 * std::reverse_iterator produces a new iterator that moves from 
 * the end to the beginning of the sequence defined by the underlying 
 * bidirectional iterator.
 * src: https://www.enseignement.polytechnique.fr/informatique/INF478/docs/Cpp/en/cpp/iterator/reverse_iterator.html#:~:text=std%3A%3Areverse_iterator%20is%20an,by%20the%20underlying%20bidirectional%20iterator.
 */
	template <class Iterator>
	class reverse_iterator
	{
		public:
			/** Member types */
			typedef Iterator												iterator_type;
			typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename iterator_traits<Iterator>::value_type			value_type;
			typedef typename iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename iterator_traits<Iterator>::pointer				pointer;
			typedef typename iterator_traits<Iterator>::reference			reference;

			reverse_iterator(void) :					_it()							{};
			reverse_iterator(iterator_type it) :		_it(it)							{};
			/** copy / type-cast constructor */
			template<class Iter>
			reverse_iterator(const reverse_iterator<Iter>& other): _it(other.base())	{};
			~reverse_iterator(void)														{};

			iterator_type	base() const  {
				return _it;
			};

			/** Assignment operators */
			template<class Iter>
			reverse_iterator& operator=(const reverse_iterator<Iter>& other)			{
				this->_it =  other.base();
				return *this;
			};

			reverse_iterator&	operator+=(difference_type n)							{
				this->_it -= n;
				return *this;
			};

			reverse_iterator&	operator-=(difference_type n)							{
				this->_it += n;
				return *this;
			};

			/** Arithmetic operators */
			reverse_iterator	operator+(difference_type n) const						{
				return reverse_iterator(this->_it - n);
			};

			reverse_iterator	operator-(difference_type n) const						{
				return reverse_iterator(this->_it + n);
			};

			/** Increment and Decrement operators */
			reverse_iterator&		operator++()										{
				this->_it -= 1;
				return *this;
			};

			reverse_iterator&		operator--()										{
				this->_it += 1;
				return *this;
			};

			reverse_iterator		operator++(int)										{
				reverse_iterator	tmp(*this);
				this->_it -= 1;
				return tmp;
			};

			reverse_iterator		operator--(int)										{
				reverse_iterator	tmp(*this);
				this->_it += 1;
				return tmp;
			};

			/** Dereference operators */
			/** with iterator alsways end - 1 */
			reference		operator*() const											{
				iterator_type	tmp = this->_it;
				return *(--tmp);
			};

			pointer			operator->() const											{
				return &(operator*());
			};

			reference		operator[] (difference_type n) const						{
				return this->base()[-n-1];
			};
/**
 * The fundamental relation between a reverse iterator and its corresponding iterator i is established by the identity: 
 * &*(reverse_iterator(i)) == &*(i - 1);
 */
		private:
			Iterator	_it;
	};

	// Non-member overloads ===================================================//
	/** Relational operators */
	template<class Iter1, class Iter2>
	bool	operator==(const reverse_iterator<Iter1>& lhs, \
						const reverse_iterator<Iter2>& rhs)								{
		return lhs.base() == rhs.base();
	};

	template<class Iter1, class Iter2>
	bool	operator!=(const reverse_iterator<Iter1>& lhs, \
						const reverse_iterator<Iter2>& rhs)								{
		return lhs.base() != rhs.base();
	};

	template<class Iter1, class Iter2>
	bool	operator<(const reverse_iterator<Iter1>& lhs, \
						const reverse_iterator<Iter2>& rhs)								{
		return lhs.base() > rhs.base();

	};

	template<class Iter1, class Iter2>
	bool	operator>(const reverse_iterator<Iter1>& lhs, \
						const reverse_iterator<Iter2>& rhs)								{
		return lhs.base() < rhs.base();

	};

	template<class Iter1, class Iter2>
	bool	operator<=(const reverse_iterator<Iter1>& lhs, \
						const reverse_iterator<Iter2>& rhs)								{
		return lhs.base() >= rhs.base();

	};

	template<class Iter1, class Iter2>
	bool	operator>=(const reverse_iterator<Iter1>& lhs, \
						const reverse_iterator<Iter2>& rhs)								{
		return lhs.base() <= rhs.base();

	};

	template <class Iterator>
	reverse_iterator<Iterator>	operator+(typename reverse_iterator<Iterator>::difference_type n, \
											const reverse_iterator<Iterator>& rev_it)	{
		return rev_it + n;
	};

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type	operator-(const reverse_iterator<Iterator>& lhs, \
											const reverse_iterator<Iterator>& rhs)		{
		return rhs.base() - lhs.base();
	};

}; // end of namespace ft

#endif