class ArrayStack:

 def init (self):
#Create an empty stack
 self. data = [ ] # nonpublic list instance

 def len (self):
#Return the number of elements in the stack.”””
 return len(self. data)

 def is empty(self):
#Return True if the stack is empty.”””
return len(self. data) == 0

 def push(self, e):
#Add element e to the top of the stack.”””
 self. data.append(e) # new item stored at end of list
 def top(self):
#Return (but do not remove) the element at the top of the stack.
 #Raise Empty exception if the stack is empty.


 if self.is empty( ):
 raise Empty( Stack is empty )
 return self. data[−1] # the last item in the list
 def pop(self): #Remove and return the element from the top of the stack (i.e., LIFO).
 #Raise Empty exception if the stack is empty.
 
 if self.is empty( ):
 raise Empty( Stack is empty )
 return self. data.pop( ) # remove last item from list
