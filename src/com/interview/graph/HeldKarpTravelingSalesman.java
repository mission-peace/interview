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
public class HeldKarpTravelingSalesman {

    private static class Index {
        int vertex;
        Set<Integer> vertexSet;

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Index index = (Index) o;

            if (vertex != index.vertex) return false;
            return !(vertexSet != null ? !vertexSet.equals(index.vertexSet) : index.vertexSet != null);

        }

        @Override
        public int hashCode() {
            int result = vertex;
            result = 31 * result + (vertexSet != null ? vertexSet.hashCode() : 0);
            return result;
        }
    }

    private static class SetSizeComparator implements Comparator<Set<Integer>>{
        @Override
        public int compare(Set<Integer> o1, Set<Integer> o2) {
            if(o1.size() <= o2.size()) {
                return -1;
            } else {
                return 1;
            }
        }
    }

    public int minCost(int[][] distance) {
        Map<Index, Integer> dp = new HashMap<>();
        Map<Index, Integer> parent = new HashMap<>();

        for(int i = 1; i < distance.length; i++) {
            Index index = createIndex(i, new HashSet<>());
            dp.put(index, distance[i][0]);
            parent.put(index, 1);
        }

        int input[] = new int[distance.length - 1];
        for(int i = 0; i < input.length; i++) {
            input[i] = i+1;
        }
        List<Set<Integer>> allSets = generateCombination(input);

        for(Set<Integer> set : allSets) {
            for(int i = 1; i < distance.length; i++) {
                if(set.contains(i)) {
                    continue;
                }
                Index index = createIndex(i, set);
                int min = Integer.MAX_VALUE;
                int minK = -1;
                for(int k : set) {
                    int val = distance[i][k] + get(set, k, dp);
                    if(val < min) {
                        min = val;
                        minK = k;
                    }
                }
                dp.put(index, min);
                parent.put(index, minK);
            }
        }

        Set<Integer> set = new HashSet<>();
        for(int i=1; i < distance.length; i++) {
            set.add(i);
        }
        int min = Integer.MAX_VALUE;
        int minK = -1;
        for(int k : set) {
            int val = distance[0][k] + get(set, k, dp);
            if(val < min) {
                min = val;
                minK = k;
            }
        }

        parent.put(createIndex(0, set), minK);

        printTour(parent, distance.length);

        return min;
    }

    private static Index createIndex(int vertex, Set<Integer> vertexSet) {
        Index i = new Index();
        i.vertex = vertex;
        i.vertexSet = vertexSet;
        return i;
    }

    private void printTour(Map<Index, Integer> parent, int totalVertices) {
        Set<Integer> set = new HashSet<>();
        for(int i=0; i < totalVertices; i++) {
            set.add(i);
        }
        int start = 0;
        Deque<Integer> stack = new LinkedList<>();
        while(set.size() > 0) {
            stack.push(start);
            set.remove(start);
            start = parent.get(createIndex(start, set));
            if(start == 0) {
                break;
            }
        }
        StringJoiner joiner = new StringJoiner("->");
        stack.push(0);
        stack.forEach(v ->
                        joiner.add(String.valueOf(v))
        );
        System.out.println("\nTSP tour");
        System.out.print(joiner.toString());
    }

    private int get(Set<Integer> set, int k, Map<Index, Integer> dp) {
        Set<Integer> newSet = new HashSet<>();
        for(int i : set) {
            if(i == k) {
                continue;
            }
            newSet.add(i);
        }
        Index index = createIndex(k, newSet);
        return dp.get(index);
    }

    private List<Set<Integer>> generateCombination(int input[]) {
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

        Set<Integer> set = createSet(result, pos);
        if(set != null) {
            allSets.add(set);
        }

        for(int i=start; i < input.length; i++) {
            result[pos] = input[i];
            generateCombination(input, i+1, pos+1, allSets, result);
        }
    }

    private static Set<Integer> createSet(int input[], int pos) {
        if(pos == 0) {
            return null;
        }
        Set<Integer> set = new HashSet<>();
        for(int i = 0; i < pos; i++) {
            set.add(input[i]);
        }
        return set;
    }

    public static void main(String args[]) {

        HeldKarpTravelingSalesman ht = new HeldKarpTravelingSalesman();
        int distance[][] = {{0, 2, 9, 10},
                    {1, 0, 6, 4},
                    {15, 7, 0, 8},
                    {6, 3, 12, 0},
                };

        ht.minCost(distance);
    }
}




