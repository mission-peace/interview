package com.interview.dynamic;

/**
 * http://www.geeksforgeeks.org/maximum-sum-such-that-no-two-elements-are-
 * adjacent/
 */
public class MaxSumForNonAdjacentElements {

    public int maxSum(int arr[]) {
        int excl = 0;
        int incl = arr[0];
        for (int i = 1; i < arr.length; i++) {
            int temp = incl;
            incl = Math.max(excl + arr[i], incl);
            excl = temp;
        }
        return incl;
    }

    public static void main(String args[]) {
        MaxSumForNonAdjacentElements msn = new MaxSumForNonAdjacentElements();
        int arr[] = { 2, 10, 3, 4, 15, 10 };
        System.out.println(msn.maxSum(arr));
    }
}
