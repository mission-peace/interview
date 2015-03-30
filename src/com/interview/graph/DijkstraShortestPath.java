package com.interview.graph;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/**
 * http://www.geeksforgeeks.org/greedy-algorithms-set-7-dijkstras-algorithm-for-adjacency-list-representation/
 */
public class DijkstraShortestPath {

    public Map<Vertex<Integer>,Integer> shortestPath(Graph<Integer> graph, Vertex<Integer> sourceVertex){
        
        BinaryMinHeap<Vertex<Integer>> minHeap = new BinaryMinHeap<Vertex<Integer>>();
        for(Vertex<Integer> vertex : graph.getAllVertex()){
            minHeap.add(1000, vertex);
        }
        
        minHeap.decrease(sourceVertex, 0);
        Map<Vertex<Integer>,Integer> distance = new HashMap<Vertex<Integer>,Integer>();
        distance.put(sourceVertex, 0);
        
        Set<Vertex<Integer>> finishedSet = new HashSet<Vertex<Integer>>();
        while(!minHeap.empty()){
            Vertex<Integer> u = minHeap.extractMin();
            finishedSet.add(u);
            for(Edge<Integer> e : u.getEdges()){
                Vertex<Integer> v = getVertexForEdge(u, e);
                if(finishedSet.contains(v)){
                    continue;
                }
                int newDistance = distance(distance, u) + e.getWeight();
                if(distance(distance,v) > newDistance){
                    distance.put(v, newDistance);
                    minHeap.decrease(v, newDistance);
                }
            }
        }
        return distance;
    }

    private int distance(Map<Vertex<Integer>,Integer> distance, Vertex<Integer> key){
        return distance.containsKey(key) ? distance.get(key) : 1000;
    }
    
    private Vertex<Integer> getVertexForEdge(Vertex<Integer> v, Edge<Integer> e){
        return e.getVertex1().equals(v) ? e.getVertex2() : e.getVertex1();
    }
    
    public static void main(String args[]){
        Graph<Integer> graph = new Graph<Integer>(false);
        graph.addEdge(0, 1, 4);
        graph.addEdge(1, 2, 8);
        graph.addEdge(2, 3, 7);
        graph.addEdge(3, 4, 9);
        graph.addEdge(4, 5, 10);
        graph.addEdge(2, 5, 4);
        graph.addEdge(1, 7, 11);
        graph.addEdge(0, 7, 8);
        graph.addEdge(2, 8, 2);
        graph.addEdge(3, 5, 14);
        graph.addEdge(5, 6, 2);
        graph.addEdge(6, 8, 6);
        graph.addEdge(6, 7, 1);
        graph.addEdge(7, 8, 7);
        
        DijkstraShortestPath dsp = new DijkstraShortestPath();
        Vertex<Integer> sourceVertex = graph.getVertex(0);
        Map<Vertex<Integer>,Integer> distance = dsp.shortestPath(graph, sourceVertex);
        System.out.print(distance);
    }
}
