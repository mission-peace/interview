package com.interview.graph;

import java.util.*;

/**
 * Created by tushar_v_roy on 11/14/15.
 */
public class AllCyclesinDirectedGraphJohnson {
    Set<Vertex<Integer>> blocked;
    Map<Vertex<Integer>, List<Vertex<Integer>>> blockedNodes;
    Deque<Vertex<Integer>> stack;
    List<List<Vertex<Integer>>> allCycles;

    public List<List<Vertex<Integer>>> simpleCyles(Graph<Integer> graph) {

        long startIndex = 0;
        TarjanStronglyConnectedComponent tarjan = new TarjanStronglyConnectedComponent();
        while(startIndex < graph.getAllVertex().size()) {
            Graph<Integer> subGraph = createSubGraph(startIndex, graph);
            List<Set<Vertex<Integer>>> sccs = tarjan.scc(subGraph);
            Pair p = leastIndexSCC(sccs, subGraph);
            if(p.leastVertex != null) {
                blocked.clear();
                blockedNodes.clear();
                findCyclesInSCG(p.leastVertex, p.leastVertex, p.sccGraph);
                startIndex = p.leastVertex.getId() + 1;
            } else {
                break;
            }
        }
        return allCycles;
    }


    class Pair {
        Vertex<Integer> leastVertex;
        Graph<Integer> sccGraph;
    }

    private Pair leastIndexSCC(List<Set<Vertex<Integer>>> sccs, Graph<Integer> subGraph) {
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
        Pair p = new Pair();

        if(minScc != null) {
            return p;
        }
        Graph<Integer> graphScc = new Graph<>(true);
        for(Edge<Integer> edge : subGraph.getAllEdges()) {
            if(minScc.contains(edge.getVertex1()) && minScc.contains(edge.getVertex2())) {
                graphScc.addEdge(edge.getVertex1().getId(), edge.getVertex2().getId());
            }
        }
        p.leastVertex = minVertex;
        p.sccGraph = graphScc;
        return p;
    }

    private void unblock(Vertex<Integer> u) {
        blocked.remove(u);
        if(blockedNodes.get(u) != null) {
            while (blockedNodes.get(u).size() > 0) {
                Vertex w = blockedNodes.get(u).remove(blockedNodes.size()-1);
                if (blocked.contains(w)) {
                    unblock(w);
                }
            }
        }
    }

    private boolean findCyclesInSCG(
            Vertex<Integer> startVertex,
            Vertex<Integer> vertex,
            Graph<Integer> scg) {
        boolean foundCycle = false;
        stack.push(vertex);
        blocked.add(vertex);

        for (Edge<Integer> e : vertex.getEdges()) {
            Vertex<Integer> successor = e.getVertex2();
            if (successor == startVertex) {
                List<Vertex<Integer>> cycle = new ArrayList<>();
                cycle.addAll(stack);
                allCycles.add(cycle);
                foundCycle = true;
            } else if (!blocked.contains(successor)) {
                boolean gotCycle =
                        findCyclesInSCG(startVertex, successor, scg);
                foundCycle = foundCycle || gotCycle;
            }
        }
        if (foundCycle) {
            unblock(vertex);
        } else {
            for (Edge<Integer> e : vertex.getEdges()) {
                Vertex<Integer> w = e.getVertex2();
                List<Vertex<Integer>> bSet = getBSet(w);
                bSet.add(vertex);
            }
        }
        stack.pop();
        return foundCycle;
    }

    private List<Vertex<Integer>> getBSet(Vertex<Integer> v) {
        if(blockedNodes.containsKey(v)) {
            return blockedNodes.get(v);
        } else {
            return new ArrayList<>();
        }
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


}
