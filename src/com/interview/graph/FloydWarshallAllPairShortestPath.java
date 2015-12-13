package com.interview.graph;

import java.util.Deque;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;

/**
 * Date 11/02/2015
 * @author Tushar Roy
 *
 * Floyd-Warshall Algorithm for finding all pair shortest path.
 *
 * Time complexity - O(V^3)
 * Space complexity - O(V^2)
 *
 * References
 * https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm
 */
public class FloydWarshallAllPairShortestPath {

    class NegativeWeightCycleException extends RuntimeException {

    }

    private static final int INF = 1000000;

    public int[][] allPairShortestPath(int[][] distanceMatrix) {
        
        int distance[][] = new int[distanceMatrix.length][distanceMatrix.length];
        int path[][] = new int[distanceMatrix.length][distanceMatrix.length];

        for (int i=0; i < distanceMatrix.length; i++) {
            for (int j=0; j< distanceMatrix[i].length; j++){
                distance[i][j] = distanceMatrix[i][j];
                if (distanceMatrix[i][j] != INF && i != j) {
                    path[i][j] = i;
                } else {
                    path[i][j] = -1;
                }
            }
        }

        for(int k=0; k < distanceMatrix.length; k++){
            for(int i=0; i < distanceMatrix.length; i++){
                for(int j=0; j < distanceMatrix.length; j++){
                    if(distance[i][k] == INF || distance[k][j] == INF) {
                        continue;
                    }
                    if(distance[i][j] > distance[i][k] + distance[k][j]){
                        distance[i][j] = distance[i][k] + distance[k][j];
                        path[i][j] = path[k][j];
                    }
                }
            }
        }

        //look for negative weight cycle in the graph
        //if values on diagonal of distance matrix is negative
        //then there is negative weight cycle in the graph.
        for(int i = 0; i < distance.length; i++) {
            if(distance[i][i] < 0) {
                throw new NegativeWeightCycleException();
            }
        }

        printPath(path, 3, 2);
        return distance;
    }

    public void printPath(int[][] path, int i, int j) {
        if(i < 0 || j < 0 || i >= path.length || j >= path.length) {
            throw new IllegalArgumentException();
        }

        System.out.println("Actual path - between " + i + " " + j);
        Deque<Integer> stack = new LinkedList<>();
        stack.addFirst(j);
        while (true) {
            j = path[i][j];
            if(j == -1) {
                return;
            }
            stack.addFirst(j);
            if(j == i) {
                break;
            }
        }

        while (!stack.isEmpty()) {
            System.out.print(stack.pollFirst() + " ");
        }

        System.out.println();
    }

    public static void main(String args[]){
        int[][] graph = {
                {0,   3,   6,   15},
                {INF, 0,  -2,   INF},
                {INF, INF, 0,   2},
                {1,   INF, INF, 0}
        };

        FloydWarshallAllPairShortestPath shortestPath = new FloydWarshallAllPairShortestPath();
        int[][] distance = shortestPath.allPairShortestPath(graph);
        System.out.println("Minimum Distance matrix");
        for(int i=0; i < distance.length; i++){
            for(int j=0; j < distance.length; j++){
                System.out.print(distance[i][j] + " ");
            }
            System.out.println("");
        }
    }
}
