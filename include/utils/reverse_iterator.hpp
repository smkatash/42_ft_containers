/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:42:01 by ktashbae          #+#    #+#             */
/*   Updated: 2023/01/17 16:23:10 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP
# include "utils.hpp"

namespace ft {
/**
 * Iterator adaptor that reverses the direction of a given iterator. 
 * In other words, when provided with a bidirectional iterator, 
 * std::reverse_iterator produces a new iterator that moves from 
 * the end to the beginning of the sequence defined by the underlying 
 * bidirectional iterator.
 * src: https://www.enseignement.polytechnique.fr/informatique/INF478/docs/Cpp/en/cpp/iterator/reverse_iterator.html#:~:text=std%3A%3Areverse_iterator%20is%20an,by%20the%20underlying%20bidirectional%20iterator.
 */
	template <class iterator>
	class reverse_iterator
	{
		public:
			/** Member types */
			typedef iterator												iterator_type;
			typedef typename iterator_traits<iterator>::iterator_category	iterator_category;
			typedef typename iterator_traits<iterator>::value_type			value_type;
			typedef typename iterator_traits<iterator>::difference_type		difference_type;
			typedef typename iterator_traits<iterator>::pointer				pointer;
			typedef typename iterator_traits<iterator>::reference			reference;

		/**
 		* The fundamental relation between a reverse iterator and its corresponding iterator i is established by the identity: 
 		* &*(reverse_iterator(i)) == &*(i - 1);
 		*/
		private:
			iterator	_it;
		
		public:
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
				_it =  other.base();
				return *this;
			};

			reverse_iterator&	operator+=(difference_type n)							{
				_it -= n;
				return *this;
			};

			reverse_iterator&	operator-=(difference_type n)							{
				_it += n;
				return *this;
			};

			/** Arithmetic operators */
			reverse_iterator	operator+(difference_type n) const						{
				return reverse_iterator(_it - n);
			};

			reverse_iterator	operator-(difference_type n) const						{
				return reverse_iterator(_it + n);
			};

			/** Increment and Decrement operators */
			reverse_iterator&		operator++()										{
				--_it;
				return *this;
			};

			reverse_iterator&		operator--()										{
				++_it;
				return *this;
			};

			reverse_iterator		operator++(int)										{
				reverse_iterator	tmp = *this;
				--_it;
				return tmp;
			};

			reverse_iterator		operator--(int)										{
				reverse_iterator	tmp = *this;
				++_it;
				return tmp;
			};

			/** Dereference operators */
			/** with iterator alsways end - 1 */
			reference		operator*() const											{
				iterator_type	tmp = _it;
				return *(--tmp);
			};

			pointer			operator->() const											{
				return &(operator*());
			};

			reference		operator[] (difference_type n) const						{
				return base()[-n-1];
			};
	};

	// Non-member overloads ===================================================//
	/** Relational operators */
	template<class Iter1, class Iter2>
	bool	operator==(const reverse_iterator<Iter1>& lhs, \
						const reverse_iterator<Iter2>& rhs)								{
		return lhs.base() == rhs.base();
	}

	template<class Iter1, class Iter2>
	bool	operator!=(const reverse_iterator<Iter1>& lhs, \
						const reverse_iterator<Iter2>& rhs)								{
		return lhs.base() != rhs.base();
	}

	template<class Iter1, class Iter2>
	bool	operator<(const reverse_iterator<Iter1>& lhs, \
						const reverse_iterator<Iter2>& rhs)								{
		return lhs.base() > rhs.base();

	}

	template<class Iter1, class Iter2>
	bool	operator>(const reverse_iterator<Iter1>& lhs, \
						const reverse_iterator<Iter2>& rhs)								{
		return lhs.base() < rhs.base();

	}

	template<class Iter1, class Iter2>
	bool	operator<=(const reverse_iterator<Iter1>& lhs, \
						const reverse_iterator<Iter2>& rhs)								{
		return lhs.base() >= rhs.base();

	}

	template<class Iter1, class Iter2>
	bool	operator>=(const reverse_iterator<Iter1>& lhs, \
						const reverse_iterator<Iter2>& rhs)								{
		return lhs.base() <= rhs.base();

	}

	template <class Iterator>
	reverse_iterator<Iterator>	operator+(typename reverse_iterator<Iterator>::difference_type n, \
											const reverse_iterator<Iterator>& rev_it)	{
		return rev_it + n;
	}

	template <class Iter1, class Iter2>
	typename reverse_iterator<Iter1>::difference_type	operator-(const reverse_iterator<Iter1>& lhs, \
											const reverse_iterator<Iter2>& rhs)		{
		return rhs.base() - lhs.base();
	}

}; // end of namespace ft

#endif