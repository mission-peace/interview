package com.interview.graph;

import java.util.*;

/**
 * Date 11/17/2015
 * @author Tushar Roy
 *
 * Help Karp method of finding tour of traveling salesman.
 *
 * Time complexity - O(2^n * n^2)
 * Space complexity - O(2^n)
 *
 * https://en.wikipedia.org/wiki/Held%E2%80%93Karp_algorithm
 */
public class TravelingSalesmanHeldKarp {

    // big number treated as infinity. 
    // INTEGER_MAX may cause integer overflow with addition
    private static int INFINITY = 100000000;

    private static class Index {
        int currentVertex;
        Set<Integer> vertexSet;

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Index index = (Index) o;

            if (currentVertex != index.currentVertex) return false;
            return !(vertexSet != null ? !vertexSet.equals(index.vertexSet) : index.vertexSet != null);
        }

        @Override
        public int hashCode() {
            int result = currentVertex;
            result = 31 * result + (vertexSet != null ? vertexSet.hashCode() : 0);
            return result;
        }

        private static Index createIndex(int vertex, Set<Integer> vertexSet) {
            Index i = new Index();
            i.currentVertex = vertex;
            i.vertexSet = vertexSet;
            return i;
        }
    }

    private static class SetSizeComparator implements Comparator<Set<Integer>>{
        @Override
        public int compare(Set<Integer> o1, Set<Integer> o2) {
            return o1.size() - o2.size();
        }
    }

    // distance[startVertex][endVertex]'s value = edge weight
    public int minCost(int[][] distance) {

        /* stores intermediate values in map */
        // cost to reach current vertex from start vertex
        //  visiting all the vertices in the vertex set
        Map<Index, Integer> minCostDP = new HashMap<>();
        // stores vertex (from vertex set) immediately before parent
        //  which will yield minimum cost
        Map<Index, Integer> parent = new HashMap<>();

        // generate all combinations of n-1,
        // -1 to exclude starting/ending vertex
        List<Set<Integer>> allSets = generateCombination(distance.length - 1);

        // run calculation for every set
        for(Set<Integer> set : allSets) {
            // skip currentVertex=0 since it's the origin
            for(int currentVertex = 1; currentVertex < distance.length; currentVertex++) {
                if(set.contains(currentVertex)) { // skip itself
                    continue;
                }
                // create key for HashMap
                // index.currentVertex, index.vertexSet
                Index index = Index.createIndex(currentVertex, set);
                int minCost = INFINITY;
                int minPrevVertex = 0;
                //to avoid ConcurrentModificationException copy set into another set while iterating
                Set<Integer> copySet = new HashSet<>(set);
                for(int prevVertex : set) { //check every possible previous vertex
                    // cost of prevVertex to currentVertex
                    // + cost to reach previous vertex from generated sets
                    int cost = distance[prevVertex][currentVertex] + getCost(copySet, prevVertex, minCostDP);
                    if(cost < minCost) {
                        minCost = cost;
                        minPrevVertex = prevVertex;
                    }
                }
                //this happens for empty subset
                if(set.size() == 0) {
                    minCost = distance[0][currentVertex];
                }
                // save to HashMap
                minCostDP.put(index, minCost);
                parent.put(index, minPrevVertex);
            }
        }

        Set<Integer> set = new HashSet<>();
        for(int i=1; i < distance.length; i++) {
            set.add(i);
        }
        int min = Integer.MAX_VALUE;
        int prevVertex = -1;
        //to avoid ConcurrentModificationException copy set into another set while iterating
        Set<Integer> copySet = new HashSet<>(set);
        // calculate minimum cost of traveling salesman from tables
        for(int k : set) {
            int cost = distance[k][0] + getCost(copySet, k, minCostDP);
            if(cost < min) {
                min = cost;
                prevVertex = k;
            }
        }

        parent.put(Index.createIndex(0, set), prevVertex);
        printTour(parent, distance.length);
        return min;
    }

    private void printTour(Map<Index, Integer> parent, int totalVertices) {
        Set<Integer> set = new HashSet<>();
        for(int i=0; i < totalVertices; i++) {
            set.add(i);
        }
        Integer start = 0;
        Deque<Integer> stack = new LinkedList<>();
        while(true) {
            stack.push(start);
            set.remove(start);
            start = parent.get(Index.createIndex(start, set));
            if(start == null) {
                break;
            }
        }
        StringJoiner joiner = new StringJoiner("->");
        stack.forEach(v -> joiner.add(String.valueOf(v)));
        System.out.println("\nTSP tour");
        System.out.println(joiner.toString());
    }

    private int getCost(Set<Integer> set, int prevVertex, Map<Index, Integer> minCostDP) {
        set.remove(prevVertex);
        Index index = Index.createIndex(prevVertex, set);
        int cost = minCostDP.get(index);
        set.add(prevVertex);
        return cost;
    }

    // generate 2^n combinations possible
    private List<Set<Integer>> generateCombination(int n) {
        int input[] = new int[n];
        for(int i = 0; i < input.length; i++) {
            input[i] = i+1;
        }
        List<Set<Integer>> allSets = new ArrayList<>();
        int result[] = new int[input.length];
        generateCombination(input, 0, 0, allSets, result);
        Collections.sort(allSets, new SetSizeComparator());
        return allSets;
    }

    private void generateCombination(int input[], int start, int pos, List<Set<Integer>> allSets, int result[]) {
        if(pos == input.length) {
            return;
        }
        // generate set of size == pos
        Set<Integer> set = createSet(result, pos);
        allSets.add(set);
        for(int i=start; i < input.length; i++) {
            // iterate each input value through same result position
            result[pos] = input[i]; 
            // generate set for current result[pos]
            generateCombination(input, i+1, pos+1, allSets, result);
        }
    }

    private static Set<Integer> createSet(int[] result, int pos) {
        if(pos == 0) {
            return new HashSet<>(); // generate empty subset
        }
        Set<Integer> set = new HashSet<>();
        for(int i = 0; i < pos; i++) {
            set.add(result[i]);
        }
        return set;
    }
    
    // driver program to test above function
    public static void main(String[] args) {
        TravelingSalesmanHeldKarp tshk = new TravelingSalesmanHeldKarp();
        int[][] edges =  new int[][]{
                    {0, 1, 15, 6},
                    {2, 0, 7, 3},
                    {9, 6, 0, 12},
                    {10, 4, 8, 0}};
        int cost = tshk.minCost(edges);
        System.out.println("Min cost is " + cost);
    }
}
