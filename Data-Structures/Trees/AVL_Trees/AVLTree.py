class Node:
    # Node class. Each node can hold data, left and right children and keeps
    # track of its height

    def __init__(self, value):
        self.data = value
        self.left = None
        self.right = None
        self.height = 1


class Tree:
    # Node class. A tree is composed of nodes and has a root.
    # All operations start from the root.
    # we can lookup, print and insert values.
    # Insert calls are modified from a standard tree to keep the AVL condition
    # intact

    def __init__(self, value):
        self.root = Node(value)

    def insert(self, value):
        # Insert a value. Tree remains balanced after the value is inserted
        self.root = self.__insert_helper(self.root, value)

    def lookup(self, value):
        # Lookup a value. Returns True if the value is present, False otherwise
        return self.__lookup_helper(self.root, value)

    def print_in_order(self):
        # Print the tree using in-order traversal
        self.__print_in_order_helper(self.root)

    # HELPERS
    def __lookup_helper(self, node, value):
        if node is None:
            return False
        if node.data == value:
            return True

        if value < node.data:
            return self.__lookup_helper(node.left, value)
        else:
            return self.__lookup_helper(node.right, value)

    def __print_in_order_helper(self, root):
        if root is None:
            return
        self.__print_in_order_helper(root.left)
        print(root.data)
        self.__print_in_order_helper(root.right)

    def __get_height(self, root_node):
        if root_node is None:
            return 0
        return 1 + max(self.__get_height(root_node.left), self.__get_height(root_node.right))

    def __insert_helper(self, node, value):
        if node is None:
            return Node(value)
        if value < node.data:
            node.left = self.__insert_helper(node.left, value)
        else:
            node.right = self.__insert_helper(node.right, value)

        balance = self.__get_height(node.left) - self.__get_height(node.right)

        # The balance is greater than one so it is left-leaning
        if balance > 1:
            if value < node.left.data:
                # the value was inserted in left child of the left subtree,
                # so it was a left-left insertion. Therefore a right-rotation
                # is needed
                return self.__rotate_right(node)
            else:
                # the value was inserted in right child of the left subtree,
                # so it was a left-right insertion. Therefore a left-right
                # rotation is needed
                node.left = __rotate_left(node.left)
                return __rotate_right(node)

        # The balance is less than one so it is right-leaning
        elif balance < -1:
            if value > node.right.data:
                # the value was inserted in right child of the right subtree,
                # so it was a right-right insertion. Therefore a left-rotation
                # is needed
                return self.__rotate_left(node)
            else:
                # the value was inserted in left child of the right subtree,
                # so it was a right-left insertion. Therefore a right-left
                # rotation is needed
                node.right = __rotate_right(node.right)
                return __rotate_left(node)

        else:
            # This subtree remains balanced after insertion, so return the node
            return node

    def node_height(self, node):
        if node is None:
            return 0
        return node.height

    def __rotate_left(self, node):
        right_child = node.right
        right_left = right_child.left

        right_child.left = node
        node.right = right_left

        node.height = max(self.node_height(node.left), self.node_height(node.right)) + 1
        right_child.height = max(self.node_height(right_child.left), self.node_height(right_child.right)) + 1

        return right_child

    def __rotate_right(self, node):
        left_child = node.left
        left_right = left_child.right

        left_child.right = node
        node.left = left_right

        node.height = max(self.node_height(node.left), self.node_height(node.right)) + 1
        left_child.height = max(self.node_height(left_child.left), self.node_height(left_child.right)) + 1

        return left_child

tree = Tree(5)
tree.insert(4)
tree.insert(3)
tree.print_in_order()
print(tree.lookup(6))
