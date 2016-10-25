---------------------------------------------------
Depth First Traversal/Search (DFS) for a Graph:
---------------------------------------------------

Definition:

Depth First Search (DFS) algorithm traverses a graph in a depthward motion and uses a stack to remember to get the next vertex to start a search, when a dead end occurs in any iteration.

Implementation Algorithm:

    Rule 1 − Visit the adjacent unvisited vertex. Mark it as visited. Display it. Push it in a stack.

    Rule 2 − If no adjacent vertex is found, pop up a vertex from the stack. (It will pop up all the vertices from the stack, which do not have adjacent vertices.)

    Rule 3 − Repeat Rule 1 and Rule 2 until the stack is empty.

Formally, Depth-first search (DFS) is an algorithm for traversing or searching tree or graph data structures. One starts at the root (selecting some arbitrary node as the root in the case of a graph) and explores as far as possible along each branch before backtracking.