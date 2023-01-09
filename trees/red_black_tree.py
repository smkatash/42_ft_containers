class Node:
	def __init__(self, val):
		self.red = False
		self.parent = None
		self.val = val
		self.right = None
		self.left = None

class rbTree:
	def __init__(self, val):
		self.nil = Node(0)
		self.nil.red = False
		self.nil.left = None
		self.nil.right = None
		self.root = self.nil

	#insert elements
	# Ordinary Binary Search Insertion
	def insert(self, val):
		new_node = Node(val)
		new_node.parent = None
		new_node.left = self.nil
		new_node.right = self.nil
		# new node must be red
		new_node.red = True
		parent = None
		current = self.root
		while current != self.nil:
			parent = current
			if new_node.val < current.val:
				current = current.left
			elif new_node.val > current.val:
				current = current.right
			else:
				return
		# Set the parent and insert the new node
		new_node.parent = parent
		if parent == None:
			self.root = new_node
		elif new_node.val < parent:
			parent.left = new_node
		else:
			parent.right = new_node
		self.rebalance(new_node)
	# rotate left at node x
	def rotate_left(self, x):
		y = x.right
		x.right = y.left
		if y.left != self.nil:
			y.left.parent = x
		y.parent = x.parent
		if x.parent == None:
			self.root = y
		elif x == x.parent.left:
			x.parent.left = y
		else:
			x.parent.right = y
		y.left = x
		x.parent = y
	# rotate left at node x
	def rotate_right(self, x):
		y = x.left
		x.left = y.right
		if y.right != self.nil:
			y.right.parent = x
		y.parent = x.parent
		if x.parent == None:
			self.root = y
		elif x == x.parent.left:
			x.parent.left = y
		else:
			x.parent.right = y
		y.right = x
		x.parent = y
			
		