package com.interview.graph;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

/**
 http://www.geeksforgeeks.org/strongly-connected-components/
 */
public class StronglyConnectedComponent {

    public List<Set<Vertex<Integer>>> scc(Graph<Integer> graph) {
        Deque<Vertex<Integer>> stack = new ArrayDeque<Vertex<Integer>>();
        Map<Vertex<Integer>, Boolean> visited = new HashMap<Vertex<Integer>, Boolean>();
        for (Vertex<Integer> vertex : graph.getAllVertex()) {
            if (visited.containsKey(vertex)) {
                continue;
            }
            DFSUtil(vertex, visited, stack);
        }

        System.out.println(stack);
        
        Graph<Integer> reverseGraph = new Graph<Integer>(true);
        Map<Long, Vertex<Integer>> vertexMap = new HashMap<Long, Vertex<Integer>>();
        for (Edge<Integer> edge : graph.getAllEdges()) {
            reverseGraph.addEdge(edge.getVertex2().getId(), edge.getVertex1()
                    .getId(), edge.getWeight());
        }
        
        for (Vertex<Integer> vertex : reverseGraph.getAllVertex()) {
            vertexMap.put(vertex.getId(), vertex);
        }
        
        visited.clear();
        List<Set<Vertex<Integer>>> result = new ArrayList<Set<Vertex<Integer>>>();
        while (!stack.isEmpty()) {
            Vertex<Integer> vertex = vertexMap.get(stack.poll().getId());
            if(visited.containsKey(vertex)){
                continue;
            }
            Set<Vertex<Integer>> set = new HashSet<Vertex<Integer>>();
            DFSUtil1(vertex, visited, set);
            result.add(set);
        }
        return result;
    }

    private void DFSUtil(Vertex<Integer> vertex,
            Map<Vertex<Integer>, Boolean> visited, Deque<Vertex<Integer>> stack) {
        visited.put(vertex, true);
        for (Vertex<Integer> v : vertex.getAdjacentVertexes()) {
            if (visited.containsKey(v)) {
                continue;
            }
            DFSUtil(v, visited, stack);
        }
        stack.offerFirst(vertex);
    }

    private void DFSUtil1(Vertex<Integer> vertex,
            Map<Vertex<Integer>, Boolean> visited, Set<Vertex<Integer>> set) {
        visited.put(vertex, true);
        set.add(vertex);
        for (Vertex<Integer> v : vertex.getAdjacentVertexes()) {
            if (visited.containsKey(v)) {
                continue;
            }
            DFSUtil1(v, visited, set);
        }
    }

    public static void main(String args[]){
        Graph<Integer> graph = new Graph<Integer>(true);
        graph.addEdge(1, 0);
        graph.addEdge(2,1);
        graph.addEdge(0,2);
        graph.addEdge(0, 3);
        graph.addEdge(3, 4);
        
        StronglyConnectedComponent scc = new StronglyConnectedComponent();
        List<Set<Vertex<Integer>>> result = scc.scc(graph);
        for(Set<Vertex<Integer>> set : result){
            System.out.println(set);
        }
    }
}
