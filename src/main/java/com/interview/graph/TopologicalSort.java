package com.interview.graph;

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.HashMap;
import java.util.Map;

public class TopologicalSort<T> {

    public Deque<Vertex<T>> topSort(Graph<T> graph) {
        Deque<Vertex<T>> stack = new ArrayDeque<Vertex<T>>();
        Map<Vertex<T>, Boolean> visited = new HashMap<Vertex<T>, Boolean>();
        for (Vertex<T> vertex : graph.getAllVertex()) {
            if (visited.containsKey(vertex)) {
                continue;
            }
            topSortUtil(vertex,stack,visited);
        }
        return stack;
    }

    private void topSortUtil(Vertex<T> vertex, Deque<Vertex<T>> stack,
            Map<Vertex<T>, Boolean> visited) {
        visited.put(vertex, true);
        for(Vertex<T> childVertex : vertex.getAdjacentVertexes()){
            if(visited.containsKey(childVertex)){
                continue;
            }
            topSortUtil(childVertex,stack,visited);
        }
        stack.offerFirst(vertex);
    }
    
    public static void main(String args[]){
        Graph<Integer> graph = new Graph<Integer>(true);
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
