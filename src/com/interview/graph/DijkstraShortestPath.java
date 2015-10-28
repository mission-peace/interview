package com.interview.graph;

import com.interview.recursion.InterpretationOfArray;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/**
 * http://www.geeksforgeeks.org/greedy-algorithms-set-7-dijkstras-algorithm-for-adjacency-list-representation/
 */
public class DijkstraShortestPath {

    public Map<Vertex<Integer>,Integer> shortestPath(Graph<Integer> graph, Vertex<Integer> sourceVertex){

        //heap + map data structure
        BinaryMinHeap<Vertex<Integer>> minHeap = new BinaryMinHeap<>();

        //stores shortest distance from root to every vertex
        Map<Vertex<Integer>,Integer> distance = new HashMap<>();

        //stores parent of every vertex in shortest distance
        Map<Vertex<Integer>, Vertex<Integer>> parent = new HashMap<>();

        //initialize all vertex with infinite distance from source vertex
        for(Vertex<Integer> vertex : graph.getAllVertex()){
            minHeap.add(Integer.MAX_VALUE, vertex);
        }

        //set distance of source vertex to 0
        minHeap.decrease(sourceVertex, 0);

        //put it in map
        distance.put(sourceVertex, 0);

        //source vertex parent is null
        parent.put(sourceVertex, null);

        //iterate till heap is not empty
        while(!minHeap.empty()){
            //get the min value from heap node which has vertex and distance of that vertex from source vertex.
            BinaryMinHeap<Vertex<Integer>>.Node heapNode = minHeap.extractMinNode();
            Vertex<Integer> current = heapNode.key;

            //update shortest distance of current vertex from source vertex
            distance.put(current, heapNode.weight);

            //iterate through all edges of current vertex
            for(Edge<Integer> edge : current.getEdges()){

                //get the adjacent vertex
                Vertex<Integer> adjacent = getVertexForEdge(current, edge);

                //if heap does not contain adjacent vertex means adjacent vertex already has shortest distance from source vertex
                if(!minHeap.containsData(adjacent)){
                    continue;
                }

                //add distance of current vertex to edge weight to get distance of adjacent vertex from source vertex
                //when it goes through current vertex
                int newDistance = distance.get(current) + edge.getWeight();

                //see if this above calculated distance is less than current distance stored for adjacent vertex from source vertex
                if(minHeap.getWeight(adjacent) > newDistance) {
                    minHeap.decrease(adjacent, newDistance);
                    parent.put(adjacent, current);
                }
            }
        }
        return distance;
    }

    private Vertex<Integer> getVertexForEdge(Vertex<Integer> v, Edge<Integer> e){
        return e.getVertex1().equals(v) ? e.getVertex2() : e.getVertex1();
    }
    
    public static void main(String args[]){
        Graph<Integer> graph = new Graph<>(false);
        /*graph.addEdge(0, 1, 4);
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
        graph.addEdge(7, 8, 7);*/

        graph.addEdge(1, 2, 5);
        graph.addEdge(2, 3, 2);
        graph.addEdge(1, 4, 9);
        graph.addEdge(1, 5, 3);
        graph.addEdge(5, 6, 2);
        graph.addEdge(6, 4, 2);
        graph.addEdge(3, 4, 3);

        
        DijkstraShortestPath dsp = new DijkstraShortestPath();
        Vertex<Integer> sourceVertex = graph.getVertex(1);
        Map<Vertex<Integer>,Integer> distance = dsp.shortestPath(graph, sourceVertex);
        System.out.print(distance);
    }
}
