package com.interview.graph;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;

/**
 * http://www.geeksforgeeks.org/greedy-algorithms-set-5-prims-mst-for-adjacency-list-representation/
 */
public class PrimMST {

    public Collection<Edge<Integer>> mst(Graph<Integer> graph){
        
        Vertex<Integer> startVertex = graph.getAllVertex().iterator().next();
        Map<Vertex<Integer>,Edge<Integer>> mstEdges = new HashMap<Vertex<Integer>,Edge<Integer>>();
        BinaryMinHeap<Vertex<Integer>> minHeap = new BinaryMinHeap<Vertex<Integer>>();
        for(Vertex<Integer> v : graph.getAllVertex()){
            minHeap.add(1000, v);
        }
        Map<Vertex<Integer>,Integer> key = new HashMap<Vertex<Integer>,Integer>();
        minHeap.decrease(startVertex,0);
        key.put(startVertex, 0);
        while(!minHeap.empty()){
            Vertex<Integer> u = minHeap.extractMin();
            for(Edge<Integer> e : u.getEdges()){
                Vertex<Integer> v = getVertexForEdge(u, e);
                if(minHeap.containsData(v) && key(key,v) > e.getWeight()){
                    key.put(v,e.getWeight());
                    minHeap.decrease(v, e.getWeight());
                    mstEdges.put(v, e);
                }
            }
        }
        return mstEdges.values();
    }
    
    private Vertex<Integer> getVertexForEdge(Vertex<Integer> v, Edge<Integer> e){
        return e.getVertex1().equals(v) ? e.getVertex2() : e.getVertex1();
    }

    private int key(Map<Vertex<Integer>,Integer> distance, Vertex<Integer> key){
        return distance.containsKey(key) ? distance.get(key) : 1000;
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
    
        PrimMST prims = new PrimMST();
        Collection<Edge<Integer>> edges = prims.mst(graph);
        for(Edge<Integer> edge : edges){
            System.out.println(edge);
        }
    }
    
    
}
