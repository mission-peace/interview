package com.interview.dynamic;

/**
 * https://leetcode.com/problems/perfect-squares/
 */
public class MinimumNumberOfPerfectSquares {
    public int numSquares(int n) {
        int count = (int)Math.ceil(Math.sqrt(n));

        int[] T = new int[n + 1];

        T[0] = 0;

        for (int i = 1; i < T.length; i++) {
            T[i] = Integer.MAX_VALUE;
            for (int j = 1; j <= count; j++) {
                if (i < j*j) {
                    break;
                }
                T[i] = Math.min(T[i], T[i - j*j] + 1);
            }
        }
        return T[n];
    }
}
