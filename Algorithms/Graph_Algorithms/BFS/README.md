---------------------------------------------------
Breadth First Traversal/Search (BFS) for a Graph:
---------------------------------------------------


Definition:

Breadth First Search (BFS) algorithm traverses a graph in a breadthward motion and uses a queue to remember to get the next vertex to start a search, when a dead end occurs in any iteration.

Implementation Algorithm:

    Rule 1 − Visit the adjacent unvisited vertex. Mark it as visited. Display it. Insert it in a queue.

    Rule 2 − If no adjacent vertex is found, remove the first vertex from the queue.

    Rule 3 − Repeat Rule 1 and Rule 2 until the queue is empty.

When the queue gets empty, the program is over.
The displayed order of vertices is the BFS traversal of the given graph.


Formally, Breadth-first search (BFS) is an algorithm for traversing or searching tree or graph data structures. It starts at the tree root (or some arbitrary node of a graph, sometimes referred to as a 'search key') and explores the neighbor nodes first, before moving to the next level neighbors.		