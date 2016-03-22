package com.interview.misc;

import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

/**
 * Date 03/21/2016
 * @author Tushar Roy
 *
 * Insert internal into sorted intervals and merge them.
 *
 * Time complexity O(n)
 *
 * https://leetcode.com/problems/insert-interval/
 */
public class InsertInterval {

    public static class Interval {
        int start;
        int end;

        @Override
        public String toString() {
            return "Interval{" +
                    "start=" + start +
                    ", end=" + end +
                    '}';
        }

        Interval(int s, int e) { start = s; end = e; }
    }

    class BinarySearchResult {
        int low;
        int high;
    }

    public List<Interval> insertBinarySearchBased(List<Interval> intervals, Interval newInterval) {
        if (intervals.size() == 0) {
            return Collections.singletonList(newInterval);
        }

        if (newInterval.start > intervals.get(intervals.size() - 1).end) {
            intervals.add(newInterval);
            return intervals;
        }

        if (newInterval.end < intervals.get(0).start) {
            intervals.add(0, newInterval);
            return intervals;
        }

        BinarySearchResult bsr1 = search(intervals, newInterval.start);
        BinarySearchResult bsr2 = search(intervals, newInterval.end);

        System.out.println(bsr1.low + " " + bsr1.high);
        System.out.println(bsr2.low + " " + bsr2.high);

        List<Interval> result = new ArrayList<>();
        int low1 = bsr1.low == bsr1.high ? bsr1.low - 1 : bsr1.low;
        for (int i = 0; i <= low1; i++) {
            result.add(intervals.get(i));
        }

        if (bsr1.low == bsr1.high && bsr2.low == bsr2.high) {
            result.add(new Interval(intervals.get(bsr1.low).start, intervals.get(bsr2.high).end));
        } else if (bsr1.low != bsr1.high && bsr2.low == bsr2.high) {
            result.add(new Interval(newInterval.start, intervals.get(bsr2.high).end));
        } else if (bsr1.low == bsr1.high && bsr2.low != bsr2.high) {
            result.add(new Interval(intervals.get(bsr1.low).start, newInterval.end));
        } else {
            result.add(newInterval);
        }
        int high = bsr2.low == bsr2.high ? bsr2.high + 1 : bsr2.high;
        for (int i = high; i < intervals.size(); i++) {
            result.add(intervals.get(i));
        }
        return result;
    }

    private BinarySearchResult search(List<Interval> intervals, int val) {
        int start = 0;
        int end = intervals.size() - 1;
        BinarySearchResult bsr = new BinarySearchResult();
        while (start <= end) {
            int middle = (start + end)/2;

            Interval middleInterval = intervals.get(middle);

            if (middleInterval.end >= val && middleInterval.start <= val) {
                bsr.low = middle;
                bsr.high = middle;
                return bsr;
            }

            if (middleInterval.start > val && (middle == 0 || intervals.get(middle - 1).end < val)) {
                bsr.low = middle - 1;
                bsr.high = middle;
                return bsr;
            }

            if (middleInterval.end < val && (middle == intervals.size() - 1 || intervals.get(middle + 1).start > val)) {
                bsr.low = middle;
                bsr.high = middle + 1;
                return bsr;
            }

            if (middleInterval.start > val) {
                end = middle - 1;
            } else {
                start = middle + 1;
            }
        }
        throw new IllegalArgumentException("This should not happen");
    }


    public List<Interval> insert(List<Interval> intervals, Interval newInterval) {
        List<Interval> result = new LinkedList<>();
        int i = 0;
        while (i < intervals.size() && intervals.get(i).end < newInterval.start)
            result.add(intervals.get(i++));
        while (i < intervals.size() && intervals.get(i).start <= newInterval.end) {
            newInterval = new Interval( // we could mutate newInterval here also
                    Math.min(newInterval.start, intervals.get(i).start),
                    Math.max(newInterval.end, intervals.get(i).end));
            i++;
        }
        result.add(newInterval);
        while (i < intervals.size()) result.add(intervals.get(i++));
        return result;
    }

    public static void main(String args[]) {
        Interval i1 = new Interval(1,3);
        Interval i2 = new Interval(6,7);
        Interval i3 = new Interval(9,10);
        Interval i4 = new Interval(11,12);
        List<Interval> input = new ArrayList<>();
        input.add(i1);
        input.add(i2);
        input.add(i3);
        input.add(i4);
        InsertInterval ii = new InsertInterval();
        System.out.println(ii.insert(input, new Interval(13, 15)));
    }
}
