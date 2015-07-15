package com.interview.graph;

import java.util.HashMap;
import java.util.Map;

/**
 * http://www.geeksforgeeks.org/dynamic-programming-set-16-floyd-warshall-algorithm/
 */
public class FloydWarshallAllPairShortestPath {

    public int[][] allPairShortestPath(int[][] graph){
        
        int distance[][] = new int[graph.length][graph.length];
        
        for(int i=0; i < graph.length; i++){
            for(int j=0; j< graph.length; j++){
                distance[i][j] = graph[i][j];
            }
                
        }
        
        for(int i=0; i < graph.length; i++){
            for(int j=0; j < graph.length; j++){
                for(int k=0; k < graph.length; k++){
                    if(distance[i][j] > distance[i][k] + distance[k][j]){
                        distance[i][j] = distance[i][k] + distance[k][j];
                    }
                }
            }
        }
        return distance;
    }
    class Pair{
        Vertex<Integer> v1;
        Vertex<Integer> v2;
        @Override
        public int hashCode() {
            final int prime = 31;
            int result = 1;
            result = prime * result + getOuterType().hashCode();
            result = prime * result + ((v1 == null) ? 0 : v1.hashCode());
            result = prime * result + ((v2 == null) ? 0 : v2.hashCode());
            return result;
        }
        @Override
        public boolean equals(Object obj) {
            if (this == obj)
                return true;
            if (obj == null)
                return false;
            if (getClass() != obj.getClass())
                return false;
            Pair other = (Pair) obj;
            if (!getOuterType().equals(other.getOuterType()))
                return false;
            if (v1 == null) {
                if (other.v1 != null)
                    return false;
            } else if (!v1.equals(other.v1))
                return false;
            if (v2 == null) {
                if (other.v2 != null)
                    return false;
            } else if (!v2.equals(other.v2))
                return false;
            return true;
        }
        private FloydWarshallAllPairShortestPath getOuterType() {
            return FloydWarshallAllPairShortestPath.this;
        }
        
        public String toString(){
            return v1.getId() + " " + v2.getId();
        }
    }
    public Map<Pair,Integer> allPairShortestPath(Graph<Integer> graph){
        Map<Pair,Integer> distance = new HashMap<Pair,Integer>();
        for(Edge<Integer> e : graph.getAllEdges()){
            updateDistance(e.getVertex1(), e.getVertex2(), distance, e.getWeight());
        }
        
        for(Vertex<Integer> v : graph.getAllVertex()){
            updateDistance(v,v,distance,0);
        }
        
        for (Vertex<Integer> v : graph.getAllVertex()) {
            for (Vertex<Integer> u : graph.getAllVertex()) {
                for(Vertex<Integer> v1 : graph.getAllVertex()){
                    if (getDistance(u, v1, distance) > getDistance(
                            u, v, distance)
                            + getDistance(v, v1, distance)) {
                        updateDistance(
                                u,
                                v1,
                                distance,
                                getDistance(u, v, distance)
                                        + getDistance(v, v1,
                                                distance));
                    }
                }
            }
        }
        return distance;
    }
    private void updateDistance(Vertex<Integer> v1,Vertex<Integer> v2,Map<Pair,Integer> distance,int weight){
        Pair p = new Pair();
        p.v1 = v1;
        p.v2 = v2;
        distance.put(p, weight);
    }
    
    private int getDistance(Vertex<Integer> v1,Vertex<Integer> v2,Map<Pair,Integer> distance){
        Pair p = new Pair();
        p.v1 = v1;
        p.v2 = v2;
        return distance.get(p) != null ? distance.get(p) : 1000;
    }
    
    
    
    public static void main(String args[]){
        int[][] graph = {
                            {0,2,1000,1,1000},
                            {1000,0,3,1,1000},
                            {1000,1000,0,1000,1000},
                            {3,1000,3,0,2},
                            {1000,1000,3,1000,0},
                        };  
                    
        FloydWarshallAllPairShortestPath shortestPath = new FloydWarshallAllPairShortestPath();
        int[][] distance = shortestPath.allPairShortestPath(graph);
        for(int i=0; i < distance.length; i++){
            for(int j=0; j < distance.length; j++){
                System.out.print(distance[i][j] + " ");
            }
            System.out.println("");
        }
        
        Graph<Integer> rGraph = new Graph<Integer>(true);
        rGraph.addEdge(0, 1, 2);
        rGraph.addEdge(0, 3, 1);
        rGraph.addEdge(1, 2, 3);
        rGraph.addEdge(1, 3, 1);
        rGraph.addEdge(3, 0, 3);
        rGraph.addEdge(3, 2, 3);
        rGraph.addEdge(3, 4, 2);
        rGraph.addEdge(4, 2, 3);
        Map<Pair,Integer> rdistance = shortestPath.allPairShortestPath(rGraph);
        for(Pair p : rdistance.keySet()){
            System.out.println(p + " " + rdistance.get(p));
        }
                    
    }
}
