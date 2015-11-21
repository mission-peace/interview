package com.interview.geometry;

import java.util.*;

/**
 * Created by tushar_v_roy on 11/19/15.
 */
public class SkylineDrawing {

    static class Position {
        int pos;
        int height;
    }

    static class CriticalPoint implements Comparable<CriticalPoint> {
        int point;
        boolean isStart;
        Interval interval;

        @Override
        public int compareTo(CriticalPoint o) {

            if(this.point < o.point) {
                return -1;
            } else if(this.point > o.point) {
                return 1;
            } else {
                if(this.isStart && !o.isStart) {
                    return -1;
                } else if(!this.isStart && o.isStart) {
                    return 1;
                } else if(this.isStart && o.isStart) {
                    if(this.interval.height >= o.interval.height) {
                        return -1;
                    } else {
                        return 1;
                    }
                } else {
                    if(this.interval.height <= o.interval.height) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            }
        }


     }

    static class Interval {
        int start;
        int end;
        int height;

        public Interval(int start, int end, int height) {
            this.start = start;
            this.end = end;
            this.height = height;
        }

        public String toString() {
            return start + " " + end + " " + height;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Interval interval = (Interval) o;

            if (start != interval.start) return false;
            if (end != interval.end) return false;
            return height == interval.height;

        }

        @Override
        public int hashCode() {
            int result = start;
            result = 31 * result + end;
            result = 31 * result + height;
            return result;
        }
    }

    class HeightComparator implements Comparator<CriticalPoint> {
        @Override
        public int compare(CriticalPoint o1, CriticalPoint o2) {
            if(o1.interval.height < o2.interval.height) {
                return -1;
            } else if(o1.interval.height > o2.interval.height) {
                return 1;
            } else {
                if(o1.interval.start == o2.interval.start && o1.interval.end == o2.interval.end) {
                    return 0;
                } else if(o1.interval.start < o2.interval.start) {
                    return -1;
                } else if(o1.interval.start > o2.interval.start){
                    return 1;
                } else if(o1.interval.end < o2.interval.end) {
                    return -1;
                } else {
                    return 1;
                }
            }
        }
    }
    public List<Position> mapSkyline(Interval[] intervals) {
        Set<Interval> uniqueInterval = new HashSet<>();
        uniqueInterval.addAll(Arrays.asList(intervals));

        CriticalPoint[] criticalPoints = new CriticalPoint[uniqueInterval.size()*2];
        int index = 0;
        for(Interval interval : uniqueInterval) {
            criticalPoints[index] = new CriticalPoint();
            criticalPoints[index].point = interval.start;
            criticalPoints[index].isStart = true;
            criticalPoints[index].interval = interval;

            criticalPoints[index + 1] = new CriticalPoint();
            criticalPoints[index + 1].point = interval.end;
            criticalPoints[index + 1].isStart = false;
            criticalPoints[index + 1].interval = interval;

            index += 2;
        }
        Arrays.sort(criticalPoints);

        TreeSet<CriticalPoint> treeSet = new TreeSet<>(new HeightComparator());
        List<Position> finalResult = new ArrayList<>();
        for(CriticalPoint cp : criticalPoints) {
            if(cp.isStart) {
                if(treeSet.isEmpty() || treeSet.last().interval.height < cp.interval.height) {
                    finalResult.add(createPosition(cp.point, cp.interval.height));
                }
                treeSet.add(cp);
            } else {
                treeSet.remove(cp);
                if(treeSet.isEmpty()) {
                    finalResult.add(createPosition(cp.point, 0));
                } else if(treeSet.last().interval.height < cp.interval.height) {
                    finalResult.add(createPosition(cp.point, treeSet.last().interval.height));
                }
            }
        }
        return finalResult;
    }

    Position createPosition(int pos, int height) {
        Position p = new Position();
        p.pos = pos;
        p.height = height;
        return p;
    }

    public static void main(String args[]) {
       /* Interval interval0 = new Interval(0, 4, 5);
        Interval interval1 = new Interval(6, 9, 2);
        Interval interval2 = new Interval(1, 3, 4);
        Interval interval3 = new Interval(3, 5, 4);
        Interval interval4 = new Interval(7, 8, 6);
        Interval[] intervals = new Interval[5];
        intervals[0] = interval1;
        intervals[1] = interval0;
        intervals[2] = interval2;
        intervals[3] = interval3;
        intervals[4] = interval4;*/

        //int[][] buildings = {{1,2,1},{1,2,2},{1,2,3}};
        int [][] buildings = {{0,3,3},{1,5,3},{2,4,3},{3,7,3}};
        Interval[] intervals = new Interval[buildings.length];
        for(int i=0; i < buildings.length; i++) {
            intervals[i] = new Interval(buildings[i][0], buildings[i][1], buildings[i][2]);
        }
        SkylineDrawing sd = new SkylineDrawing();
        List<Position> finalResult = sd.mapSkyline(intervals);

    }
}
