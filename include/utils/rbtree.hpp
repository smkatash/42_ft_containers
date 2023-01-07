#ifndef RBTREE_HPP
# define RBTREE_HPP
# define red 0
# define black 1
# include <memory>
# include "enable_if.hpp"
# include "iterator.hpp"
# include "reverse_iterator.hpp"
# include "bidirectional_iterator.hpp"
# include "equal.hpp"
# include "pair.hpp"

template<typename T>
struct Node {
	typedef T			value_type;
	value_type			_value;
	Node				*_parent, *_left, *_right;
	int					_color;
	std::size_t			_cnt;

	Node(): _value(0), _parent(nullptr), _left(nullptr), _right(nullptr), _color(red), _cnt(0) {}

	explicit Node(T const& value, Node *parent, std::size_t size):	\
		_value(value), _parent(parent), _left(nullptr), _right(nullptr), _color(red), _cnt(size) {}

	Node(Node const& curr): _value(curr._value), \
							_parent(curr._parent), \
							_left(curr._left), \
							_right(curr._right), \
							_color(curr._color), \
							_cnt(curr._cnt) {}
	~Node() {}

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

namespace ft {
	template <class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
	class rbtree {
		public:
			// Member Types ======================================================================//
			typedef T														mapped_type;
			typedef Compare													value_compare;
			typedef Allocator												allocator_type;
			typedef typename allocator_type::reference						reference;
			typedef typename allocator_type::const_reference				const_reference;
			typedef typename allocator_type::pointer						pointer;
			typedef typename allocator_type::const_pointer					const_pointer;
			typedef ft::bidirectionalIterator<T>							iterator;
			typedef ft::bidirectionalIterator<const T>						const_iterator;
			typedef ft::reverse_iterator<iterator>							reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
			typedef	std::size_t												size_type;
			// The rebind member allows a container to construct an allocator for some arbitrary type out of the allocator type provided as a template parameter. 
			typedef	Node<value_type>										node;
			typedef typename Alloc::template rebind <node>::other			allocator_node;

			// Member Functions ==================================================================//
			explicit rbtree(const value_compare	&comp, const allocator_type &alloc): _child(reserve()),
																					_comp(comp), \
																					_alloc(alloc), \
																					_size(0) {
					_child->_color = black;
					_root = _child;
			}
			
			rbtree(rbtree const& curr): _child(reserve()), \
										_root(_child), \
										_comp(curr._comp), \
										_alloc(curr._alloc) {
				TODO 
				insert(curr.begin(), curr.end());
			}

			node	*reserve() {
				node	*new_node = _alloc_node.allocate(1);
				new_node->_parent = nullptr;
				new_node->_left = _child;
				new_node->_right = _child;
				new_node->_color = black;
				new_node->_cnt = 0;
				return new_node;
			}
			TODO

/**
 * @brief General rules of RBTree
 * 1. Every node is Black / Red
 * 2. The root is always Black
 * 3. New inserted node is always Red
 * 4. Eevery path from to child(leaf) has the same number of Black nodes
 * 5. No path can have 2 consecutive Red nodes
 * 6. Nulls are Black
 * 
 * @brief 2 Rules to rebalance RBTree
 * !!! Black Aunt -> Rotate 
 * !!! Red Aunt -> Color flip
 * 
 * @attention After Rotation
 * Black root -> 2 Red leaves
 * 
 * @attention After Color flip
 * Red root -> 2 Black leaves
 */
		private:
			node			*_root;
			node			*_child;
			Compare			_comp;
			allocator_type	_alloc;
			allocator_node	_alloc_node;
			size_type		_size;

			node	*nnode(value_type const& val, node *parent, std::size_t cnt) {
				node *new_node = _alloc_node.allocate(1);
				_alloc.construct((&new_node->_value), val);
				new_node->_parent = parent;
				new_node->_left = left;
				new_node->_right = right;
				new_node->_color = red;
				new_node->_cnt = cnt;
				_size++;
				return new_node;
			}

			// All the rotation operation are performed
			// about the node itself
			// Performs all the linking done when there is
			// clockwise rotation performed at node "x"
			void	rotateRight(node *x) {
				node	*y = x->_left;
				x->_left = y->_right;
				if (y->_right != nullptr) {
					y->_right->_parent = x;
				}
				if (x->_parent != nullptr && x->_parent->_right == x) {
					x->_parent->_right = y;
				}
				else if (x->_parent != nullptr && x->_parent->_left == x) {
					x->_parent->_left = y;
				}
				y->_parent = x->_parent;
				y->_right = x;
				x->_parent = y;
			}

			// Performs all the linking done when there is
			// anti-clockwise rotation performed at node "x"
			void	rotateLeft(node *x) {
				node	*y = x->_right;
				x->_right = y->_left;
				if (y->_left != nullptr) {
					y->_left->_parent = x;
				}
				if (x->_parent != nullptr && x->_parent->_left == x) {
					x->_parent->_left = y;
				}
				else if (x->_parent != nullptr && x->_parent->_right == x) {
					x->_parent->_right = y;
				}
				y->_parent = x->_parent;
				y->_left = x;
				x->_parent = y;
			}

			void	colorFlip(node *x) {
				x->_color = !x->_color;
			}
/**
 * @attention In the insert operation, we check the color of the aunt to decide the appropriate case. 
 * In the delete operation, we check the color of the sibling to decide the appropriate case.
 *  insert -> rebalance
 *  delete -> delete_fixup
 */
			void rebalance(node *current) {
				while (current != _root && current->_parent->_color == red) {
					node *gparent = current->_parent->_parent;
					// path on the rhs
					if (current->_parent == gparent->_right) {
						node *aunt = gparent->_left;
						// red aunt -> colorflip: red : black : black
						if (aunt->_color == red) {
							gparent->_color = red;
							aunt->_color = black;
							current->_parent->_color = black;
							current = gparent;
						}
						// black aunt -> rotate
						// after rotation: black : red : red
						else {
							// path on lhs
							if (current == current->_parent->_left) {
								current = current->_parent;
								rotateRight(current);
							}
							current->_parent->_color = black;
							gparent->_color = red;
							rotateLeft(gparent);
						}
					}
					else {
						// path on lhs
						node *aunt = gparent->_right;
						// red aunt -> color flip
						if (aunt->_color == red) {
							gparent->_color = red;
							aunt->_color = black;
							current->_parent->_color = black;
							current = gparent;
						}
						// black aunt -> rotate
						else {
							current->_parent->_color = black;
							gparent->_color = red;
							rotateRight(gparent);
						}
					}
				}
				// root is always black
				_root->_color = black;
			}

			void	delete_fixup(node *current) {
				while (node != _root && current->_color == black) {
					// lhs path
					if (current == current->_parent->_left) {
						node	*sibling = current->_parent->_right;
						// deletion requires double black
						if (sibling->_color == red) {
							colorFlip(sibling);
							current->_parent->_color = red;
							rotateLeft(current->_parent);
							sibling = current->_parent->_right;
						}
						if (sibling->_left->_color == black && \
							sibling->_right->_color == black) {
								sibling->_color = red;
								current = current->_parent;
						} else {
							if (sibling->_right->_color == black) {
								sibling->_left->_color = black;
								sibling->_color = red;
								rotateRight(sibling);
								sibling = current->_parent->_right;
							}
							sibling->_color = current->_parent->_color;
							current->_parent->_color = black;
							sibling->_right->_color = black;
							rotateLeft(current->_parent);
							current = _root;
						}
						// rhs path
					} else {
						node *sibling = current->_parent->_left;
						if (sibling->_color == red) {
							colorFlip(sibling);
							current->_parent->_color = red;
							rotateRight(current->_parent);
							sibling = current->_parent->_left;
						}
						if (sibling->_right->_color == black && \
							sibling->_left->_color == black) {
								sibling->_color = red;
								current = current->_parent;
						} else {
							if (sibling->_left->_color == black) {
								sibling->_right->_color = black;
								sibling->_color = red;
								rotateLeft(sibling);
								sibling = current->_parent->_left;
							}
							sibling->_color = current->_parent->_color;
							current->_parent->_color = black;
							sibling->_left->_color = black;
							rotateRight(current->_parent);
							current = _root;
						}
					}
				}
				current->_color = black;
			}

		// TODO transplant etc



	};
}; // namespace ft



#endif