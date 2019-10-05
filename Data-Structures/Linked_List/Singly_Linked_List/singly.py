class Node:
	def __init__(self, data):
		self.data = data
		self.next = None

class LinkedList:
	def __init__(self):
		self.head = None		

	def add(self, data):
		node = Node(data)
		if self.head == None:	
			self.head = node
		else:
			node.next = self.head						
			self.head = node		

	def search(self, k):
		p = self.head
		if p != None :
			while p.next != None:
				if (p.data == k):
					return p			
				p = p.next
			if (p.data == k):
				return p
		return None

	def get_node_prev(self, p):
		if(p == None):
			return None
		prev = p
		tmp = self.head
		while tmp.next != None:
			prev = tmp
			if tmp.next == p:
				return prev
			tmp = tmp.next

		if tmp == p:
			return prev
		return None

	def remove(self, p):
		# check if p is None
		if (p == None):
			return None

		# if the deleted node is the head node
		if (p == self.head):
			self.head = p.next
			return 1

		# need to get prev node to delete the current
		prev = self.get_node_prev(p)
		if prev == None:
			return None
		prev.next = p.next
		return 1



	def __str__( self ) :
		s = ""
		p = self.head
		if p != None :		
			while p.next != None :
				s += str(p.data)+", "
				p = p.next
			s += str(p.data)
		return s

if __name__ == "__main__":
	linked_list = LinkedList()
	linked_list.add(1)
	linked_list.add(10)
	linked_list.add(11)
	linked_list.add(9)
	linked_list.add(5)
	linked_list.add(3)
	linked_list.add(6)
	linked_list.add(7)
	linked_list.add(8)
	
	# print linked list
	print linked_list

	print "test cases"

	# search testing
	print "test #1"
	print "pass" if 9 == linked_list.search(9).data else "failed"
	
	print "test #2"
	print "pass" if None == linked_list.search(0) else "failed"
	
	print "test #3"
	print "pass" if 3 == linked_list.search(3).data else "failed"
	
	# search remove
	print "test #4"
	print "pass" if 1 == linked_list.remove(linked_list.search(3)) else "failed"

	print "test #5"
	print "pass" if 1 == linked_list.remove(linked_list.search(10)) else "failed"
	
	print "test #6"
	print "pass" if 1 == linked_list.remove(linked_list.search(8)) else "failed"

	print "test #7"
	print "pass" if None == linked_list.remove(linked_list.search(80)) else "failed"

	# print linked list
	print linked_list
