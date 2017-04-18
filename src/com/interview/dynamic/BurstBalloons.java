package com.interview.dynamic;

/**
 * Date 03/02/2016
 * @author Tushar Roy
 *
 * Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented
 * by array nums. You are asked to burst all the balloons. If the you burst balloon i you will
 * get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst,
 * the left and right then becomes adjacent.
 * Find the maximum coins you can collect by bursting the balloons wisely.
 *
 * Time complexity O(n^3)
 * Space complexity O(n^2)
 *
 * Reference
 * https://leetcode.com/problems/burst-balloons/
 */
public class BurstBalloons {

    /**
     * Bottom up Dynamic programming solution.
     * Space complexity: O(n^2) for matrix
     * Time complexity: O(n^3), 2 loops for matrix, 1 loop to optimize subsequence
     */
    public int maxBalloonBottomUpDp(int[] nums) {

        int T[][] = new int[nums.length][nums.length];

        for (int len = 1; len <= nums.length; len++) {
            for (int s = 0; s <= nums.length - len; s++) { // s: start index
                int e = s + len - 1; // e: end index relative to subsequence length
                // k cuts the length (1') subsequence into a 2' subsequence
                // matrix stores the values of length (1') subsequence from s-e
                // 1' subsequence == 2' subsequence before k + 2' subsequence after k
                // + (balloon before length * balloon k * balloon after length)
                for (int k = s; k <= e; k++) { // k: last balloon to burst
                    //leftValue/rightValue is initially 1. If there is element on
                    // left/right of k then left/right value will take that value.
                    int leftValue = 1; //balloon value to left
                    int rightValue = 1; // balloon value to right
                    if (s != 0) {
                        leftValue = nums[s-1]; // balloon before length
                    }
                    if (e != nums.length -1) {
                        rightValue = nums[e+1]; // balloon after length
                    }

                    //before is initially 0. If k is i then before will
                    //stay 0 otherwise it gets value T[i][k-1]
                    //after is similarly 0 initially. if k is j then after will
                    //stay 0 other will get value T[k+1][j]
                    //subsequence range must fall within bottom-up length
                    int before = 0; // subsequence before k
                    int after = 0; // subsequence after k
                    if (s != k) {
                        before = T[s][k-1];
                    }
                    if (e != k) {
                        after = T[k+1][e];
                    }
                    // keep previous max, or save current last balloon 'k'
                    T[s][e] = Math.max(T[s][e], 
                            leftValue * nums[k] * rightValue + before + after);
                }
            }
        }
        return T[0][nums.length - 1];
    }

    /**
     * Recursive solution.
     */
    public int maxBalloonRec(int nums[]) {
        //insert 1 before && after array for edge cases calculations
        int[] nums1 = new int[nums.length + 2];
        nums1[0] = 1;
        nums1[nums1.length - 1] = 1;
        for (int i = 0; i < nums.length; i++) {
            nums1[i+1] = nums[i];
        }
        return maxBalloonRecUtil(nums1);
    }

    private int maxBalloonRecUtil(int[] nums) {
        if (nums.length == 2) { // last 2 array 1s inserted for edge cases
            return 0; //base case
        }

        int max = 0;
        // recurse array, excluding outside 1s
        for (int i = 1; i < nums.length - 1; i++) {
            int val = nums[i - 1] * nums[i] * nums[i+1] 
                    + maxBalloonRecUtil(formNewArray(nums, i));
            if (val > max) { //save best value
                max = val;
            }
         }
        return max;

    }

    // remove bursted balloon
    private int[] formNewArray(int[] input, int doNotIncludeIndex) {
        int[] newArray = new int[input.length - 1];
        int index = 0;
        for (int i = 0; i < input.length; i++) {
            if (i == doNotIncludeIndex) {
                continue;
            }
            newArray[index++] = input[i];
        }
        return newArray;
    }


    public static void main(String args[]) {
        BurstBalloons bb = new BurstBalloons();
        int input[] = {2, 4, 3, 5};
        System.out.print(bb.maxBalloonBottomUpDp(input));
    }
}
