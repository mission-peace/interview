# detect cycle in directed graph
# https://github.com/mission-peace/interview/blob/master/src/com/interview/graph/CycleInDirectedGraph.java

from graph import *

GRAY = "gray"
BLACK = "black"
WHITE = "white"

def has_cycle(graph):
    visited = set()
    current_stack = set()
    for vertex in graph.all_vertex.values():
        if vertex not in visited:
            result = has_cycle_util(vertex, visited, current_stack)
            if result:
                return True
    return False

def has_cycle_util(vertex, visited, current_stack):
    visited.add(vertex)
    current_stack.add(vertex)
    for adjacent in vertex.adjacent_vertices:
        if adjacent in current_stack:
            return True
        else:
            result = has_cycle_util(adjacent, visited, current_stack)
            if result:
                return True

    current_stack.remove(vertex)
    return False

def has_cycle_using_back_edge(graph):
    visited = {}
    for vertex in graph.all_vertex.values():
        visited[vertex] = WHITE

    for vertex in graph.all_vertex.values():
        if visited[vertex] == WHITE:
            result = has_cycle_using_back_edge_util(vertex, visited)
            if result:
                return True
    return False

def has_cycle_using_back_edge_util(vertex, visited):
    if visited[vertex] == GRAY:
        return True
    visited[vertex] = GRAY
    for adjacent in vertex.adjacent_vertices:
        result = has_cycle_using_back_edge_util(adjacent, visited)
        if result:
            return True
    visited[vertex] = BLACK
    return False
        

if __name__ == '__main__':
    graph = Graph(True)
    graph.add_edge(1,2)
    graph.add_edge(1,3)
    graph.add_edge(3,4)
    graph.add_edge(4,5)
    graph.add_edge(2,5)
    graph.add_edge(5,3)

    result1 = has_cycle(graph)
    result2 = has_cycle_using_back_edge(graph)
    print(str(result1) + " " + str(result2))
