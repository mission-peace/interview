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
 * Time complexity - O(V^3), row vertex * column vertex * through vertex
 * Space complexity - O(V^2), vertex matrix size
 *
 * References
 * https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm
 */
public class FloydWarshallAllPairShortestPath {

    class NegativeWeightCycleException extends RuntimeException {

    }

    // big number treated as infinity. 
    // INTEGER_MAX may cause integer overflow with addition
    private static final int INF = 1000000;

    public int[][] allPairShortestPath(int[][] distanceMatrix) {
        
        // distance from [row] to [column]
        // infinity means there is no path from [row] to [column]
        int distance[][] = new int[distanceMatrix.length][distanceMatrix.length];
        // vertex 'v' traversed to find shortest path 
        // corresponding to distance matrix
        int path[][] = new int[distanceMatrix.length][distanceMatrix.length];

        for (int r=0; r < distanceMatrix.length; r++) { //r: row
            for (int c=0; c< distanceMatrix[r].length; c++){ //c: column
                distance[r][c] = distanceMatrix[r][c];
                if (distanceMatrix[r][c] != INF && r != c) {
                    // initial path from [row] to [column] is row
                    path[r][c] = r;
                } else {
                    // path does not exist
                    path[r][c] = -1;
                }
            }
        }

        // check if going through vertex 'v' will give shorter distance
        for(int v=0; v < distanceMatrix.length; v++){ // v: vertex
            for(int r=0; r < distanceMatrix.length; r++){ //r: row
                for(int c=0; c < distanceMatrix.length; c++){ //c: column
                    if(distance[r][v] == INF || distance[v][c] == INF) {
                        // no path from rowVertex->vertex || vertex->columnVertex
                        continue;
                    }
                    if(distance[r][c] > distance[r][v] + distance[v][c]){
                        distance[r][c] = distance[r][v] + distance[v][c];
                        // copy vertex used to find shorter path
                        path[r][c] = path[v][c];
                    }
                }
            }
        }

        //look for negative weight cycle in the graph
        //if values on diagonal of distance matrix is negative
        //then there is negative weight cycle in the graph.
        // distance from vertex to itself should be 0
        for(int i = 0; i < distance.length; i++) {
            if(distance[i][i] < 0) {
                throw new NegativeWeightCycleException();
            }
        }

//        printPath(path, 3, 2);
        return distance;
    }

    public void printPath(int[][] path, int start, int end) {
        if(start < 0 || end < 0 
                || start >= path.length 
                || end >= path.length) {
            throw new IllegalArgumentException();
        }

        System.out.println("Actual path - between " + start + " " + end);
        Deque<Integer> stack = new LinkedList<>();
        stack.addFirst(end);
        while (true) {
            end = path[start][end];
            if(end == -1) {
                return;
            }
            stack.addFirst(end);
            if(end == start) {
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

        FloydWarshallAllPairShortestPath shortestPath = 
                new FloydWarshallAllPairShortestPath();
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
