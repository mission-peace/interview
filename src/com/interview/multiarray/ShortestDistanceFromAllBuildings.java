package com.interview.multiarray;

import java.util.ArrayList;
import java.util.Deque;
import java.util.LinkedList;
import java.util.List;

/**
 * Date 03/25/2016
 * @author Tushar Roy
 *
 * Shortest Distance from All Buildings
 * https://leetcode.com/problems/shortest-distance-from-all-buildings/
 */
public class ShortestDistanceFromAllBuildings {
    public int shortestDistance(int[][] grid) {
        int countBuilding = 0;
        List<Point> buildings = new ArrayList<>();
        for (int i = 0; i < grid.length ; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 1) {
                    countBuilding++;
                    buildings.add(new Point(i, j, 0));
                }
            }
        }

        if (countBuilding == 0) {
            return -1;
        }

        int[][] output = new int[grid.length][grid[0].length];
        int[][] reach = new int[grid.length][grid[0].length];
        for (Point building : buildings) {
            Deque<Point> queue = new LinkedList<>();
            queue.offerFirst(building);
            int currentBuildingCount = 0;
            boolean[][] visited = new boolean[output.length][output[0].length];
            visited[building.x][building.y] = true;
            while (!queue.isEmpty()) {
                Point p  = queue.pollLast();
                output[p.x][p.y] += p.d;
                List<Point> neighbors = neighbors(p, grid.length, grid[0].length);
                for (Point neighbor : neighbors) {
                    if (visited[neighbor.x][neighbor.y]) {
                        continue;
                    }
                    if (grid[neighbor.x][neighbor.y] == 1) {
                        currentBuildingCount++;
                    } else if (grid[neighbor.x][neighbor.y] != 2) {
                        queue.offerFirst(neighbor);
                        reach[neighbor.x][neighbor.y] += 1;
                    }
                    visited[neighbor.x][neighbor.y] = true;
                }
            }
            if (countBuilding - 1 != currentBuildingCount) {
                return -1;
            }
        }
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < output.length; i++) {
            for (int j = 0; j < output[0].length; j++) {
                if (reach[i][j] == countBuilding) {
                    min = Math.min(min, output[i][j]);
                }
            }
        }
        return min == Integer.MAX_VALUE ? -1 : min;
    }

    private List<Point> neighbors(Point p, int m, int n) {
        List<Point> neighbors = new ArrayList<>();
        if (p.y < n - 1) {
            neighbors.add(new Point(p.x, p.y + 1, p.d + 1));
        }
        if (p.x < m - 1) {
            neighbors.add(new Point(p.x + 1, p.y, p.d + 1));
        }
        if (p.x > 0) {
            neighbors.add(new Point(p.x - 1, p.y, p.d + 1));
        }
        if (p.y > 0) {
            neighbors.add(new Point(p.x, p.y - 1, p.d + 1));
        }
        return neighbors;
    }

    class Point {
        int x, y, d;
        Point(int x, int y, int d) {
            this.x = x;
            this.y = y;
            this.d = d;
        }
    }

    public static void main(String args[]) {
        int[][] grid = {{1, 0, 2, 0, 1}, {0, 0, 0, 0, 0}, {0, 0, 1, 0, 0}};
        int[][] grid1 = {{1,1},{0,1}};
        ShortestDistanceFromAllBuildings shortestDistanceFromAllBuildings = new ShortestDistanceFromAllBuildings();
        System.out.println(shortestDistanceFromAllBuildings.shortestDistance(grid));
    }

}
