class bstNode:
	# constructor
	def __init__(self, val=None):
		self.left = None
		self.right = None
		self.val = val
	# insert elements
	def insert(self, val):
		if not self.val:
			self.val = val
			return
		if self.val == val:
			return
		if val < self.val:
			if self.left:
				self.left.insert(val)
				return
			self.left = bstNode(val)
			return
		if self.right:
			self.right.insert(val)
			return
		self.right = bstNode(val)
	# min / max element
	def get_min(self):
		node = self
		while node.left is not None:
			node = node.left
		return node.val

	def get_max(self):
		node = self
		while node.right is not None:
			node = node.right
		return node.val

	def delete(self, val):
		if self == None:
			return self
		if val < self.val:
			if self.left:
				self.left = self.left.delete(val)
			return self
		if val > self.val:
			if self.right:
				self.right = self.right.delete(val)
			return self
		if self.right == None:
			return self.left
		if self.left == None:
			return self.right
		min_node = self.right
		while min_node.left:
			min_node = min_node.left
		self.val = min_node.val
		self.right = self.right.delete(min_node.val)
		return self
	# true / false is value exists
	def exists(self, val):
		if self.val == val:
			return True
		if val < self.val:
			if self.left == None:
				return False
			return self.left.exists(val)
		if self.right == None:
			return False
		return self.right.exists(val)
	# print’s the values in the tree in the order of their keys.
	def inorder(self, vals):
		if self.left is not None:
			self.left.inorder(vals)
		if self.val is not None:
			vals.append(self.val)
		if self.right is not None:
			self.right.inorder(vals)
		return vals
	def preorder(self, vals):
		if self.val is not None:
			vals.append(self.val)
		if self.left is not None:
			self.left.preorder(vals)
		if self.right is not None:
			self.right.preorder(vals)
		return vals
	def postorder(self, vals):
		if self.left is not None:
			self.left.postorder(vals)
		if self.right is not None:
			self.right.postorder(vals)
		if self.val is not None:
			vals.append(self.val)
		return vals

def main():
	nums = [12, 6, 18, 19, 21, 11, 3, 5, 4, 24, 18]
	bst = bstNode()
	for num in nums:
		bst.insert(num)
	print("preorder:")
	print(bst.preorder([]))
	print("#")

	print("postorder:")
	print(bst.postorder([]))
	print("#")

	print("inorder:")
	print(bst.inorder([]))
	print("#")

	nums = [2, 6, 20]
	print("deleting " + str(nums))
	for num in nums:
		bst.delete(num)
	print("#")

	print("4 exists:")
	print(bst.exists(4))
	print("2 exists:")
	print(bst.exists(2))
	print("12 exists:")
	print(bst.exists(12))
	print("18 exists:")
	print(bst.exists(18))
 
if __name__ == '__main__':
	main()