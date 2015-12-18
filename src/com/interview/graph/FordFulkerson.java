package com.interview.graph;

import java.util.*;

/**
 * Date 04/14/2014
 * @author Tushar Roy
 *
 * Ford fulkerson method edmonds karp algorithm for finding max flow
 *
 * Time complexity is O(VE^2)
 *
 * References:
 * http://www.geeksforgeeks.org/ford-fulkerson-algorithm-for-maximum-flow-problem/
 * https://en.wikipedia.org/wiki/Edmonds%E2%80%93Karp_algorithm
 */
public class FordFulkerson {

    public int maxFlow(int capacity[][], int s, int t){
        int flow[][] = new int[capacity.length][capacity[0].length];
        Map<Integer,Integer> parent = new HashMap<>();
        int maxFlow = 0;
        while(true){
            int minCapacity = BFS(capacity, flow, parent, s, t);
            if(minCapacity == 0) {
                break;
            }
            maxFlow += minCapacity;

            int v = t;
            while(v != s){
                int u = parent.get(v);
                flow[u][v] += minCapacity;
                flow[v][u] -= minCapacity;
                v = u;
            }
        }
        return maxFlow;
    }
    
    private int BFS(int[][] capacity, int[][] flow, Map<Integer,Integer> parent,
            int s, int t){

        Set<Integer> visited = new HashSet<>();
        Queue<Integer> queue = new LinkedList<>();
        Map<Integer, Integer> minCapacity = new HashMap<>();
        queue.add(s);
        visited.add(s);
        minCapacity.put(s, Integer.MAX_VALUE);
        while(!queue.isEmpty()){
            int u = queue.poll();
            for(int v = 0; v < flow.length; v++){
                int residualCapacity = capacity[u][v] - flow[u][v];
                if(!visited.contains(v) &&  residualCapacity > 0){
                    parent.put(v, u);
                    if (residualCapacity < minCapacity.get(u)) {
                        minCapacity.put(v, residualCapacity);
                    } else {
                        minCapacity.put(v, minCapacity.get(u));
                    }
                    if(v == t){
                        return minCapacity.get(t);
                    }
                    visited.add(v);
                    queue.add(v);
                }
            }
        }
        return 0;
    }
    
    public static void main(String args[]){
        FordFulkerson ff = new FordFulkerson();
        int[][] capacity = {{0, 3, 0, 3, 0, 0, 0},
                            {0, 0, 4, 0, 0, 0, 0},
                            {3, 0, 0, 1, 2, 0, 0},
                            {0, 0, 0, 0, 2, 6, 0},
                            {0, 1, 0, 0, 0, 0, 1},
                            {0, 0, 0, 0, 0, 0, 9},
                            {0, 0, 0, 0, 0, 0, 0}};

        int [][] capacity1 = {{0, 16, 13, 0, 0, 0},
                            {0, 0, 10, 12, 0, 0},
                            {0, 4, 0, 0, 14, 0},
                            {0, 0, 9, 0, 0, 20},
                            {0, 0, 0, 7, 0, 4},
                            {0, 0, 0, 0, 0, 0}};
        System.out.print("Maximum capacity " + ff.maxFlow(capacity1, 0, 5));
    }
}
