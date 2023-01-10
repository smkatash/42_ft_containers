#ifndef RBTREE_HPP
# define RBTREE_HPP
# define RED 0
# define BLACK 1
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

	Node(): _value(0), _parent(nullptr), _left(nullptr), _right(nullptr), _color(RED), _cnt(0) {}

	explicit Node(T const& value, Node *parent, std::size_t size):	\
		_value(value), _parent(parent), _left(nullptr), _right(nullptr), _color(RED), _cnt(size) {}

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
	class RedBlackTree {
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
			explicit RedBlackTree(const value_compare& comp, const allocator_type& alloc): _nil(nilNode()),
																					_comp(comp), \
																					_alloc(alloc), \
																					_size(0) {
					_nil->_color = BLACK;
					_root = _nil;
			}
			
			RedBlackTree(RedBlackTree const& curr): _nil(nilNode()), \
										_root(_nil), \
										_comp(curr._comp), \
										_alloc(curr._alloc) { insert(curr.begin(), curr.end());	}

			RedBlackTree& operator=(const RedBlackTree& tree) {
				if (this != &tree) {
					clear(_root);
					_comp = tree._comp;
					_alloc = tree._alloc;
					insert(tree.begin(), tree.end());
				}
				return *this;
			}

			~RedBlackTree() {
				clear(_root);
				freeNode(_nil);
			}

			node	*nilNode() {
				node	*new_node = _alloc_node.allocate(1);
				new_node->_parent = nullptr;
				new_node->_left = _nil;
				new_node->_right = _nil;
				new_node->_color = BLACK;
				new_node->_cnt = 0;
				return new_node;
			}

			ft::pair<iterator, bool> insert(const value_type& val) {
				if (_root == _nil) {
					_root = newNode(val, _nil, 2);
					_root->_color = BLACK;
					// balanced tree ->true, iterator (node *_current)
					return ft::make_pair(iterator(_root), true);
				}
				node	*current = _root;
				node	*parent = _nil;
				while (current != _nil) {
					parent = current;
					if (_comp(val, current->_value))
						current = current->_left;
					else if (_comp(current->_value, val))
						current = current->_right;
					else
						// duplicate are not allowed in map
						// tree is not balanced, did not reach insertFixup
						return ft::make_pair(iterator(current), false);
				}
				current = newNode(val, parent, 1);
				if (_comp(parent->_value, val))
					parent->_right = current;
				else
					parent->_left = current;
				insertFixup(current);
				return ft::make_pair(iterator(current), true);
			}

			iterator	insert(iterator position, const value_type& val) {
				void(position);
				return insert(val).first;
			}

			template<class InputIterator>
			void	insert(InputIterator first, InputIterator last) {
				while (first != last) {
					insert(*first);
					first++;
				}
			}

			node	*search(node *x, const value_type& val) const {
				while (x != _nil) {
					if (_comp(val, x->_value))
						x = x->_left;
					else if (_comp(x->_value, val))
						x = x->_right;
					else
						return x;
				}
				return nullptr;
			}

			iterator	find(const value_type& val) const {
				node *x = search(_root, val);
				if (x != nullptr)
					return iterator(x);
				return iterator(maximum(_root));
			}

			bool			empty() const			{ return _size == 0;							}
			size_type		size() const			{ return _size;									}
			size_type		max_size() const		{ return _node_alloc.max_size();				}

			iterator	begin() {
				if (_root == _nil)
					return iterator(_nil);
				node *current = _root;
				while (current != nullptr && current->_nil)
					current = current->_left;
				return iterator(current);
			}

			const_iterator	begin() const {
				if (_root == _nil)
					return iterator(_nil);
				node *current = _root;
				while (current != nullptr && current->_nil)
					current = current->_left;
				return iterator(current);
			}

			iterator				end()				{ return iterator(maximum(_root));			}
			const_iterator			end() const			{ return iterator(maximum(_root));			}
			reverse_iterator		rbegin()			{ return reverse_iterator(end());			}
			const_reverse_iterator	rbegin() const		{ return reverse_iterator(end());			}
			reverse_iterator		rend()				{ return reverse_iterator(begin());			}
			const_reverse_iterator	rend() const		{ return reverse_iterator(begin());			}

			// TODO check if correct comparison
			node	*lower_bound(const value_type& val) const {
				node	*lower = _nil;
				node	*current = _root;
				while (current != _nil) {
					if (_comp(val, current->_value)) {
						lower = current;
						current = current->_left;
					}
					else
						current = current->_right;
				}
				return lower;
			}

			
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
			node			*_nil;
			Compare			_comp;
			allocator_type	_alloc;
			allocator_node	_alloc_node;
			size_type		_size;

			node	*newNode(value_type const& val, node *parent, std::size_t cnt) {
				node *new_node = _alloc_node.allocate(1);
				_alloc.construct((&new_node->_value), val);
				new_node->_parent = parent;
				new_node->_left = _nil;
				new_node->_right = _nil;
				new_node->_color = RED;
				new_node->_cnt = cnt;
				_size++;
				return new_node;
			}

			void freeNode(node *n) {
				_node_alloc.deallocate(n, 1); 
				_size--;
			}

			void destroyNode(node *n) {
				_alloc.destroy(&(n->_value));  
				freeNode(n);
			}

			// All the rotation operation are performed
			// about the node itself
			// Performs all the linking done when there is
			// clockwise rotation performed at node "x"
			void	rotateRight(node *x) {
				node	*y = x->_left;
				x->_left = y->_right;
				if (y->_right != _nil) {
					y->_right->_parent = x;
				}
				y->_parent = x->_parent;
				if (x->_parent == nullptr ) {
					this->_root = y;
				} else if (x->_parent->_left == x) {
					x->_parent->_left = y;
				} else {
					x->_parent->_right = y;
				}
				y->_right = x;
				x->_parent = y;
			}

			// Performs all the linking done when there is
			// anti-clockwise rotation performed at node "x"
			void	rotateLeft(node *x) {
				node	*y = x->_right;
				x->_right = y->_left;
				if (y->_left != _nil) {
					y->_left->_parent = x;
				}
				y->_parent = x->_parent;
				if (x->_parent == nullptr)
					this->_root = y;
				else if (x->_parent->_left == x) {
					x->_parent->_left = y;
				} else {
					x->_parent->_right = y;
				}
				y->_left = x;
				x->_parent = y;
			}

/**
 * @attention In the insert operation, we check the _color of the aunt to decide the appropriate case. 
 * In the delete operation, we check the _color of the sibling to decide the appropriate case.
 *  insert -> insert_fixup
 *  delete -> delete_fixup
 */
			void insertFixup(node *n) {
				node *aunt;
				while (n != _root && n->_parent->_color == RED) {
					if (n->_parent == n->_parent->_parent->_right) {
						aunt = n->_parent->_parent->_left;
						// aunt.RED -> colorflip
						if (aunt->_color == RED) {
							aunt->_color = BLACK;
							n->_parent->_parent->_color = RED;
							n = n->_parent->_parent;
						} else {
							// aunt.BLACK -> rotate
							if (n == n->_parent->_left) {
								n = n->_parent;
								rotateRight(n);
							}
							n->_parent->_color = BLACK;
							n->_parent->_parent->_color = RED;
							rotateLeft(n->_parent->_parent);
						}
					} else {
						aunt = n->_parent->_parent->_right;
						// aunt.RED -> colorflip
						if (aunt->_color == RED) {
							aunt->_color = BLACK;
							n->_parent->_parent->_color = RED;
							n = n->_parent->_parent;
						} else {
							// aunt.BLACK -> rotate
							if (n == n->_parent->_right) {
								n = n->_parent;
								rotateLeft(n);
							} else {
								n->_parent->_color = BLACK;
								n->_parent->_parent->_color = RED;
								rotateRight(n->_parent->_parent);
							}
						}
					}
					_root->_color = BLACK;
				}
			}

			void	deleteFixup(node *current) {
				node	*sibling;
				while (node != _root && current->_color == BLACK) {
					// lhs path
					if (current == current->_parent->_left) {
						sibling = current->_parent->_right;
						// deletion requires double BLACK
						if (sibling->_color == RED) {
							sibling->_color = BLACK;
							current->_parent->_color = RED;
							rotateLeft(current->_parent);
							sibling = current->_parent->_right;
						}
						if (sibling->_left->_color == BLACK && \
							sibling->_right->_color == BLACK) {
								sibling->_color = RED;
								current = current->_parent;
						} else {
							if (sibling->_right->_color == BLACK) {
								sibling->_left->_color = BLACK;
								sibling->_color = RED;
								rotateRight(sibling);
								sibling = current->_parent->_right;
							}
							sibling->_color = current->_parent->_color;
							current->_parent->_color = BLACK;
							sibling->_right->_color = BLACK;
							rotateLeft(current->_parent);
							current = _root;
						}
						// rhs path
					} else {
						sibling = current->_parent->_left;
						if (sibling->_color == RED) {
							sibling->_color = BLACK;
							current->_parent->_color = RED;
							rotateRight(current->_parent);
							sibling = current->_parent->_left;
						}
						if (sibling->_right->_color == BLACK && \
							sibling->_left->_color == BLACK) {
								sibling->_color = RED;
								current = current->_parent;
						} else {
							if (sibling->_left->_color == BLACK) {
								sibling->_right->_color = BLACK;
								sibling->_color = RED;
								rotateLeft(sibling);
								sibling = current->_parent->_left;
							}
							sibling->_color = current->_parent->_color;
							current->_parent->_color = BLACK;
							sibling->_left->_color = BLACK;
							rotateRight(current->_parent);
							current = _root;
						}
					}
				}
				current->_color = BLACK;
			}

			// switch two nodes
			void transplantNode(node *u, node *v) {
				if (u->_parent == nullptr) {
					_root = v;
				} else if (u == u->_parent->_left) {
					u->_parent->_left = v;
				} else {
					u->_parent->_right = v;
				}
				v->_parent = u->_parent;
			}

			node	*replaceNode(node *n) {
				if (!n || (!n->_left && !n->right))
					return nullptr;
				if (n->_left && n->right)
					return successor(n);
				if (n->right)
					return n->_left;
				return n->right;
			};

			node *minimum(node *n) {
				while (n->_left != _nil)
					n = n->_left;
				return n;
			}

			node *maximum(node *n) {
				while (n->_right != _nil)
					n = n->_right;
				return n;
			}

			node *successor(node *x) {
				if (x->_right != _nil)
					return minimum(x->_right);
				node *y = x->_parent;
				while (y != _nil && x == y->_right) {
					x = y;
					y = y->_parent;
				}
				return y;
			}

			node *predecessor(node *x) {
				if (x->_left != _nil)
					return maximum(x->_left);
				node *y = x->_parent;
				while (y != _nil && x == y->_left) {
					x = y;
					y = y->_parent;
				}
				return y;
			}

	};
}; // namespace ft



#endif