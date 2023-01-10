class Node:
	def __init__(self, val):
		self.red = False
		self.parent = None
		self.val = val
		self.right = None
		self.left = None

class RBtree:
	def __init__(self):
		self.nil = Node(0)
		self.nil.red = False
		self.nil.left = None
		self.nil.right = None
		self.root = self.nil

	def __repr__(self):
		lines = []
		print_tree(self.root, lines)
		return '\n'.join(lines)

	def exists(self, val):
		node = self.root
		while node != self.nil and val != node.val:
			if val < node.val:
				node = node.left
			else:
				node = node.right
		return node
	
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
			else:
				current = current.right
		# Set the parent and insert the new node
		new_node.parent = parent
		if parent == None:
			self.root = new_node
		elif new_node.val < parent.val:
			parent.left = new_node
		else:
			parent.right = new_node
		self.insert_fixup(new_node)
	
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
	
	# rotate right at node x
	def rotate_right(self, x):
		y = x.left
		x.left = y.right
		if y.right != self.nil:
			y.right.parent = x
		y.parent = x.parent
		if x.parent == None:
			self.root = y
		elif x == x.parent.right:
			x.parent.right = y
		else:
			x.parent.left = y
		y.right = x
		x.parent = y

	def insert_fixup(self, node):
		# depends on aunt's color
		while node != self.root and node.parent.red:
			# aunt.red -> colorflip
			if node.parent == node.parent.parent.right:
				aunt = node.parent.parent.left
				if aunt.red:
					aunt.red = False
					node.parent.parent.red = True
					node = node.parent.parent
				# aunt.black -> rotate
				else:
					if node == node.parent.left:
						node = node.parent
						self.rotate_right(node)
					node.parent.red = False
					node.parent.parent.red = True
					self.rotate_left(node.parent.parent)
			else:
				aunt = node.parent.parent.right
				if aunt.red:
					aunt.red = False
					node.parent.parent.red = True
					node = node.parent.parent
				else:
					if node == node.parent.right:
						node = node.parent
						self.rotate_left(node)
					node.parent.red = False
					node.parent.parent.red = True
					self.rotate_right(node.parent.parent)
		self.root.red = False

	def	get_min(self, node):
		while node.left != self.nil:
			node = node.left
		return node

	def	get_max(self, node):
		while node.right != self.nil:
			node = node.right
		return node

	# search similar to BST
	def search(self, val):
		node = self.root
		while node is not None:
			if val < node.val:
				node = node.left
			elif val > node.val:
				node = node.right
			else:
				return node
		return None

	# delete
	# replace node to be deleted with the one to be replaced by
	def transplant(self, todelete, toreplace):
		if todelete.parent == None:
			self.root = toreplace
		elif todelete == todelete.parent.left:
			todelete.parent.left = toreplace
		else:
			todelete.parent.right = toreplace
		toreplace.parent = todelete.parent

	def delete(self, val):
		node = self.root
		todelete = self.nil
		while node != self.nil:
			if node.val == val:
				todelete = node
			if node.val > val:
				node = node.left
			else:
				node = node.right
		if todelete == self.nil:
			print("Value not found")
			return
		save_color = todelete.red
		td = todelete
		replace = None
		if todelete.left == self.nil:
			replace = todelete.right
			self.transplant(todelete, todelete.right)
		elif todelete.right == self.nil:
			replace = todelete.left
			self.transplant(todelete, todelete.left)
		else:
			td = self.get_min(todelete.right)
			save_color = td.red
			replace = td.right
			if td.parent == todelete:
				replace.parent = todelete
			else:
				self.transplant(td, td.right)
				td.right = todelete.right
				td.right.parent = td
			self.transplant(todelete, td)
			td.left = todelete.left
			td.left.parent = td
			td.red = todelete.red
		if save_color == False:
			self.delete_fixup(replace)

	# dependance on sibling
	def delete_fixup(self, node):
		while node != self.root and node.red == False:
			if node == node.parent.left:
				sibling = node.parent.right
				# sibling:red -> colorflip & left rotate
				# Case 1: the sibling is red.
				if sibling.red == True:
					sibling.red = False
					node.parent.red = True
					self.rotate_left(node.parent)
					sibling = node.parent.right
				# Case 2: the sibling is black and its children are black.
				if sibling.left.red == False and sibling.right.red == False:
					sibling.red = True
					node = node.parent # new fixing node
				# Cases 3 and 4: the sibling is black and one of
				# its child is red and the other is black.
				else:
					if sibling.right.red == False:
						sibling.left.red = False
						sibling.red = True
						self.rotate_right(sibling)
						sibling = node.parent.right
					# Case 4: the sibling is black and its right child is red.
					sibling.red = node.parent.red
					node.parent.red = False
					sibling.right.red = False
					self.rotate_left(node.parent)
					node = self.root
			else:
				sibling = node.parent.left
				# Case 5: the sibling is red.
				if sibling.red == True:
					sibling.red = False
					node.parent.red = True
					self.rotate_right(node.parent)
					sibling = node.parent.left
				# Case 6: the sibling is black and its children are black.
				if sibling.right.red == False and sibling.left.red == False:
					sibling.red = True
					node = node.parent
				else:
					# Case 7: the sibling is black and its right child is red.
					if sibling.left.red == False:
						sibling.right.red = False
						sibling.red = True
						self.rotate_left(sibling)
						sibling = node.parent.left
					sibling.red = node.parent.red
					node.parent.red = False
					sibling.left.red = False
					self.rotate_right(node.parent)
					node = self.root
		node.red = False

def print_tree(node, lines, level=0):
	if node.val != 0:
		print_tree(node.left, lines, level + 1)
		lines.append('-' * 4 * level + '> ' +
					 str(node.val) + ' ' + ('r' if node.red else 'b'))
		print_tree(node.right, lines, level + 1)

def main():
	tree = RBtree()
	for x in range(1, 10):
		tree.insert(x)
	print(tree)
	print("*******************")
	#tree.delete(4)
	tree.insert(4)
	print(tree)


main()