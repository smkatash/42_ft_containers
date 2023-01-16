/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:21:50 by ktashbae          #+#    #+#             */
/*   Updated: 2023/01/15 13:16:33 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP
# include "utils.hpp"
# include "rbtree.hpp"

template<typename T>
struct Node {
	typedef T			value_type;
	value_type			_value;
	Node				*_parent;
	Node				*_left;
	Node				*_right;
	int					_color;
	std::size_t			_cnt;

	Node(void): _value(0), _parent(nullptr), _left(nullptr), _right(nullptr), _color(RED), _cnt(0) {}

	Node(T const& value, Node *parent, std::size_t size):	\
		_value(value), _parent(parent), _left(nullptr), _right(nullptr), _color(RED), _cnt(size) {}

	Node(Node const& curr): _value(curr._value), \
							_parent(curr._parent), \
							_left(curr._left), \
							_right(curr._right), \
							_color(curr._color), \
							_cnt(curr._cnt) {}
	~Node(void) {}

	Node& operator=(Node const& curr) {
		this->_value = curr._value;
		this->_parent = curr._parent;
		this->_left = curr._left;
		this->_right = curr._right;
		this->_color = curr._color;
		this->_cnt = curr._cnt;
		return *this;
	}
};

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

			bidirectionalIterator(void)			:	_current(nullptr)							{}
			bidirectionalIterator(node* N)		:	_current(N)									{}
			bidirectionalIterator(bidirectionalIterator const& it)	: _current(it.base())		{}

			bidirectionalIterator& operator=(bidirectionalIterator const& it)					{
				_current = it.base();
				return *this;
			}


			node	*base() const										{	return _current;					}
			operator			const_iterator() const					{	return const_iterator(reinterpret_cast<const_node *>(_current));	}
			reference			operator*()								{	return _current->_value;				}
			const_reference		operator*() const						{	return _current->_value;				}
			pointer				operator->()							{	return &_current->_value;			}
			const_pointer		operator->() const						{	return &_current->_value;			}
			
			bidirectionalIterator& operator++(void)	{
				if (_current->_cnt) {
					if (_current && _current->_right && _current->_right->_cnt) {
						_current = _current->_right;
						while (_current && _current->_left && _current->_left->_cnt) {
							_current = _current->_left;
						}
					} else {
						node	*temp = _current;
						_current = _current->_parent;
						while (_current && _current->_cnt && _current->_right == temp) {
							temp = _current;
							_current = _current->_parent;
						}
					}
				}
				return *this;
			}

			bidirectionalIterator& operator--(void)	{
				if (_current->_cnt > 0) {
					if (_current->_left && _current->_left->_cnt) {
						_current = _current->_left;
						while (_current->_right && _current->_right->_cnt)
							_current = _current->_right;
					} else {
						node	*temp = _current;
						_current = _current->_parent;
						while (_current && _current->_cnt && _current->_left == temp) {
							temp = _current;
							_current = _current->_parent;
						}
					}
				} else {
					while (_current->_parent->_cnt)
						_current = _current->_parent;
					while (_current->_right->_cnt)
						_current = _current->_right;
				}
				return *this;
			}
			
			bidirectionalIterator	operator++(int)						{
				bidirectionalIterator	it(*this);
				operator++();
				return it;
			}

			bidirectionalIterator	operator--(int)						{
				bidirectionalIterator	it(*this);
				operator--();
				return it;
			}

			bool	operator==(bidirectionalIterator const& it) 		{	return  _current == it._current;	}
			bool	operator!=(bidirectionalIterator const& it)			{	return  _current != it._current;	}
			bool	operator>(bidirectionalIterator const& it) 			{	return  _current > it._current;		}
			bool	operator<=(bidirectionalIterator const& it) 		{	return  _current <= it._current;	}
			bool	operator<(bidirectionalIterator const& it) 			{	return  _current < it._current;		}
			bool	operator>=(bidirectionalIterator const& it) 		{	return  _current >= it._current;	}

		private:
			node*	_current;
	};

#endif