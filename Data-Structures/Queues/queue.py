""" 
I implementated the basic operations with queue's in C++
"""

class Queue:
	def __init__(self):
		self.__size = 0
		self.__items = []
	def empty(self):
		return (self.__size == 0)

	def size(self):
		return self.__size

	def front(self):
		if self.__size != 0:
	    		return self.__items[0]
		return "the queue is empty"

	def push_back(self, x):
		self.__size = self.__size + 1
		self.__items.append(x)

	def pop_front(self):
		for i in (1, self.__size-1):
	    		self.__items[i-1] = self.__items[i]

		self.__size = self.__size - 1
	


""" some tests """

q = Queue()
print (q.empty())
print(q.empty())
print(q.size())

q.push_back(1)
q.push_back(2)
q.push_back(3)
q.push_back(4)
q.push_back(5)

print(q.empty())
print(q.size())

q.pop_front()

print(q.size())

while not q.empty():
	q.pop_front()

print(q.empty())
print(q.size())
    
