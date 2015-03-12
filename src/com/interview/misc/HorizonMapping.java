package com.interview.misc;

import java.util.Deque;
import java.util.Iterator;
import java.util.LinkedList;

/**
 * http://www.glassdoor.com/Interview/Given-the-list-of-points-of-the-skyline-of-a-city-in-order-from-East-to-West-Find-the-maximal-rectangle-contained-in-this-QTN_27179.htm
 * http://www.glassdoor.com/Interview/Given-a-set-of-2D-coordinates-for-the-4-corners-of-each-building-in-a-city-skyline-as-if-in-a-photograph-how-would-you-d-QTN_345912.htm
 */
public class HorizonMapping {

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
    }

    public Deque<Interval> mergeInterval(Interval[] intervals) {
        Deque<Interval> stack = new LinkedList<Interval>();

        stack.offerFirst(intervals[0]);
        for (int i = 1; i < intervals.length; i++) {
            Interval curr = stack.peekFirst();
            if (curr.end < intervals[i].start) {
                stack.offerFirst(intervals[i]);
            } else if (curr.end >= intervals[i].start) {
                Interval newInterval = mergeOverlap(curr, intervals[i]);
                if (newInterval != null) {
                    stack.offerFirst(newInterval);
                }
            }
        }
        return stack;
    }

    private Interval mergeOverlap(Interval i1, Interval i2) {
        if(i1.start == i2.start && i1.end == i2.end){
            i1.height = Math.max(i1.height, i2.height);
            return null;
        }
        if (i1.start <= i2.start && i1.end >= i2.end) {
            if (i2.height > i1.height) {
                return i2;
            } else {
                return null;
            }
        }
        if(i1.height == i2.height)
        {
            i1.end = i2.end;
            return null;
        }else if(i1.height < i2.height){
            i1.end = i2.start;
            return i2;
        }else{
            return new Interval(i1.end, i2.end, i2.height);
        }
    }

    public static void main(String args[]) {
        Interval intervals[] = new Interval[6];
        intervals[0] = new Interval(0, 2, 3);
        intervals[1] = new Interval(2, 6, 3);
        intervals[2] = new Interval(4, 8, 8);
        intervals[3] = new Interval(5, 9, 10);
        intervals[4] = new Interval(6, 10, 9);
        intervals[5] = new Interval(7, 11, 8);
        HorizonMapping hm = new HorizonMapping();
        Deque<Interval> ll = hm.mergeInterval(intervals);
        Iterator<Interval> itr = ll.iterator();
        while (itr.hasNext()) {
            System.out.println(itr.next());
        }
    }
}
