package com.interview.graph;

import java.util.Set;
import java.util.HashSet;
import java.util.Deque;
import java.util.ArrayDeque;

/**
 * Date 08/20/2014
 * @author Tushar Roy
 *
 * Given a directed acyclic graph, do a topological sort on this graph.
 *
 * Do DFS (depth-first search) by keeping visited vertex in Set. 
 * Each vertex added to Set will be completely explored recursively.
 * Vertex is completely explored when it no longer has unvisited children
 * Put the vertex which are completely explored into a stack.
 * Pop from stack to get sorted order.
 *
 * Space and time complexity is O(n).
 */
public class TopologicalSort<T> {

    /**
     * Main method to be invoked to do topological sorting.
     */
    public Deque<Vertex<T>> topSort(Graph<T> graph) {
        Deque<Vertex<T>> stack = new ArrayDeque<>();
        Set<Vertex<T>> visited = new HashSet<>();
        // explore every vertex
        for (Vertex<T> vertex : graph.getAllVertex()) {
            // skip already visited vertex
            if (visited.contains(vertex)) {
                continue;
            }
            topSortUtil(vertex,stack,visited);
        }
        return stack;
    }

    private void topSortUtil(Vertex<T> vertex, Deque<Vertex<T>> stack,
            Set<Vertex<T>> visited) {
        visited.add(vertex);
        for(Vertex<T> childVertex : vertex.getAdjacentVertexes()){
            if(visited.contains(childVertex)){
                continue;
            }
            // childVertex not in visited Set, explore it recursively
            topSortUtil(childVertex,stack,visited);
        }
        // vertex completely explored, add to stack
        stack.offerFirst(vertex);
    }
    
    public static void main(String args[]){
        Graph<Integer> graph = new Graph<>(true);
        graph.addEdge(1, 3);
        graph.addEdge(1, 2);
        graph.addEdge(3, 4);
        graph.addEdge(5, 6);
        graph.addEdge(6, 3);
        graph.addEdge(3, 8);
        graph.addEdge(8, 11);
        
        TopologicalSort<Integer> sort = new TopologicalSort<Integer>();
        Deque<Vertex<Integer>> result = sort.topSort(graph);
        while(!result.isEmpty()){
            System.out.println(result.poll());
        }
    }
}
