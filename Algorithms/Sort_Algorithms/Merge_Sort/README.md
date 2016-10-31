#MERGE SORT

Merge sort is a sorting technique based on the divide-and-conquer paradigm. 

It is based on the idea of breaking down a collection of data elements like an array of integers into several sub-arrays until each subarray consists of a single element and merging those subarrays in a manner that results into a sorted array.In other words, it divides input array in two halves, calls itself for the two halves and then merges the two sorted halves. 


#STEPS
To sort an array To sort A[p .. r]:

1. Divide Step
If a given array A has zero or one element, simply return; it is already sorted. Otherwise, split A[p .. r] into two subarrays A[p .. q] and A[q + 1 .. r], each containing about half of the elements of A[p .. r]. That is, q is the halfway point of A[p .. r].

2. Conquer Step
Conquer by recursively sorting the two subarrays A[p .. q] and A[q + 1 .. r].

3. Combine Step or merge step
Combine the elements back in A[p .. r] by merging the two sorted subarrays A[p .. q] and A[q + 1 .. r] into a sorted sequence. 


#Steps to merge/combine two arrays

Assume, that both arrays are sorted in ascending order and we want resulting array to maintain the same order. Algorithm to merge two arrays A[0..m-1] and B[0..n-1] into an array C[0..m+n-1] is as following:

1.    Introduce read-indices i, j to traverse arrays A and B, accordingly. Introduce write-index k to store position of the first free cell in the resulting array. By default i = j = k = 0.

2.    At each step: if both indices are in range ((i < m) and (j < n)), choose minimum of (A[i], B[j]) and write it to C[k]. Otherwise go to step 4.

3.    Increase k and index of the array, algorithm located minimal value at, by one. Repeat step 2.
4.    Copy the rest values from the array, which index is still in range, to the resulting array.


#COMPLEXITY:

An array of N elements is divided into a max of logN parts, and the merging of all subarrays into a single array takes O(N) time.So in the worst case, run time of this algorithm is O(NLogN).
