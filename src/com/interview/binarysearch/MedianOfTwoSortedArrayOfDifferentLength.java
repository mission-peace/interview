package com.interview.binarysearch;

/**
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 *
 * Solution
 * Take minimum size of two array. Possible number of cuts are from 0 to m in m size array.
 * Try every cut in binary search way. When you cut first array at i then you cut second array at (m + n + 1)/2 - i
 * Now try to find the i where a[i-1] <= b[j] and b[j-1] <= a[i]. So this i is the answerr
 *
 * Time complexity is O(log(min(m,n))
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/
 * https://discuss.leetcode.com/topic/4996/share-my-o-log-min-m-n-solution-with-explanation/4
 */
public class MedianOfTwoSortedArrayOfDifferentLength {
    public double findMedianSortedArrays(int input1[], int input2[]) {
        if (input1.length > input2.length) {
            return findMedianSortedArrays(input2, input1);
        }
        if (input1.length == 0) {
            return getMedian(input2);
        }
        int m = input1.length;
        int n = input2.length;

        int low = 0;
        int high = m;
        while (low <= high) {
            int cut1 = (low + high)/2;
            int cut2 = (m + n + 1)/2 - cut1;

            int a1 = (cut1 == 0) ? Integer.MIN_VALUE : input1[cut1 - 1];
            int a2 = (cut1 == m) ? Integer.MAX_VALUE : input1[cut1];

            int b1 = (cut2 == 0) ? Integer.MIN_VALUE : input2[cut2 - 1];
            int b2 = (cut2 == n) ? Integer.MAX_VALUE : input2[cut2];

            if (a1 <= b2 && b1 <= a2) {
                if ((m + n) % 2 == 0) {
                    return ((double)Math.max(a1, b1) + Math.min(a2, b2))/2;
                } else {
                    return (double)Math.max(a1, b1);
                }
            } else if (a1 > b2) {
                high = cut1 - 1;
            } else {
                low = cut1 + 1;
            }
        }
        throw new IllegalArgumentException();
    }

    private double getMedian(int arr[]){
        if(arr.length % 2 == 0){
            return ((double)arr[arr.length/2 - 1] + arr[arr.length/2])/2;
        } else {
            return arr[arr.length/2];
        }
    }
}
