#ford fulkerson method edomonds karp algorithm
# java code https://github.com/mission-peace/interview/blob/master/src/com/interview/graph/FordFulkerson.java
from queue import Queue
import sys

def max_flow(capacity, s, t):
    flow = [[0 for x in range(len(capacity))] for x in range(len(capacity[0]))]
    max_flow = 0
    while True:
        parent,min_capacity = bfs(capacity, flow, s, t)
        if min_capacity == 0:
            break;

        max_flow += min_capacity

        v = t;
        while v != s:
            u = parent[v]
            flow[u][v] += min_capacity
            flow[v][u] -= min_capacity
            v = u

    return max_flow
            
def bfs(capacity, flow, s, t):
    visited = set()
    queue = Queue()
    queue.put(s)
    visited.add(s)
    parent = {}
    min_capacity = {}
    min_capacity[s] = sys.maxsize;
    while not queue.empty():
        u = queue.get()
        for v in range(len(capacity)):
            residual_capacity = capacity[u][v] - flow[u][v]
            if v not in visited and residual_capacity > 0:
                parent[v] = u
                if (residual_capacity < min_capacity[u]):
                    min_capacity[v] = residual_capacity
                else:
                    min_capacity[v] = min_capacity[u] 
                if v == t:
                    return (parent, min_capacity[v])
                visited.add(v)
                queue.put(v)
    return (parent, 0)

if __name__ == '__main__':
    capacity = [[0, 3, 0, 3, 0, 0, 0],
                [0, 0, 4, 0, 0, 0, 0],
                [3, 0, 0, 1, 2, 0, 0],
                [0, 0, 0, 0, 2, 6, 0],
                [0, 1, 0, 0, 0, 0, 1],
                [0, 0, 0, 0, 0, 0, 9],
                [0, 0, 0, 0, 0, 0, 0]]

    capacity1 = [[0, 16, 13, 0, 0, 0],
                 [0, 0, 10, 12, 0, 0],
                 [0, 4, 0, 0, 14, 0],
                 [0, 0, 9, 0, 0, 20],
                 [0, 0, 0, 7, 0, 4],
                 [0, 0, 0, 0, 0, 0]]
    max_val = max_flow(capacity1, 0 ,5)
    print(max_val)
