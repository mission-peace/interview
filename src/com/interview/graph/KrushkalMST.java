package com.interview.graph;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

/**
 http://www.geeksforgeeks.org/greedy-algorithms-set-2-kruskals-minimum-spanning-tree-mst/
 */
public class KrushkalMST {

    public class EdgeComparator implements Comparator<Edge<Integer>>{

        @Override
        public int compare(Edge<Integer> edge1, Edge<Integer> edge2) {
            if(edge1.getWeight() <= edge2.getWeight()){
                return -1;
            }else{
                return 1;
            }
        }
        
    }
    
    public List<Edge<Integer>> getMST(Graph<Integer> graph){
        
        List<Edge<Integer>> allEdges = graph.getAllEdges();
        EdgeComparator edgeComparator = new EdgeComparator();
        Collections.sort(allEdges, edgeComparator);
        DisjointSet disjointSet = new DisjointSet();
        
        for(Vertex<Integer> vertex : graph.getAllVertex()){
            disjointSet.makeSet(vertex.getId());
        }
        
        List<Edge<Integer>> resultEdge = new ArrayList<Edge<Integer>>();
        
        for(Edge<Integer> edge : allEdges){
            long root1 = disjointSet.findSet(edge.getVertex1().getId());
            long root2 = disjointSet.findSet(edge.getVertex2().getId());
            if(root1 == root2){
                continue;
            }else{
                resultEdge.add(edge);
                disjointSet.union(edge.getVertex1().getId(), edge.getVertex2().getId());
            }
            
        }
        return resultEdge;
    }
    
    public static void main(String args[]){
        
        Graph<Integer> graph = new Graph<Integer>(false);
        graph.addEdge(1,2, 4);
        graph.addEdge(1,3, 1);
        graph.addEdge(2,5, 1);
        graph.addEdge(2,6, 3);
        graph.addEdge(2,4, 2);
        graph.addEdge(6,5, 2);
        graph.addEdge(6,4, 3);
        graph.addEdge(4,7, 2);
        graph.addEdge(3,4, 5);
        graph.addEdge(3,7, 8);
        
        KrushkalMST mst = new KrushkalMST();
        List<Edge<Integer>> result = mst.getMST(graph);
        for(Edge<Integer> edge : result){
            System.out.println(edge.getVertex1() + " " + edge.getVertex2());
        }
    }
}
