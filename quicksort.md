#QUICK SORT

1. Quick sort is a highly efficient sorting algorithm.

2. The quick sort uses divide and conquer paradigm to gain the same advantages as the merge sort.

3. A quick sort first selects a value, which is called the pivot value.

4. In quicksort, the array of items to be sorted is divided into two partitions and then the quicksort procedure is called recursively to sort the two partitions, ie we divide the problem into two smaller ones and conquer by solving the smaller ones. In quick sort, a large array is partitioned into two arrays one of which holds values smaller than the pivot value and another array holds values greater than the pivot value.

5. It reduces the space complexity and removes the use of the auxiliary array that is used in merge sort. Selecting a random pivot in an array results in an improved time complexity in most of the cases.
 
#STEPS
 
The algorithm to sort the array using quick sort comprises of following steps:

Step 1 − Make the right-most index value pivot.

Step 2 − Take two variables,one of which points to the left-most index and the other to the right-most index of the array excluding pivot.

Step 3 − while value at left is less than pivot move right.

Step 4 − while value at right is greater than pivot move left.

Step 5 − if both step 3 and step 4 does not match swap left and right.

Step 6 − if left ≥ right, the point where they met is new pivot.

#COMPLEXITY

The worst case time complexity of this algorithm is O(N2) , but as this is randomized algorithm, its time complexity fluctuates between O(N2) and O(NlogN) and mostly it comes out to be O(NlogN)
