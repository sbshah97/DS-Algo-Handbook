"""Implementation of a Binary Tree in Python."""

class BinaryTree:
    def __init__(self, root_node):
        self.key = root_node
        self.left_node = None
        self.right_node = None

    def insert_left(self, new_node):
        if self.left_node == None:
            self.left_node = BinaryTree(new_node)
        else:
            tree = BinaryTree(new_node)
            tree.left_node = self.left_node
            self.left_node = tree

    def insert_right(self, new_node):
        if self.right_node == None:
            self.right_node = BinaryTree(new_node)
        else:
            tree = BinaryTree(new_node)
            tree.right_node = self.right_node
            self.right_node = tree

    def get_left_node(self):
        return self.left_node

    def get_right_node(self):
        return self.right_node

    def get_root_value(self):
        return self.key

    def set_root_node(self, new_root):
        self.key = new_root
