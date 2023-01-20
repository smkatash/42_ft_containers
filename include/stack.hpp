/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:56:46 by kanykei           #+#    #+#             */
/*   Updated: 2023/01/20 10:57:13 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP
# include "vector.hpp"

namespace ft {
	template <class T, class Container = ft::vector<T> >
	class stack {
		public:
			typedef T				value_type;
			typedef Container		container_type;
			typedef size_t			size_type;

			explicit stack (const container_type& ctnr = container_type()): _vector(ctnr) {}

			bool				empty() const	{ return _vector.empty();			}
			size_type			size() const	{ return _vector.size();			}
			value_type&			top()			{ return _vector.back();			}
			const value_type&	top() const		{ return _vector.back();			}

			void	push(const value_type& val) { _vector.push_back(val);		}
			void	pop()						{ _vector.pop_back();			}

			friend bool operator==(stack const& lhs, stack const& rhs)				{		return lhs._vector == rhs._vector;			}
			friend bool operator!=(stack const& lhs, stack const& rhs)				{		return lhs._vector != rhs._vector;			}
			friend bool operator<(stack const& lhs, stack const& rhs)				{		return lhs._vector < rhs._vector;			}
			friend bool operator>(stack const& lhs, stack const& rhs)				{		return lhs._vector > rhs._vector;			}
			friend bool operator<=(stack const& lhs, stack const& rhs)				{		return lhs._vector <= rhs._vector;			}
			friend bool operator>= (stack const& lhs, stack const& rhs)				{		return lhs._vector >= rhs._vector;			}

		protected:
			container_type	_vector;
	};
};

#endif