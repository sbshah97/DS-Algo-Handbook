## Introduction
An AVL tree is a variant of a binary search tree (BST). 
In a sense, they are very similar as they both contain the same properties:
	- Items can be inserted or deleted
	- Items can be looked up in the data structure
	- They share the same BST property: the left subtree of node contains smaller items and the right subtree of a node contains larger items

However, there is a large difference because an AVL tree is *self-balancing*.
A regular BST has an optimal height of O(log n) with n the number of items.
This means that lookups of items are also performed in O(log n).
However, a pathological BST can have, for example, only right children which renders its height to O(n), thus also having O(n) search.

A self-balancing binary search tree, as an AVL tree is, enforces additional constraints to prevent the tree from nearing the pathological case and ensuring that it stays within bounds of the optimal data 
structure.

## How it works
In a normal BST, each node contains three elements:
- The content or data
- A left child
- A right child

An AVL tree has an additional item per node: the balance factor.
This value represents the difference in height between the left child and right child.
The AVL tree enforces that the balance factor for each node in the tree is either 1 -- the right subtree has one node more than the left subtree, 0 -- a balanced node, or -1, the left subtree has one 
node more than the right subtree.
This is also called the AVL condition.
If this is the case for each node in the tree than the height of the entire tree is always O(log n), regardless of the number of items in the tree.
One could also require that each node has to be perfectly balanced, but it turns out that in practice that the current AVL condition is ``balanced enough'' and that when perfect balance is required, the 
time saved searching is wasted on keeping the tree in perfect balance during modification.

## Operations
We will now see how different fundamental operations for BSTs are defined.

### Lookup
Searching a value in the AVL tree is no different than searching in a regular BST.
The only difference is that searching is guaranteed to be O(log n) rather than only in the best-case scenario with a regular BST.

### Insertion 
Consider when a leaf is inserted in an AVL tree. It might be that the AVL condition is not violated and that one has not do any extra work.
However, it could also be that the parent or some node higher up the tree has now become unbalanced. The AVL condition is then restored by *rotations*.
There are four kinds of rotations:
- Left rotation
- Right rotation
- Left-Right rotation
- Right-left rotation

For a visualization of these rotations, see here: https://www.tutorialspoint.com/data_structures_algorithms/avl_tree_algorithm.htm
Suppose a node has been inserted in the right subtree (C) of a right child (B) of a node (A), and (A) and has become unbalanced due to that insertion. This means that (A) now has a balance factor of 2 
and (B) has a balance factor of 1. This imbalance can be solved by a left rotation: It substitutes (B) in the place of (A) with (A) and (C) as its left- and right children, respectively.
This restores the AVL condition. This is called a left rotation because when visualized, it looks like the whole subtree is rotated to its left with (B) as turning point.

The analogous happens when a node is inserted in the *left* subtree of a *left* child of a node. Then a right rotation happens.

Difficult cases are when a node is inserted in the right subtree (B) of a left child (A) of a node (C) or the left subtree of a right child. Then this cannot be solved with one rotation because this 
alone will not restore the AVL condition because it would violate the properties of a BST. In this case, two rotations are needed to restore the AVL condition while maintaining the BST property.
In the first case, we perform a left-rotation on (A) and (B) and subsequently perform a right-rotation on (B) and (C). In the other case the reverse happens; first a right-rotation is performed and then 
a left-rotation.

While this seems like a lot of work it is actually not so bad in terms of complexity. One has to perform at most O(log n) rotations as this procedure might be necessary from the leaf node where it is 
inserted all the way up to the root of the tree. In that case it has to traverse O(log n) nodes since it already was an AVL tree. Assuming insertion and rotation happen in O(1), insertion in an AVL tree 
happens in O(log n).

### deletion 
When deleting a node, in fact the same happens as in insertion: if the AVL property remains intact, no extra work needs to be done and a node can be deleted. If it is violated, however, then mirrored set 
of rotations need to happen with respect to insertion. 
