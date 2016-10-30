#INSERTION SORT
	
Insertion sort is an elementary sorting algorithm that sorts one element at a time. 

Insertion sort is a simple sorting algorithm that works the way we sort playing cards in our hands.

The idea behind is that in each iteration, it consumes one element from the input elements, removes it and finds its correct position 		i.e., where it belongs in the sorted list and places it there.

It iterates the array by growing the sorted list behind it at each iteration. It checks the current element with the largest value in 		the sorted list. If the current element is larger, then it leaves the element at its place and moves to the next element else it finds 		its correct position in the sorted list and moves it to that position. It is done by shifting all the elements which are larger than 		the current element to one position ahead.
	
In insertion sort, the array consists of two sublists. One of which is sorted and the other one unsorted. Initially the first element 		of the array is considered to be sorted sublist and the remaining array as unsorted sublist.

#ALGORITHM

The algorithm takes an element from the list and places it in the correct location in the list. This process is repeated until there are no more unsorted items in the list. 

Simple steps by which we can achieve insertion sort.

Step 1 − If it is the first element, it is already sorted. return 1;

Step 2 − Pick next element

Step 3 − Compare with all elements in the sorted sub-list

Step 4 − Shift all the elements in the sorted sub-list that is greater than the 
         value to be sorted

Step 5 − Insert the value

Step 6 − Repeat until list is sorted

#COMPLEXITY : 
Complexity of Insertion sort is O(n2) .

