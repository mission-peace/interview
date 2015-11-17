package com.interview.graph;

import java.util.*;

/**
 * Date 11/16/2015
 * @author Tushar Roy
 *
 * Find all cycles in directed graph using Johnson's algorithm
 *
 * Time complexity - (E + V).(c+1) where c is number of cycles found
 *
 * References
 * https://github.com/jgrapht/jgrapht/blob/master/jgrapht-core/src/main/java/org/jgrapht/alg/cycle/JohnsonSimpleCycles.java
 */
public class AllCyclesinDirectedGraphJohnson {
    Set<Vertex<Integer>> blocked;
    Map<Vertex<Integer>, Set<Vertex<Integer>>> blockedNodes;
    Deque<Vertex<Integer>> stack;
    List<List<Vertex<Integer>>> allCycles;

    public List<List<Vertex<Integer>>> simpleCyles(Graph<Integer> graph) {

        blocked = new HashSet<>();
        blockedNodes = new HashMap<>();
        stack = new LinkedList<>();
        allCycles = new ArrayList<>();
        long startIndex = 0;
        TarjanStronglyConnectedComponent tarjan = new TarjanStronglyConnectedComponent();
        while(startIndex < graph.getAllVertex().size()) {
            Graph<Integer> subGraph = createSubGraph(startIndex, graph);
            List<Set<Vertex<Integer>>> sccs = tarjan.scc(subGraph);
            Optional<Vertex<Integer>> maybeLeastVertex = leastIndexSCC(sccs, subGraph);
            if(maybeLeastVertex.isPresent()) {
                Vertex<Integer> leastVertex = maybeLeastVertex.get();
                blocked.clear();
                blockedNodes.clear();
                findCyclesInSCG(leastVertex, leastVertex);
                startIndex = leastVertex.getId() + 1;
            } else {
                break;
            }
        }
        return allCycles;
    }

   private Optional<Vertex<Integer>> leastIndexSCC(List<Set<Vertex<Integer>>> sccs, Graph<Integer> subGraph) {
        long min = Integer.MAX_VALUE;
        Vertex<Integer> minVertex = null;
        Set<Vertex<Integer>> minScc = null;
        for(Set<Vertex<Integer>> scc : sccs) {
            if(scc.size() == 1) {
                continue;
            }
            for(Vertex<Integer> vertex : scc) {
                if(vertex.getId() < min) {
                    min = vertex.getId();
                    minVertex = vertex;
                    minScc = scc;
                }
            }
        }

        if(minVertex == null) {
            return Optional.empty();
        }
        Graph<Integer> graphScc = new Graph<>(true);
        for(Edge<Integer> edge : subGraph.getAllEdges()) {
            if(minScc.contains(edge.getVertex1()) && minScc.contains(edge.getVertex2())) {
                graphScc.addEdge(edge.getVertex1().getId(), edge.getVertex2().getId());
            }
        }
        return Optional.of(graphScc.getVertex(minVertex.getId()));
    }

    private void unblock(Vertex<Integer> u) {
        blocked.remove(u);
        if(blockedNodes.get(u) != null) {
            blockedNodes.get(u).forEach( v -> {
                if(blocked.contains(v)) {
                    unblock(v);
                }
            });
            blockedNodes.remove(u);
        }
    }

    private boolean findCyclesInSCG(
            Vertex<Integer> startVertex,
            Vertex<Integer> vertex) {
        boolean foundCycle = false;
        stack.push(vertex);
        blocked.add(vertex);

        for (Edge<Integer> e : vertex.getEdges()) {
            Vertex<Integer> successor = e.getVertex2();
            if (successor == startVertex) {

                List<Vertex<Integer>> cycle = new ArrayList<>();
                stack.push(startVertex);
                cycle.addAll(stack);
                stack.pop();
                allCycles.add(cycle);
                foundCycle = true;
            } else if (!blocked.contains(successor)) {
                boolean gotCycle =
                        findCyclesInSCG(startVertex, successor);
                foundCycle = foundCycle || gotCycle;
            }
        }
        if (foundCycle) {
            unblock(vertex);
        } else {
            for (Edge<Integer> e : vertex.getEdges()) {
                Vertex<Integer> w = e.getVertex2();
                Set<Vertex<Integer>> bSet = getBSet(w);
                bSet.add(vertex);
            }
        }
        stack.pop();
        return foundCycle;
    }

    private Set<Vertex<Integer>> getBSet(Vertex<Integer> v) {
        return blockedNodes.computeIfAbsent(v, (key) ->
            new HashSet<>() );
    }

    private Graph createSubGraph(long startVertex, Graph<Integer> graph) {
        Graph<Integer> subGraph = new Graph<>(true);
        for(Edge<Integer> edge : graph.getAllEdges()) {
            if(edge.getVertex1().getId() >= startVertex && edge.getVertex2().getId() >= startVertex) {
                subGraph.addEdge(edge.getVertex1().getId(), edge.getVertex2().getId());
            }
        }
        return subGraph;
    }

    public static void main(String args[]) {
        AllCyclesinDirectedGraphJohnson johnson = new AllCyclesinDirectedGraphJohnson();
        Graph<Integer> graph = new Graph<>(true);
        graph.addEdge(0, 1);
        graph.addEdge(1, 4);
        graph.addEdge(1, 7);
        graph.addEdge(1, 6);
        graph.addEdge(4, 2);
        graph.addEdge(4, 3);
        graph.addEdge(2, 4);
        graph.addEdge(2, 7);
        graph.addEdge(2, 6);
        graph.addEdge(7, 8);
        graph.addEdge(7, 5);
        graph.addEdge(5, 2);
        graph.addEdge(5, 3);
        graph.addEdge(3, 7);
        graph.addEdge(3, 6);
        graph.addEdge(3, 4);
        graph.addEdge(6, 5);
        graph.addEdge(6, 8);

        List<List<Vertex<Integer>>> allCycles = johnson.simpleCyles(graph);
        allCycles.forEach(cycle -> { cycle.forEach(vertex -> {
            System.out.print(vertex.getId() + " ");
        });
        System.out.println();});
    }

}
