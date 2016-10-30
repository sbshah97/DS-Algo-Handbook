'''
Topological sort.
Taken from : 
http://stackoverflow.com/questions/15038876/topological-sort-python
'''

from collections import defaultdict
from itertools import takewhile, count

def sort_topologically(graph):
    levels_by_name = {}
    names_by_level = defaultdict(set)

    def walk_depth_first(name):
        if name in levels_by_name:
            return levels_by_name[name]
        children = graph.get(name, None)
        level = 0 if not children else (1 + max(walk_depth_first(lname) for lname in children))
        levels_by_name[name] = level
        names_by_level[level].add(name)
        return level

    for name in graph:
        walk_depth_first(name)

    return list(takewhile(lambda x: x is not None, (names_by_level.get(i, None) for i in count())))


graph = {
        1: [2, 3],
        2: [4, 5, 6],
        3: [4,6],
        4: [5,6],
        5: [6],
        6: []
    }

print(sort_topologically(graph))