---------------------------------------------------
Binary Search :
---------------------------------------------------

## Definition:

- Binary search is a fast search algorithm with run-time complexity of **Ο(log n)**. 
- This search algorithm works on the principle of __Divide and Conquer__. 

## Algorithm

- Binary search looks for a particular item by comparing the middle most item of the collection. 
- If a match occurs, then the index of item is returned. 
- If the middle item is greater than the item, then the item is searched in the sub-array to the right of the middle item. 
- Otherwise, the item is searched for in the sub-array to the left of the middle item. 
- This process continues on the sub-array as well until the size of the subarray reduces to zero.

For a binary search to work, it is **mandatory** for the target array to be sorted. 

## Pseudo Code:

Binary_Search(A, first, last, key)
1. while(first < last)
2.	mid = (first + last) / 2
3. 	if(A[mid] == key)
4.		return mid
5.	else if(A[mid] > key)
6.		last = mid - 1
7.	else
8.		first = mid + 1
9.	return -1

