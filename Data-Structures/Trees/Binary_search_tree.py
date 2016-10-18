class Node:
   
#Tree node: left and right child + data which can be any object
  
def __init__(self, data):
       
self.left = None
        self.right = None
        self.data = data

        class Node:
   
def insert(self, data):
        
        #Insert new node with data

       
       
if self.data:
            if data < self.data:
                if self.left is None:
                    self.left = Node(data)
                else:
                    self.left.insert(data)
            elif data > self.data:
                if self.right is None:
                    self.right = Node(data)
                else:
                    self.right.insert(data)
        else:
            self.data = data

            def lookup(self, data, parent=None):
        
#Lookup node containing data

        
        if data < self.data:
            if self.left is None:
                return None, None
            return self.left.lookup(data, self)
        elif data > self.data:
            if self.right is None:
                return None, None
            return self.right.lookup(data, self)
        else:
            return self, parent



  def delete(self, data): #delete

        node, parent = self.lookup(data)
        if node is not None:
            children_count = node.children_count()
  def print_tree(self):
        
 # Print tree content inorder

        if self.left:
            self.left.print_tree()
        print self.data,
        if self.right:
            self.right.print_tree()

