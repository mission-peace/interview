package com.interview.graph;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/**
 * http://www.geeksforgeeks.org/detect-cycle-in-a-graph/
 * It has both stack and back edge(gray vertex) method.
 */
public class CycleInDirectedGraph {

    enum Color{
        GRAY,
        BLACK,
        WHITE;
    }
    
    private boolean isCyclicUtil(Vertex<Integer> vertex, Set<Long> visited, Set<Long> currentStack){
        visited.add(vertex.getId());
        currentStack.add(vertex.getId());
        for(Vertex<Integer> v : vertex.getAdjacentVertexes()){
            if(currentStack.contains(v.getId())){
                return true;
            }else{
                boolean result = isCyclicUtil(v,visited,currentStack);
                if(result){
                    return true;
                }
            }
        }
        currentStack.remove(vertex.getId());
        return false;
    }
    
    public boolean isCyclic(Graph<Integer> graph){
        
        Set<Long> visited = new HashSet<Long>();
        Set<Long> currentStack = new HashSet<Long>();
        for(Vertex<Integer> v : graph.getAllVertex()){
            if(!visited.contains(v.getId())){
                boolean result = isCyclicUtil(v,visited,currentStack);
                if(result){
                    return true;
                }
            }
        }
        return false;
        
    }
    
    private boolean isCyclicBackEdgeMethodUtil(Vertex<Integer> v,Map<Vertex<Integer>,Color> visited){
        if(visited.get(v) == Color.GRAY){
            return true;
        }
        visited.put(v, Color.GRAY);
        for(Vertex<Integer> u : v.getAdjacentVertexes()){
            boolean result = isCyclicBackEdgeMethodUtil(u, visited);
            if(result){
                return true;
            }
        }
        visited.put(v,Color.BLACK);
        return false;
            
    }
    
    public boolean isCyclicBackEdgeMethod(Graph<Integer> graph){
        Map<Vertex<Integer>,Color> visited = new HashMap<Vertex<Integer>,Color>();
        for(Vertex<Integer> v : graph.getAllVertex()){
            visited.put(v, Color.WHITE);
        }
        for(Vertex<Integer> v : graph.getAllVertex()){
            if(visited.get(v) == Color.WHITE){
                boolean result = isCyclicBackEdgeMethodUtil(v,visited);
                if(result){
                    return true;
                }
            }
        }
        return false;
    }

    public static void main(String args[]){
        Graph<Integer> graph = new Graph<Integer>(true);
        graph.addEdge(1, 2);
        graph.addEdge(1, 3);
        graph.addEdge(3, 4);
        graph.addEdge(4, 5);
        graph.addEdge(2, 5);
        graph.addEdge(5, 3);
        CycleInDirectedGraph cdg = new CycleInDirectedGraph();
        System.out.println(cdg.isCyclicBackEdgeMethod(graph));
    }
}
