/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:21:50 by ktashbae          #+#    #+#             */
/*   Updated: 2023/01/04 17:38:35 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP
# include <iostream>
# include <memory>

// TODO 
template<typename T>
class BidirectionalIterator {
	public:
		/** Member types */
		typedef T												value_type;
		typedef T*												pointer;
		typedef const T*										const_pointer;
		typedef T&												reference;
		typedef const T&										const_reference;
		typedef std::ptrdiff_t									difference_type;
		typedef std::bidirectional_iterator_tag					iterator_category;
		typedef Node<value_type>								node;
		typedef Node<const value_type>							const_node;
		typedef BidirectionalIterator<T>						iterator;
		typedef BidirectionalIterator<const T>					const_iterator;

		BidirectionalIterator()			:	_current(NULL)								{}
		BidirectionalIterator(node* N)	:	_current(N)									{}
		BidirectionalIterator(BidirectionalIterator const& it)	: _current(it.base())	{}

		BidirectionalIterator& operator=(BidirectionalIterator const& it)				{
			_current = it.base();
			return *this;
		}
		
		// TODO const_iterator ???

		node	*base() const										{	return _current;					}

		reference			operator*()								{	return _current->value;				}
		const_reference		operator*() const						{	return _current->value;				}
		pointer				operator->()							{	return &_current->value;			}
		const_pointer		operator->() const						{	return &_current->value;			}
		
		// TODO  to write operators: ++(), --(), ++(int), --(int)
		
		bool	operator==(BidirectionalIterator const& it) 		{	return  _current == it._current;	}
		bool	operator!=(BidirectionalIterator const& it)			{	return  _current != it._current;	}
		bool	operator>(BidirectionalIterator const& it) 			{	return  _current > it._current;		}
		bool	operator<=(BidirectionalIterator const& it) 		{	return  _current <= it._current;	}
		bool	operator<(BidirectionalIterator const& it) 			{	return  _current < it._current;		}
		bool	operator>=(BidirectionalIterator const& it) 		{	return  _current >= it._current;	}

	private:
		node*	_current;


};

#endif