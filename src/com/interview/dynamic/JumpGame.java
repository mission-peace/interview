package com.interview.dynamic;

/**
 * Date 07/31/2016
 * @author Tushar Roy
 *
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 * Each element in the array represents your maximum jump length at that position.
 * Determine if you are able to reach the last index.
 *
 * Time complexity O(n)
 * Space complexity O(1)
 *
 * https://leetcode.com/problems/jump-game/
 */
public class JumpGame {

    public boolean canJump(int[] nums) {
        int jump = 0;
        int i;
        for (i = 0; i < nums.length && i <= jump; i++) {
            jump = Math.max(jump, i + nums[i]);
        }
        return i == nums.length;
    }

    public static void main(String args[]) {
        JumpGame jumpGame = new JumpGame();
        int[] nums = {3, 1};
        System.out.print(jumpGame.canJump(nums));
    }
}
