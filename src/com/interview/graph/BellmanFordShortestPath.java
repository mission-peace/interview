package com.interview.graph;

import java.util.HashMap;
import java.util.Map;

/**
 * Date 11/05/2015
 * @author Tushar Roy
 *
 * Write program for Bellman Ford algorithm to find single source shortest path in directed graph.
 * Bellman ford works with negative edges as well unlike Dijksra's algorithm. If there is negative
 * weight cycle it detects it.
 *
 * Time complexity - O(EV)
 * Space complexity - O(V)
 *
 * References
 * https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm
 * http://www.geeksforgeeks.org/dynamic-programming-set-23-bellman-ford-algorithm/
 */

public class BellmanFordShortestPath {

    private static int INFINITY = 10000000;

    class CycleException extends RuntimeException {
    }
    
    public Map<Vertex<Integer>, Integer> getShortestPath(Graph<Integer> graph,
            Vertex<Integer> startVertex) {
        Map<Vertex<Integer>, Integer> distance = new HashMap<>();
        Map<Vertex<Integer>, Vertex<Integer>> predecessor = new HashMap<>();

        for(Vertex<Integer> v : graph.getAllVertex()) {
            distance.put(v, INFINITY);
            predecessor.put(v, null);
        }

        distance.put(startVertex, 0);

        int totalVertices = graph.getAllVertex().size() - 1;

        //relax edges repeatedly
        for (int i = 0; i < totalVertices ; i++) {
            for (Edge<Integer> edge : graph.getAllEdges()) {
                Vertex<Integer> u = edge.getVertex1();
                Vertex<Integer> v = edge.getVertex2();
                //if we get better distance to v via u then use this distance
                //and set u as predecessor of v.
                if (distance.get(u) + edge.getWeight() < distance.get(v)) {
                    distance.put(v, distance.get(u) + edge.getWeight());
                    predecessor.put(v, u);
                }
            }
        }

        //relax all edges again. If we still get better distance it means
        //there is negative weight cycle in the graph. Throw exception in that
        //case
        for (Edge<Integer> edge : graph.getAllEdges()) {
            Vertex<Integer> u = edge.getVertex1();
            Vertex<Integer> v = edge.getVertex2();
            if (distance.get(u) + edge.getWeight() < distance.get(v)) {
                throw new CycleException();
            }
        }
        return distance;
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
        System.out.println(distance);
    }

}
