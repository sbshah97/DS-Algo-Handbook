#Heap Sort

Heap Sort is a comparison based sorting technique based on the binary heap data structure. It is similar to the selection sort where we first find the greatest element and place it at the end. We repeat the same process for the remaining elements. To understand Heap Sort, we first understand what a Binary heap is.

Binary Heap-

To understand heaps, we will first get familiar with what a binary tree is. 

A complete binary tree is a binary tree in which every level, except possibly the last level is completely filled, and all nodes are far left as possible.

A Binary Heap is a Complete Binary Tree where items are stored in an order such that the value of parent node is always greater(or smaller) than the value of its two children node.

The Binary Heap in which the value of the paretn node is alway greater than its children node is called a Max Heap and the Heap in which the value of the parent node is always smaller than the calue of the children node is called Min Heap.

#Implementation-

To implement Heap Sort, an array can be used. An array based representation is space efficient. 

Assuming the index of array starts at 0, if the parent node is stored at index 'i', then the left child will be stored at index '2*i + 1' and the right child will be stored at index '2*i + 2'. 

#Algorithm
1. Build a Max Heap from the input data
2. At this stage, the largest element would be at the root of the heap.
3. Replace the root with the last item of the heap and folowed by reducing the size of heap by 1
4. Heapify the root again.
5. Repeat these steps until size of heap is more than 1.

#Time Complexity

Heap Sort algorithm takes O(NLogN) time to sort an array.
