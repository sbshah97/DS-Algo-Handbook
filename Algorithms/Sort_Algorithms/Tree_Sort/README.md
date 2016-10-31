Definition:
A tree sort is a sort algorithm that builds a binary search tree from the elements to be sorted, and then traverses the tree (in-order) so that the elements come out in sorted order. Its typical use is sorting elements adaptively: after each insertion, the set of elements seen so far is available in sorted order.

Algorithm:
Step 1: Take the elements input in an array.
Step 2: Create a Binary search tree by inserting data items from the array into the
        binary searh tree.
Step 3: Perform in-order traversal on the tree to get the elements in sorted order.

Complexity:
Worst case space complexity‎: ‎Θ(n)
Average case performance‎: ‎O(n log n)
Best case performance‎: ‎O(n log n)
Worst case performance‎: ‎O(n²) (unbalanced)