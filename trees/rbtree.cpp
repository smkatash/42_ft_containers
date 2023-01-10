#include <iostream>
# define red 0
# define black 1
using namespace std;

struct Node {
	int val;
	Node *parent, *left, *right;
	int color;
};

typedef Node *node;

class RedBlackTree {
	private:
		node _root;
		node _nil;
	
	void node_nil(node n, node parent) {
		n->val = 0;
		n->parent = parent;
		n->left = nullptr;
		n->right = nullptr;
		n->color = black;
	}

	void insertFixup(node n) {
		node aunt;
		while (n != _root && n->parent->color == red) {
			if (n->parent == n->parent->parent->right) {
				aunt = n->parent->parent->left;
				// aunt.red -> colorflip
				if (aunt->color == red) {
					aunt->color = black;
					n->parent->parent->color = red;
					n = n->parent->parent;
				} else {
					// aunt.black -> rotate
					if (n == n->parent->left) {
						n = n->parent;
						rotateRight(n);
					}
					n->parent->color = black;
					n->parent->parent->color = red;
					rotateLeft(n->parent->parent);
				}
			} else {
				aunt = n->parent->parent->right;
				// aunt.red -> colorflip
				if (aunt->color == red) {
					aunt->color = black;
					n->parent->parent->color = red;
					n = n->parent->parent;
				} else {
					// aunt.black -> rotate
					if (n == n->parent->right) {
						n = n->parent;
						rotateLeft(n);
					} else {
						n->parent->color = black;
						n->parent->parent->color = red;
						rotateRight(n->parent->parent);
					}
				}
			}
			_root->color = black;
		}
	}

	public:
		// constructor
		RedBlackTree() {
			_nil = new Node;
			_nil->color = black;
			_nil->left = nullptr;
			_nil->right = nullptr;
			_root = _nil;
		}

		void rotateLeft(node x) {
			node y = x->right;
			x->right = y->left;
			if (y->left != this->_nil)
				y->left->parent = x;
			y->parent = x->parent;
			if (x->parent == nullptr) {
				this->_root = y;
			}
			else if (x == x->parent->left) {
				x->parent->left = y;
			} else {
				x->parent->right = y;
			}
			y->left = x;
			x->parent = y;
		}

		void rotateRight(node x) {
			node y = x->left;
			x->left = y->right;
			if (y->right != this->_nil)
				y->right->parent = x;
			y->parent = x->parent;
			if (x->parent == nullptr)
				this->_root = y;
			else if (x == x->parent->right)
				x->parent->right = y;
			else
				x->parent->left = y;
			y->right = x;
			x->parent = y;
		}

		node	minimum(node x) {
			while (x->left != _nil) {
				x = x->left;
			}
			return x;
		}

		node	maximum(node x) {
			while (x->right != _nil) {
				x = x->right;
			}
			return x;
		}

		void	insert(int val) {
			node n = new Node;
			n->parent = nullptr;
			n->left = _nil;
			n->right = _nil;
			n->val = val;
			n->color = red;
			node parent = nullptr;
			node current = this->_root;
			while (current != _nil ) {
				parent = current;
				if (n->val < current->val)
					current = current->left;
				else
					current = current->right;
			}
			n->parent = parent;
			if (parent == nullptr)
				_root = n;
			else if (n->val < parent->val)
				parent->left = n;
			else
				parent->right = n;
			if (n->parent == nullptr) {
				n->color = black;
				return;
			}
			if (n->parent->parent == nullptr)
				return;
			insertFixup(n);
		}
};

