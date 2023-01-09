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

class RBtree {
	private:
		node root;
		node nil;
	
	void node_nil(node n, node parent) {
		n->val = 0;
		n->parent = parent;
		n->left = nullptr;
		n->right = nullptr;
		n->color = black;
	}

	public:
		// constructor
		RBtree() {
			nil = new Node;
			nil->color = black;
			nil->left = nullptr;
			nil->right = nullptr;
			root = nil;
		}

		void rotateLeft(node x) {
			node y = x->right;
			x->right = y->left;
			if (y->left != this->nil)
				y->left->parent = x;
			y->parent = x->parent;
			if (x->parent == nullptr) {
				this->root = y;
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
			if (y->right != this->nil)
				y->right->parent = x;
			y->parent = x->parent;
			if (x->parent == nullptr)
				this->root = y;
			else if (x == x->parent->right)
				x->parent->right = y;
			else
				x->parent->left = y;
			y->right = x;
			x->parent = y;
		}
}

