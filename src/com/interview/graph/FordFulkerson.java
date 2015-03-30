package com.interview.graph;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;

/**
 http://www.geeksforgeeks.org/ford-fulkerson-algorithm-for-maximum-flow-problem/
 */
public class FordFulkerson<T> {

    public int maxFlow(Graph<T> graph, Vertex<T> s, Vertex<T>  t){
        
        int[][] matrix = new int[graph.getAllVertex().size()][graph.getAllVertex().size()];
        for(Edge<T> edge : graph.getAllEdges()){
            matrix[(int)edge.getVertex1().getId()][(int)edge.getVertex2().getId()] = edge.getWeight();
        }
        
        
        Map<Integer,Integer> parent = new HashMap<Integer,Integer>();
        
        int max_flow = 0;
        while(BFS(matrix,parent,(int)s.getId(),(int)t.getId())){
            
            int min_flow = 10000;
            int v = (int)t.getId();
            while(parent.containsKey(v)){
                int u = parent.get(v);
                if(min_flow > matrix[u][v]){
                    min_flow = matrix[u][v];
                }
                v = u;
            }
            
            max_flow += min_flow;
            
            v = (int)t.getId();
            while(parent.containsKey(v)){
                int u = parent.get(v);
                matrix[u][v] -= min_flow;
                matrix[v][u] += min_flow;
                v = u;
            }
        }
        return max_flow;
    }
    
    private boolean BFS(int[][] matrix, Map<Integer,Integer> parent,
            int s, int t){
        
        Map<Integer,Boolean> visited = new HashMap<Integer,Boolean>();
        Queue<Integer> queue = new LinkedList<Integer>();
        queue.add(s);
        visited.put(s, true);
        while(queue.size() != 0){
            int u = queue.poll();
            for(int v =0 ; v < matrix.length; v++){
                if(!visited.containsKey(v) && matrix[u][v] > 0){
                    parent.put(v, u);
                    if(v == t){
                        return true;
                    }
                    visited.put(v, true);
                    queue.add(v);
                }
            }
        }
        return false;
    }
    
    public static void main(String args[]){
        
        Graph<Integer> graph = new Graph<Integer>(true);
        
        Vertex<Integer> s = graph.addSingleVertex(0);
        Vertex<Integer> t = graph.addSingleVertex(7);
        graph.addEdge(0, 1,10);
        graph.addEdge(1, 2,9);
        graph.addEdge(2, 7,10);
        graph.addEdge(0, 3,5);
        graph.addEdge(3, 4,8);
        graph.addEdge(4, 7,10);
        graph.addEdge(0, 5,15);
        graph.addEdge(5, 6,16);
        graph.addEdge(6, 7,10);
        graph.addEdge(1, 3,4);
        graph.addEdge(3, 5,4);
        graph.addEdge(1, 4,15);
        graph.addEdge(2, 4,15);
        graph.addEdge(6, 3,6);
        graph.addEdge(4, 6,15);
        
        
        FordFulkerson<Integer> ff = new FordFulkerson<Integer>();
        int result = ff.maxFlow(graph, s, t);
        System.out.print(result);
    }
}
