/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:21:50 by ktashbae          #+#    #+#             */
/*   Updated: 2023/01/07 12:00:34 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP
# include <iostream>
# include <memory>
# include "rbtree.hpp"

// TODO 
namespace ft {
	template<typename T>
	class bidirectionalIterator {
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
		typedef bidirectionalIterator<T>						iterator;
		typedef bidirectionalIterator<const T>					const_iterator;

		bidirectionalIterator()			:	_current(NULL)								{}
		bidirectionalIterator(node* N)	:	_current(N)									{}
		bidirectionalIterator(bidirectionalIterator const& it)	: _current(it.base())	{}

		bidirectionalIterator& operator=(bidirectionalIterator const& it)				{
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
		
		bool	operator==(bidirectionalIterator const& it) 		{	return  _current == it._current;	}
		bool	operator!=(bidirectionalIterator const& it)			{	return  _current != it._current;	}
		bool	operator>(bidirectionalIterator const& it) 			{	return  _current > it._current;		}
		bool	operator<=(bidirectionalIterator const& it) 		{	return  _current <= it._current;	}
		bool	operator<(bidirectionalIterator const& it) 			{	return  _current < it._current;		}
		bool	operator>=(bidirectionalIterator const& it) 		{	return  _current >= it._current;	}

	private:
		node*	_current;
	};
};


#endif