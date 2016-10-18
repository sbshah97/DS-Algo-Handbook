class Node:
”””Lightweight, nonpublic class for storing a doubly linked node.”””
slots = _element , _prev , _next # streamline memory
def init (self, element, prev, next): # initialize node’s fields
self. element = element # user’s element
self. prev = prev # previous node reference
self. next = next


class DoublyLinkedBase:

 class Node:


 def init (self):
#Create an empty list.”””
 self. header = self. Node(None, None, None)
 self. trailer = self. Node(None, None, None)
 self. header. next = self. trailer # trailer is after header
 self. trailer. prev = self. header # header is before trailer
self. size = 0 # number of elements

 def len (self):
#Return the number of elements in the list.”””
 return self. size

 def is empty(self):
#Return True if list is empty.”””
 return self. size == 0

 def insert between(self, e, predecessor, successor):
#Add element e between two existing nodes and return new node.”””
 newest = self. Node(e, predecessor, successor) # linked to neighbors
 predecessor. next = newest
 successor. prev = newest
 self. size += 1
 return newest

 def delete node(self, node):
#Delete nonsentinel node from the list and return its element.”””
predecessor = node. prev
 successor = node. next
 predecessor. next = successor
 successor. prev = predecessor
 self. size −= 1
 element = node. element # record deleted element
 node. prev = node. next = node. element = None 
# deprecate node return element # return deleted element
Code Fragment
