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
 * class Alloc = new_allocator<T> : The allocator used for 
 * all internal memory management
 */
	template <class T, class Alloc = std::allocator<T> >
	class vector {
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
 * Alloc object:
 - The container keeps and uses an internal copy of this allocator.
 - Member type allocator_type is the internal allocator type used by the container, 
 	defined in vector as an alias of its second template parameter (Alloc).
 - If allocator_type is an instantiation of the default allocator (which has no state).
 */
		typedef Alloc													allocator_type;

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


		// Iterators [random access iterator] ====================================================//
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
		
		// Iterators  ===================================================================================//

		iterator				begin() 			{ return iterator(_elem);			 		};
		const_iterator			begin() const 		{ return const_iterator(_elem);				};
		iterator				end() 				{ return iterator(_elem + _size);			};
		const_iterator			end() const 		{ return const_iterator(_elem + _size);		};
		reverse_iterator		rbegin()			{ return reverse_iterator(end());			};
		const_reverse_iterator	rbegin() const		{ return const_reverse_iterator(end());		};
		reverse_iterator		rend()				{ return reverse_iterator(begin());			};
		const_reverse_iterator	rend() const		{ return const_reverse_iterator(begin());	};

		// (1) single element
		iterator	insert(iterator position, const value_type& val) 			{
			size_type	i = position - begin();

			insert(position, 1, val);
			return begin() + i;
		}
		// (2) fill
		void 		insert(iterator position, size_type n, const value_type& val) {
			size_type	i = position - begin();

			if (_size + n > _capacity)
				reserve(_new_capacity(_size + n));
			for (size_type)

		// (3) range
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last) {

		}
			
		}

		// Capacity  =====================================================================================//
		size_type	size() 		const	{ return _size;					};
		size_type	max_size() 	const	{ return _alloc.max_size();		};
		size_type	capacity() 	const	{ return _capacity;				};
		bool		empty()		const	{ return _size == 0;			};
/**
 * class length_error : defines a type of object to be thrown as exception. 
 * It reports errors that result from attempts to exceed implementation defined 
 * length limits for some object.
 */		
		void	reserve(size_type n) 	{
			if (n <= _capacity) return ;
			if (n > max_size())
				throw std::length_error("resize failed");
			T	*new_vector = _alloc.allocate(n);
			for (size_type i = 0; i < _size; i++) {
				_alloc.construct(&new_vector[i], _elem[i]);
				_alloc.destroy(&_elem[i]);
			}
			_alloc.deallocate(_elem, _capacity);
			_elem = new_vector;
			_capacity = n;
		}

		// Private Member Functions ======================================================================//
		
		private:
			allocator_type	_alloc;
			value_type		*_elem;
			size_type		_capacity;
			size_type		_size;
			size_type		_new_capacity(size_type size) {
				size_type	n;

				n = 1;
				while (size > n)
					n *= 2;
				return n;
			}
	};
}; // end of namespace ft

#endif