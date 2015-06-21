package com.interview.graph;

import java.util.HashSet;
import java.util.Set;

/**
 http://www.geeksforgeeks.org/union-find/
 It has both union-find and DFS way to find the cycle
 */
public class CycleUndirectedGraph<T> {

    public boolean hasCycle(Graph<T> graph){
        
        DisjointSet disjointSet = new DisjointSet();
        
        for(Vertex<T> vertex : graph.getAllVertex()){
            disjointSet.makeSet(vertex.getId());
        }
        
        for(Edge<T> edge : graph.getAllEdges()){
            long parent1 = disjointSet.findSet(edge.getVertex1().getId());
            long parent2 = disjointSet.findSet(edge.getVertex2().getId());
            if(parent1 == parent2){
                return true;
            }
            disjointSet.union(edge.getVertex1().getId(), edge.getVertex2().getId());
        }
        return false;
    }
    
    public boolean hasCycleDFS(Graph<T> graph){
        Set<Vertex<T>> visited = new HashSet<Vertex<T>>();
        for(Vertex<T> vertex : graph.getAllVertex()){
            if(visited.contains(vertex)){
                continue;
            }
            boolean flag = hasCycleDFSUtil(vertex, visited, null);
            if(flag){
                return true;
            }
        }
        return false;
    }
    
    public boolean hasCycleDFSUtil(Vertex<T> vertex, Set<Vertex<T>> visited,Vertex<T> parent){
        visited.add(vertex);
        for(Vertex<T> adj : vertex.getAdjacentVertexes()){
            if(adj.equals(parent)){
                continue;
            }
            if(visited.contains(adj)){
                return true;
            }
            boolean hasCycle = hasCycleDFSUtil(adj,visited,vertex);
            if(hasCycle){
                return true;
            }
        }
        return false;
    }
    
    public static void main(String args[]){
        
        CycleUndirectedGraph<Integer> cycle = new CycleUndirectedGraph<Integer>();
        Graph<Integer> graph = new Graph<Integer>(false);
        
        graph.addEdge(0, 1);
        graph.addEdge(1, 2);
        graph.addEdge(0, 3);
        graph.addEdge(3, 4);
        graph.addEdge(4, 5);
        graph.addEdge(5, 1);
        boolean isCycle = cycle.hasCycleDFS(graph);
        
        
        System.out.print(isCycle);
        
    }
    
}
