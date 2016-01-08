package com.interview.geometry;

import java.util.*;

/**
 * Date 01/07/2016
 * @author Tushar Roy
 *
 * Given skyline of a city merge the buildings
 *
 * Time complexity is O(nlogn)
 * Space complexity is O(n)
 *
 * References
 * https://leetcode.com/problems/the-skyline-problem/
 * https://leetcode.com/discuss/67091/once-for-all-explanation-with-clean-java-code-nlog-time-space
 */
public class SkylineDrawing {

    /**
     * Represents either start or end of building
     */
    static class BuildingPoint implements Comparable<BuildingPoint> {
        int point;
        boolean isStart;
        int height;

        @Override
        public int compareTo(BuildingPoint o) {
            //first compare by point.
            //If they are same then use this logic
            //if two starts are compared then higher height building should be picked first
            //if two ends are compared then lower height building should be picked first
            //if one start and end is compared then start should appear before end
            if (this.point != o.point) {
                return this.point - o.point;
            } else {
                return (this.isStart ? -this.height : this.height) - (o.isStart ? -o.height : o.height);
            }
        }
     }

    public List<int[]> getSkyline(int[][] buildings) {

        //for all start and end of building put them into List of BuildingPoint
        BuildingPoint[] buildingPoints = new BuildingPoint[buildings.length*2];
        int index = 0;
        for(int building[] : buildings) {
            buildingPoints[index] = new BuildingPoint();
            buildingPoints[index].point = building[0];
            buildingPoints[index].isStart = true;
            buildingPoints[index].height = building[2];

            buildingPoints[index + 1] = new BuildingPoint();
            buildingPoints[index + 1].point = building[1];
            buildingPoints[index + 1].isStart = false;
            buildingPoints[index + 1].height = building[2];
            index += 2;
        }
        Arrays.sort(buildingPoints);

        //using TreeMap because it gives log time performance.
        //PriorityQueue in java does not support remove(object) operation in log time.
        TreeMap<Integer, Integer> queue = new TreeMap<>();
        queue.put(0, 1);
        int prevMaxHeight = 0;
        List<int[]> criticalPoints = new ArrayList<>();
        for(BuildingPoint cp : buildingPoints) {
            //if it is start of building then add the height to map. If height already exists then increment
            //the value
            if (cp.isStart) {
                queue.compute(cp.height, (key, value) -> {
                   if (value != null) {
                       return value + 1;
                   }
                    return 1;
                });
            } else { //if it is end of building then decrement or remove the height from map.
                queue.compute(cp.height, (key, value) -> {
                    if (value == 1) {
                        return null;
                    }
                    return value - 1;
                });
            }
            //peek the current height after addition or removal of building point.
            int currentMaxHeight = queue.lastKey();
            //if height changes from previous height then this building point becomes critcal point.
            // So add it to the result.
            if (prevMaxHeight != currentMaxHeight) {
                criticalPoints.add(new int[]{cp.point, currentMaxHeight});
                prevMaxHeight = currentMaxHeight;
            }
        }
        return criticalPoints;
    }

    public static void main(String args[]) {
        int [][] buildings = {{0,3,3},{1,5,3},{2,4,3},{3,7,3}};
        SkylineDrawing sd = new SkylineDrawing();
        List<int[]> criticalPoints = sd.getSkyline(buildings);
        criticalPoints.forEach(cp -> System.out.println(cp[0] + " " + cp[1]));

    }
}
