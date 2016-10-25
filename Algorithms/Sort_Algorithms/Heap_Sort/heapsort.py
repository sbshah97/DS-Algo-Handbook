def maxHeapify(a,i,size):
	large = i
	left = 2*i+1
	right = 2*i+2
	if(left < size and a[left]>a[i]):
		large = left
	if(right < size and a[right]>a[large]):
		large = right
	if(large != i):
		a[i],a[large]=a[large],a[i]
		maxHeapify(a,large,size)
def buildMaxHeap(a,size):
	for i in range((size//2)-1,-1,-1):
		maxHeapify(a,i,size)

def heapSort(a):
	size=len(a)
	buildMaxHeap(a,size)
	for i in range(size-1,0,-1):
		a[i],a[0]=a[0],a[i]		# Swap Array[0] with Array[i]
		maxHeapify(a,0,i)
a = [4,2,1,6,3,6,7,9,-8,0]
heapSort(a)
print(a)
