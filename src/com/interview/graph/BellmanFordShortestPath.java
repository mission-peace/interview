package com.interview.graph;

import java.util.HashMap;
import java.util.Map;

/**
 http://www.geeksforgeeks.org/dynamic-programming-set-23-bellman-ford-algorithm/
 */

public class BellmanFordShortestPath {

    @SuppressWarnings("serial")
    class CycleException extends RuntimeException{
        
    }
    
    public Map<Vertex<Integer>, Integer> getShortestPath(Graph<Integer> graph,
            Vertex<Integer> startVertex) {
        Map<Vertex<Integer>, Integer> distance = new HashMap<Vertex<Integer>, Integer>();
        distance.put(startVertex, 0);
        
        for(int i=0; i < graph.getAllVertex().size() -1 ; i++){
            for(Edge<Integer> edge : graph.getAllEdges()){
                Vertex<Integer> u = edge.getVertex1();
                Vertex<Integer> v = edge.getVertex2();
                if(getDistance(u,distance) > getDistance(v,distance) + edge.getWeight()){
                    distance.put(u, getDistance(v,distance) + edge.getWeight());
                }
                if(getDistance(v,distance) > getDistance(u,distance) + edge.getWeight()){
                    distance.put(v, getDistance(u,distance) + edge.getWeight());
                }
            }
        }
        
        for(Edge<Integer> edge : graph.getAllEdges()){
            Vertex<Integer> u = edge.getVertex1();
            Vertex<Integer> v = edge.getVertex2();
            if(getDistance(u,distance) > getDistance(v,distance) + edge.getWeight()){
                throw new CycleException();
            }
            if(getDistance(v,distance) > getDistance(u,distance) + edge.getWeight()){
                throw new CycleException();
            }
            
        }
        
        return distance;

    }

    private int getDistance(Vertex<Integer> v,
            Map<Vertex<Integer>, Integer> distance) {
        if (distance.containsKey(v)) {
            return distance.get(v);
        } else {
            return 10000;
        }
    }
    
    
    public static void main(String args[]){
        
        Graph<Integer> graph = new Graph<Integer>(false);
        graph.addEdge(1, 4,4);
        graph.addEdge(1, 2,3);
        graph.addEdge(2, 4,2);
        graph.addEdge(2, 3,3);
        graph.addEdge(3, 4,1);
        graph.addEdge(5, 4,1);
        graph.addEdge(3, 5,2);
        graph.addEdge(3, 6,1);
        graph.addEdge(5, 6,2);
        
        BellmanFordShortestPath shortestPath = new BellmanFordShortestPath();
        Vertex<Integer> startVertex = graph.getAllVertex().iterator().next();
        Map<Vertex<Integer>,Integer> distance = shortestPath.getShortestPath(graph, startVertex);
        System.out.println(startVertex);
        System.out.println(distance);
    }

}
