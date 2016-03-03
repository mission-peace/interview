package com.interview.dynamic;

/**
 * Date 03/02/2016
 * @author Tushar Roy
 *
 * Time complexity O(n^3)
 * Space complexity O(n^2)
 * https://leetcode.com/problems/burst-balloons/
 */
public class BurstBalloons {
    public int maxCoins(int[] nums) {

        int T[][] = new int[nums.length][nums.length];

        for (int l = 1; l <= nums.length; l++) {
            for (int i = 0; i <= nums.length - l; i++) {
                int j = i + l - 1;
                int val = 0;
                for (int k = i; k <= j; k++) {
                    int left = 1;
                    int right = 1;
                    int before = 0;
                    if (i != k) {
                        before = T[i][k-1];
                    }
                    int after = 0;
                    if (j != k) {
                        after = T[k+1][j];
                    }
                    if (i != 0) {
                        left = nums[i-1];
                    }
                    if (j != nums.length -1) {
                        right = nums[j+1];
                    }
                    T[i][j] = Math.max(left*nums[k]*right + before + after, T[i][j]);
                }
            }
        }
        return T[0][nums.length - 1];
    }

    public int maxCoinsRec(int nums[]) {
        int[] nums1 = new int[nums.length + 2];
        nums1[0] = 1;
        nums1[nums1.length - 1] = 1;
        for (int i = 0; i < nums.length; i++) {
            nums1[i+1] = nums[i];
        }
        return maxCoinsRecUtil(nums1);
    }

    private int maxCoinsRecUtil(int[] nums) {
        if (nums.length == 2) {
            return 0;
        }

        int max = 0;
        for (int i = 1; i < nums.length - 1; i++) {
            int val = nums[i - 1]*nums[i]*nums[i+1] + maxCoinsRecUtil(formNewArray(nums, i));
            if (val > max) {
                max = val;
            }
         }
        return max;

    }

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
        int input[] = {3, 1, 5, 8};
        System.out.print(bb.maxCoins(input));
    }
}
