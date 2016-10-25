def bfs(graph, start):
    visited = [False] * len(graph)
    queue = []
    print(start)
    visited[start] = True
    queue.insert(0, start)
    while(len(queue) != 0):
        actual = queue.pop()
        for i in range(0, len(graph)):
            if(graph[actual][i] > 0 and not visited[i]):
                print(i)
                visited[i] = True
                queue.insert(0, i)

"""
    Graph is represented with an Adjacency Matrix.

    Negative values mean that there's no edge between
    the two nodes, and 0 means it's the same node.

    Positive values mean that there's an edge between
    the two nodes.
"""
graph = [ [0,1,1,-1], [1,0,1,-1], [1,1,0,1], [-1,-1,1,0] ]
bfs(graph, 0)
