/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:50:14 by kanykei           #+#    #+#             */
/*   Updated: 2023/01/03 15:19:10 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP
# include <memory>
# include "utils/enable_if.hpp"
# include "utils/iterator.hpp"
# include "utils/reverse_iterator.hpp"
# include "utils/equal.hpp"
# include "utils/pair.hpp"
// TODO
# include "utils/rbtree.hpp"

namespace ft {
	template<class Key, class T, class Compare = std::less<Key>, \
			class Allocator = std::allocator<std::pair<const Key, T> > >
	class map {
		public:
			// Member Types ======================================================================//
			typedef Key														key_type;
			typedef T														mapped_type;
			typedef ft::pair<const Key, T>									value_type;
			typedef Compare													key_compare;
			typedef Allocator												allocator_type;
			typedef typename allocator_type::reference						reference;
			typedef typename allocator_type::const_reference				const_reference;
			typedef typename allocator_type::pointer						pointer;
			typedef typename allocator_type::const_pointer					const_pointer;
			typedef typename rbtree::iterator								iterator;
			typedef typename rbtree::const_iterator							const_iterator;
			typedef ft::reverse_iterator<iterator>							reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
			typedef typename iterator_traits<iterator>::difference_type		difference_type;
			typedef	size_t													size_type;
			typedef	node<value_type>										node_type;
			// *** Member Class ***
			class	value_compare {
				friend class map;
				protected:
					key_compare		comp;
					// constructed with map's comparison object
					value_compare(key_compare c) : comp(c) {}
								public:
					typedef bool 			result_type;
					typedef value_type 		first_argument_type;
					typedef value_type 		second_argument_type;
					bool	operator() (const value_type& x, const value_type& y) const {
						return comp(x.first, y.first);
					}
			};
		private:
			typedef rbtree<value_type, value_compare, allocator_type>	rbtree;
			rbtree														_tree;
			key_compare													_comp;
			allocator_type												_alloc;

		// Member Functions ============================================================//
/**
 * (1) empty container constructor (default constructor).
 * Constructs an empty container, with no elements.
 */
		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):	_tree(comp, alloc),
																												_comp(comp),
																												_alloc(alloc) {}
/**
 * (2) range constructor. Constructs a container with as many elements as the range [first,last),
 * with each element constructed from its corresponding element in that range.
 */
	template <class InputIterator>
	map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): \
		_tree(comp, alloc), _comp(comp) {
			_tree.insert(first, last);
	}
/**
 * (3) copy constructor. Constructs a container with a copy of each of the elements in x.
 */
	map (const map& x): _tree(x._tree), _comp(x._comp), _alloc(x._alloc) {}
/**
 * assignment operator. Copies all the elements from x into the container, changing its size accordingly.
 * The container preserves its current allocator, which is used to allocate additional storage if needed.
 */
	map& operator=(const map& x) {
		if (this != &x) {
			_tree = x._tree;
			_comp = x._comp;
			_alloc = x._alloc;
		}
		return *this;
	}
/**
 * Destructor
 */
	virtual ~map() {};

	};
};

#endif