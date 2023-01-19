/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:50:14 by kanykei           #+#    #+#             */
/*   Updated: 2023/01/19 17:15:52 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP
# include "./utils/utils.hpp"
# include "./utils/rbtree.hpp"

namespace ft {
	template<class Key, class T, class Compare = std::less<Key>, \
			class Allocator = std::allocator<ft::pair<const Key, T> > >
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
		// Private Member Functions ======================================================================//
		private:
			typedef RedBlackTree<value_type, value_compare, allocator_type>	rbtree;
			rbtree															_tree;
			key_compare														_comp;
			allocator_type													_alloc;
			void inorder() 									{	_tree.inorder(_tree.get_root());			}
			value_type	get_type(const key_type& k) const	{	return ft::make_pair(k, mapped_type());		}

		public:
			typedef typename rbtree::iterator								iterator;
			typedef typename rbtree::const_iterator							const_iterator;
			typedef ft::reverse_iterator<iterator>							reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
			typedef typename iterator_traits<iterator>::difference_type		difference_type;
			typedef	std::size_t												size_type;
			typedef	Node<value_type>										node_type;

		// Member Functions ============================================================//
		public:
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
			map(const map& x): _tree(x._tree), _comp(x._comp), _alloc(x._alloc) {}
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

	// Iterators  ===================================================================================//
			iterator				begin() 				{	return _tree.begin();				 			}
			const_iterator			begin() const 			{	return _tree.begin();							}
			iterator				end() 					{	return _tree.end();								}
			const_iterator			end() const 			{	return _tree.end();								}
			reverse_iterator		rbegin()				{	return _tree.rbegin();							}
			const_reverse_iterator	rbegin() const			{	return _tree.rbegin();							}
			reverse_iterator		rend()					{	return _tree.rend();							}
			const_reverse_iterator	rend() const			{	return _tree.rend();							}
		
			void	clear()									{	_tree.clear(_tree.get_root());					}
			void	debug()									{	this->inorder();										}
	/**
	 * Searches the container for elements with a key equivalent to k and returns the 
	 * number of matches. Because all elements in a map container are unique, 
	 * the function can only return 1 (if the element is found) or zero (otherwise).
	 */
			size_type count(const key_type& k) const {
				return _tree.search(_tree.get_root(), get_type(k)) ? 1 : 0;
			}

			bool empty() const								{	return _tree.empty();							}
			size_type max_size() const						{	return _tree.max_size();						}
			size_type size() const							{	return _tree.size();							}

			ft::pair<iterator,iterator> equal_range(const key_type& k) {
				return ft::make_pair(lower_bound(k), upper_bound(k));
			}
			ft::pair<const_iterator,const_iterator> equal_range(const key_type& k) const {
				return ft::make_pair(lower_bound(k), upper_bound(k));
			}

			iterator lower_bound(key_type const& k)			{	return _tree.lower_bound(get_type(k));			}
			iterator lower_bound(key_type const& k) const	{	return _tree.lower_bound(get_type(k));			}
			iterator upper_bound(key_type const& k)			{	return _tree.upper_bound(get_type(k));			}
			iterator upper_bound(key_type const& k) const	{	return _tree.upper_bound(get_type(k));			}

			void erase(iterator position)					{	_tree.erase(position.base());					}
			size_type erase(const key_type& k)				{	return _tree.erase(get_type(k));				}
			void erase(iterator first, iterator last)		{	_tree.erase(first, last);						}

			iterator find(const key_type& k)				{	return _tree.find(get_type(k));					}
			const_iterator find(const key_type& k) const	{	return _tree.find(get_type(k));					}

			mapped_type& operator[] (const key_type& k)		{
				return (*(insert(ft::make_pair( k, mapped_type())).first)).second;
			}

			ft::pair<iterator,bool> insert(const value_type& val)		{	
				return _tree.insert(val);					}
	
			iterator insert(iterator position, const value_type& val)	{	return _tree.insert(position, val);		}
			
			template <class InputIterator>
			void insert(InputIterator first, InputIterator last)		{	_tree.insert(first, last);			}

			allocator_type	get_allocator() const			{	return _tree.get_allocator();							}

			key_compare key_comp() const					{	return _comp;									}
			value_compare value_comp() const				{	return value_compare(_comp);					}

			void swap(map& m)								{	_tree.swap(m._tree);							}
	};
	// Non-Member Functions ======================================================================//
			template <class T, class Alloc>
			bool operator==(const map<T,Alloc>& lhs, const map<T,Alloc>& rhs)	{
				if (lhs.size() != rhs.size())
					return false;
				return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
			}

			template <class T, class Alloc>
			bool operator!=(const map<T,Alloc>& lhs, const map<T,Alloc>& rhs)	{
				return !(lhs == rhs);
			}

			template <class T, class Alloc>
			bool operator<(const map<T,Alloc>& lhs, const map<T,Alloc>& rhs)	{
				return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
			}

			template <class T, class Alloc>
			bool operator>(const map<T,Alloc>& lhs, const map<T,Alloc>& rhs)	{
				return rhs < lhs;
			}

			template <class T, class Alloc>
			bool operator<=( const map<T,Alloc>& lhs, const map<T,Alloc>& rhs)	{
				return !(rhs < lhs);
			}

			template <class T, class Alloc>
			bool operator>=(const map<T,Alloc>& lhs, const map<T,Alloc>& rhs)	{
				return !(lhs < rhs);
			}

			template <class T, class Alloc>
			void swap (map<T,Alloc>& x, map<T,Alloc>& y)						{
				x.swap(y);
			}
};

#endif