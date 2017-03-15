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
   Negative weight cycle is a cycle whose total weight is negative.
 *
 * Time complexity - O(EV)
     If running every source - O( V^2 * E)
     Worst Case: O(V^4) when 2 edges between every vertex, E = V^2. Floyd-Warshall's worst case is O(V^3)
 * Space complexity - O(V)
 *
 * References
 * https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm
 * http://www.geeksforgeeks.org/dynamic-programming-set-23-bellman-ford-algorithm/
 */

// find shortest distance from source to every other vertex
public class BellmanFordShortestPath {

    //some random big number is treated as infinity. I m not taking INTEGER_MAX as infinity because
    //doing any addition on that causes integer overflow
    private static int INFINITY = 10000000;

    class NegativeWeightCycleException extends RuntimeException {
    }
    
    public Map<Vertex<Integer>, Integer> getShortestPath(Graph<Integer> graph,
            Vertex<Integer> sourceVertex) {

        Map<Vertex<Integer>, Integer> distance = new HashMap<>();
        Map<Vertex<Integer>, Vertex<Integer>> parent = new HashMap<>();

        //set distance of every vertex to be infinity initially
        for(Vertex<Integer> v : graph.getAllVertex()) {
            distance.put(v, INFINITY);
            parent.put(v, null);
        }

        //set distance of source vertex to be 0
        distance.put(sourceVertex, 0);

        int V = graph.getAllVertex().size(); // total vertices in graph

        // Since the longest possible path (visiting all vertex) without a cycle can be V-1 edges
        // edges must be scanned V - 1 time to ensure all paths has been found to all nodes
        for (int i = 0; i < V - 1 ; i++) { //relax edges repeatedly V - 1 times 
            // go through all edges
            for (Edge<Integer> edge : graph.getAllEdges()) {
                Vertex<Integer> u = edge.getVertex1(); // start of edge
                Vertex<Integer> v = edge.getVertex2(); // end of edge
                //relax the edge
                //if we get better distance to v via u then use this distance
                //and set u as parent of v.
                if (distance.get(u) + edge.getWeight() < distance.get(v)) {
                    // update shortest path distance
                    distance.put(v, distance.get(u) + edge.getWeight());
                    parent.put(v, u); // update parent of shortest path
                }
            }
        }

        //relax all edges again. If we still get lesser distance it means
        //there is negative weight cycle in the graph. Throw exception in that
        //case
        for (Edge<Integer> edge : graph.getAllEdges()) {
            Vertex<Integer> u = edge.getVertex1();
            Vertex<Integer> v = edge.getVertex2();
            if (distance.get(u) + edge.getWeight() < distance.get(v)) {
                throw new NegativeWeightCycleException();
            }
        }
        return distance; // return distance map
    }

    public static void main(String args[]){
        
        Graph<Integer> graph = new Graph<>(false);
        graph.addEdge(0, 3, 8);
        graph.addEdge(0, 1, 4);
        graph.addEdge(0, 2, 5);
        graph.addEdge(1, 2, -3);
        graph.addEdge(2, 4, 4);
        graph.addEdge(3, 4, 2);
        graph.addEdge(4, 3, 1);

        BellmanFordShortestPath shortestPath = new BellmanFordShortestPath();
        Vertex<Integer> startVertex = graph.getAllVertex().iterator().next();
        Map<Vertex<Integer>,Integer> distance = shortestPath.getShortestPath(graph, startVertex);
        System.out.println(distance);
    }

}
