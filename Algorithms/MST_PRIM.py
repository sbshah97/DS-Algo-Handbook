# Prim's algorithm is a greedy algorithm that
# finds a minimum spanning tree
# for a weighted undirected graph.
#
# Time complexity: O(m * n)

# Input Format:
# First line has two integers n,m where n=number of nodes in the graph and m=number of edges in the graph.
# The next  lines each consist of three space separated integers, denoting u=first vertex, v=second vertex, c=weight of edge.

# Output Format:
# Single integer denoting the weight of MST


import heapq
from collections import defaultdict

graph = defaultdict(list)                   # graph
n, m = map(int, raw_input().split(' ')) # number of vertexes and edges
weight = 0                              # weight of MST
MST = set([])                     # set containing connected vertexes
minHeap = []                                 # heap

for _ in range(m):
    u, v, c = map(int, raw_input().split(' '))
    graph[u].append((c, v))
    graph[v].append((c, u))

start = 1
MST.add(start)

for tup in graph[start]:
    heapq.heappush(minHeap, tup)

while minHeap:
    w, b = heapq.heappop(minHeap)
    if b not in MST:
        weight += w
        MST.add(b)

        for tup in graph[b]:
            heapq.heappush(minHeap, tup)

print weight
