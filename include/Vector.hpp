/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:18:23 by ktashbae          #+#    #+#             */
/*   Updated: 2022/12/01 17:22:45 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include "utils/iterator.hpp"
#include "utils/enable_if.hpp"
#include "utils/reverse_iterator.hpp"

namespace ft
{
/**
 * class (typename) T: The type of object that is stored in the vector
 * class Allocator = new_allocator<T> : The allocator used for 
 * all internal memory management
 */
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
/**
 * The first template parameter (T). Type of the elements.
 * Only if T is guaranteed to not throw while moving, 
 * implementations can optimize to move elements 
 * instead of copying them during reallocations.
 */
		typedef T														value_type;

/**
 * The second template parameter (Alloc)
 * Type of the allocator object used to define the storage allocation model.
 * By default, the allocator class template is used, 
 * which defines the simplest memory allocation model and is value-independent.
 * Aliased as member type vector::allocator_type.
 * 
 * template <class T, class Alloc = allocator<T> >
 * class vector
 * {
 * };
 * 
 * An allocator *type* is supposed to be passed as a template argument. 
 * Not an allocator class template. So, if you need an
 * allocator for a different type from inside vector, your only choice is
 * to use the rebind member.
 * Allocator object:
 - The container keeps and uses an internal copy of this allocator.
 - Member type allocator_type is the internal allocator type used by the container, 
 	defined in vector as an alias of its second template parameter (Alloc).
 - If allocator_type is an instantiation of the default allocator (which has no state).
 */
		typedef Allocator												allocator_type;

/**
 * Reference  for the default allocator: value_type&
 */
		typedef typename allocator_type::reference						reference;
/**
 * Const Reference  for the default allocator: const value_type&
 */
		typedef typename allocator_type::const_reference				const_reference;

/**
 * Pointer for the default allocator: value_type*
 */
		typedef typename allocator_type::pointer						pointer;

/**
 * Const Pointer for the default allocator: const value_type*
 */
		typedef typename allocator_type::const_pointer					const_pointer;

/**
 * The unsigned integer type describes an object that can represent 
 * the length of any sequence that an object of template class allocator can allocate.*
 */
		typedef typename allocator_type::size_type						size_type;


		// Iterators =========================================================================//
		typedef ft::iterator<T>											iterator;
		typedef ft::iterator<const T>									const_iterator;
		typedef ft::reverse_iterator<iterator>							reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
		typedef typename iterator_traits<iterator>::difference_type		difference_type;


		// Member Functions ======================================================================//
/**
 * The explicit function specifier controls unwanted implicit type conversions. It can only be used 
 * in declarations of constructors within a class declaration.
 */
		//(1) empty container constructor (default constructor)
		explicit vector(const allocator_type& alloc = allocator_type()) :
			_alloc(alloc), _elem(NULL), _capacity(0), _size(0)		{ }
		
		// (2) fill constructor : constructs a container with n elements. Each element is a copy of val.
		// void insert (iterator position, size_type n, const value_type& val);
		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) :
			_alloc(alloc), _elem(NULL), _capacity(0), _size(0)		{
				insert(begin(), n, val);
			}
		
		// (3) range constructor : constructs a container with as many elements as the range [first,last), 
		// with each element constructed from its corresponding element in that range, in the same order.
		template <class InputIterator> 
		vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), \
			typename ft::enable_if<!ft::is_integral<InputIterator>::value::type* = nullptr) :
				_alloc(alloc), _elem(NULL), _capacity(0) {
					//to write Insert!!!!
				}
			
		
		// (4) copy constructor : constructs a container with a copy of each of the elements in x, in the same order.
		vector(const vector& x);
		//to write Assign!!!!
	
		~vector()													{
			clear();
			_alloc.deallocate(_elem, _capacity);
		};

		template<class InputIterator>
		void	assign(InputIterator first, InputIterator last, \
				typename ft::enable_if<!ft::is_integral<InputIterator>::value::type* = nullptr)	{
			size_type	n = ft::distance(first, last);
			
		};
		
		vector&	operator=(const vector& x)							{
			if (this != &x)
				assign(x.begin(), x.end());
			return *this;
		};
		

		// Member Functions ======================================================================//
		
		private:
			allocator_type	_alloc;
			value_type		*_elem;
			size_type		_capacity;
			size_type		_size;
	};
}; // end of namespace ft

#endif