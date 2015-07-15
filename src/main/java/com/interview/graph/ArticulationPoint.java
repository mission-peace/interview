package com.interview.graph;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/**
 http://www.geeksforgeeks.org/articulation-points-or-cut-vertices-in-a-graph/
 */
public class ArticulationPoint<T> {

    private int time;
    private Vertex<T> rootVertex;

    public Set<Vertex<T>> ap(Graph<T> graph) {

        Map<Vertex<T>, Boolean> visited = new HashMap<Vertex<T>, Boolean>();
        Set<Vertex<T>> articulationPoints = new HashSet<Vertex<T>>();
        Vertex<T> startVertex = graph.getAllVertex().iterator().next();
        Map<Vertex<T>, Integer> discoveryTime = new HashMap<Vertex<T>, Integer>();
        Map<Vertex<T>, Integer> minTime = new HashMap<Vertex<T>, Integer>();
        
        rootVertex = startVertex;
        DFS(visited,articulationPoints,startVertex,discoveryTime,minTime);
        
        return articulationPoints;
    }

    private void DFS(Map<Vertex<T>, Boolean> visited,
            Set<Vertex<T>> articulationPoints, Vertex<T> startVertex,
            Map<Vertex<T>, Integer> discoveryTime,
            Map<Vertex<T>, Integer> minTime) {
        visited.put(startVertex, true);
        discoveryTime.put(startVertex, time++);
        minTime.put(startVertex, time);
        int count =0;
        for(Vertex<T> adj : startVertex.getAdjacentVertexes()){
            if(!visited.containsKey(adj)){
                DFS(visited,articulationPoints,adj,discoveryTime,minTime);
                count++;
                if(startVertex.equals(rootVertex)){
                    if(count >= 2){
                        articulationPoints.add(startVertex);
                    }
                }
                else{
                    int lowTime = getTime(minTime,adj);
                    if(getTime(discoveryTime,startVertex) <= lowTime){
                        articulationPoints.add(startVertex);
                    }else{
                        minTime.put(startVertex,lowTime < getTime(minTime,startVertex) ? lowTime : getTime(minTime,startVertex));
                    }
                }
            }else{
                if(getTime(minTime,startVertex) > getTime(discoveryTime,adj)){
                    minTime.put(startVertex, getTime(discoveryTime,adj));
                }
            }
        }
        
    }
    
    private int getTime(Map<Vertex<T>,Integer> time,Vertex<T> vertex){
        return time.containsKey(vertex) ? time.get(vertex) : 1000;
    }

    public static void main(String args[]){
        Graph<Integer> graph = new Graph<Integer>(false);
        graph.addEdge(1,2);
        graph.addEdge(2, 3);
        graph.addEdge(1, 3);
        graph.addEdge(2, 4);
        graph.addEdge(4,5);
        graph.addEdge(5,6);
        graph.addEdge(6,4);
        graph.addEdge(6,2);
        ArticulationPoint<Integer> ap = new ArticulationPoint<Integer>();
        Set<Vertex<Integer>> aPoints = ap.ap(graph);
        System.out.println(aPoints);
    }
    
}
