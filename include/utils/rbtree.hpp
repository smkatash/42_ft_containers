#ifndef RBTREE_HPP
# define RBTREE_HPP
# include "utils.hpp"
# include "bidirectional_iterator.hpp"
# define RED 0
# define BLACK 1

template <class T, class Compare = std::less<T>, class Allocator = std::allocator<T> >
class RedBlackTree {
		public:
			// Member Types ======================================================================//
			typedef T														value_type;
			typedef Compare													value_compare;
			typedef Allocator												allocator_type;
			typedef typename allocator_type::pointer						pointer;
			typedef typename allocator_type::const_pointer					const_pointer;
			typedef typename allocator_type::reference						reference;
			typedef typename allocator_type::const_reference				const_reference;
			typedef bidirectionalIterator<T>								iterator;
			typedef bidirectionalIterator<const T>							const_iterator;
			typedef ft::reverse_iterator<iterator>							reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
			typedef	std::size_t												size_type;
			typedef	Node<value_type>										node;
			// The rebind member allows a container to construct an allocator for some arbitrary type out of the allocator type provided as a template parameter. 
			typedef typename Allocator::template rebind<node>::other		allocator_node;

		private:
			node			*_root;
			node			*_nil;
			Compare			_comp;
			allocator_type	_alloc;
			allocator_node	_alloc_node;
			size_type		_size;
			// Member Functions ==================================================================//
		public:
			// !!! debugging
			void getfullNode(void) {
					std::cout << "value f " << this->_root->_value.first << " ";
					std::cout << "value s " << this->_root->_value.second << " ";
					std::cout << "root " << this->_root->_color << " ";
					std::cout << "nil " << this->_nil->_color << " ";
					std::cout << this->_size << " ";
			}

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
										_alloc(curr._alloc)		{ insert(curr.begin(), curr.end());	}

			RedBlackTree& operator=(const RedBlackTree& tree)	{
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
						return ft::make_pair(iterator(current), false);
						// duplicate are not allowed in map
						// tree is not balanced, did not reach insertFixup
				}
				current = newNode(val, parent, 1);
				if (_comp(parent->_value, val))
					parent->_right = current;
				else
					parent->_left = current;
				current->_left->_parent = current;
				current->_right->_parent = current;
				insertFixup(current);
				return ft::make_pair(iterator(current), true);
			}


			iterator	insert(iterator position, const value_type& val) {
				(void)position;
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
				if (x)
					return iterator(x);
				return iterator(maximum(_root));
			}

			bool			empty() const			{ return _size == 0;							}
			size_type		size() const			{ return _size;									}
			size_type		max_size() const		{ return _alloc_node.max_size();				}

			iterator	begin() {
				if (_root == _nil)
					return iterator(_nil);
				node *current = _root;
				while (current != nullptr && current != _nil)
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

			iterator				end()						{ return iterator(maximum(_root));			}
			const_iterator			end() const					{ return iterator(maximum(_root));			}
			reverse_iterator		rbegin()					{ return reverse_iterator(end());			}
			const_reverse_iterator	rbegin() const				{ return reverse_iterator(end());			}
			reverse_iterator		rend()						{ return reverse_iterator(begin());			}
			const_reverse_iterator	rend() const				{ return reverse_iterator(begin());			}

			allocator_type			get_allocator(void) const	{ return _alloc; 							}
			node					*get_root() const			{ return _root;								}

			// TODO check if correct comparison
			node	*lower_bound(const value_type& val) const {
				node	*lower = _nil;
				node	*current = _root;
				while (current != _nil) {
					if (!_comp(current->_value, val)) {
						lower = current;
						current = current->_left;
					}
					else
						current = current->_right;
				}
				return lower;
			}

			node	*upper_bound(const value_type& val) const {
				node	*upper = _nil;
				node	*current = _root;
				while (current != _nil) {
					if (_comp(val, current->_value)) {
						upper = current;
						current = current->_left;
					}
					else
						current = current->_right;
				}
				return upper;
			}

			void	swap(RedBlackTree &rhs) {
				ft::swap(_nil, rhs._nil);
				ft::swap(_root, rhs._root);
				ft::swap(_alloc, rhs._alloc);
				ft::swap(_alloc_node, rhs._alloc_node);
				ft::swap(_comp, rhs._comp);
				ft::swap(_size, rhs._size);
			}

			size_type	erase(const value_type& val) {
				node	*n = search(_root, val);
				if (n != nullptr) {
					erase(n);
					return 1;
				}
				return 0;
			}

			void		erase(node *n) {
				node *todelete = n;
				node *replace;
				int color = n->_color;
				if (n->_left == _nil) {
					replace = n->_right;
					transplantNode(n, n->_right);
				} else if (n->_right == _nil) {
					replace = n->_left;
					transplantNode(n, n->_left);
				} else {
					todelete = minimum(n->_right);
					color = todelete->_color;
					replace = todelete->_right;
					if (todelete->_parent == n) 
						replace->_parent = todelete;
					else {
						transplantNode(todelete, todelete->_right);
						todelete->_right = n->_right;
						todelete->_right->_parent = todelete;
					}
					transplantNode(n, todelete);
					todelete->_left = n->_left;
					todelete->_left->_parent = todelete;
					todelete->_color = n->_color;
				}
				if (color == BLACK)
					deleteFixup(replace);
				destroyNode(n);
			}

			void 	erase(iterator first, iterator last) {
				while (first != last) {
					erase(*first);
					first++;
				}
			}

			void	clear(node *n) {
				if (n && n->_cnt) {
					clear(n->_left);
					clear(n->_right);
					destroyNode(n);
				}
				_root = _nil;
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

			void inorder(node* n)
			{
				if (n != _nil)
				{
					inorder(n->_left);
					std::cout << n->_value.second << " ";
					inorder(n->_right);          
				}
			}

			node	*newNode(const value_type& val, node *parent, std::size_t cnt) {
				node *new_node = _alloc_node.allocate(1);
				_alloc.construct(&(new_node->_value), val);
				new_node->_parent = parent;
				new_node->_left = _nil;
				new_node->_right = _nil;
				new_node->_color = RED;
				new_node->_cnt = cnt;
				_size++;
				return new_node;
			}

			void freeNode(node *n) {
				_alloc_node.deallocate(n, 1); 
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
				if (x->_parent == _nil) {
					_root = y;
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
				if (x->_parent == _nil)
					_root = y;
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
				while (current != _root && current->_color == BLACK) {
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

			node *minimum(node *n) const {
				while (n->_left != _nil)
					n = n->_left;
				return n;
			}

			node *maximum(node *n) const {
				while (n && n->_cnt)
					n = n->_right;
				return n;
			}

			// node	*replaceNode(node *n) {
			// 	if (!n || (!n->_left && !n->_right))
			// 		return nullptr;
			// 	if (n->_left && n->_right)
			// 		return successor(n);
			// 	if (n->_right)
			// 		return n->_left;
			// 	return n->_right;
			// }

			// node *successor(node *x) {
			// 	if (x->_right != _nil)
			// 		return minimum(x->_right);
			// 	node *y = x->_parent;
			// 	while (y != _nil && x == y->_right) {
			// 		x = y;
			// 		y = y->_parent;
			// 	}
			// 	return y;
			// }

			// node *predecessor(node *x) {
			// 	if (x->_left != _nil)
			// 		return maximum(x->_left);
			// 	node *y = x->_parent;
			// 	while (y != _nil && x == y->_left) {
			// 		x = y;
			// 		y = y->_parent;
			// 	}
			// 	return y;
			// }

}; // namespace RBT



#endif