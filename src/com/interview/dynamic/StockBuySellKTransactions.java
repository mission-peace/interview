package com.interview.dynamic;

/**
 * Date 12/22/2015
 * @author Tushar Roy
 *
 * Given stockc prices for certain days and at most k transactions how to buy and sell
 * to maximize profit.
 *
 * Time complexity - O(nk)
 * Space complexity - O(nk)
 *
 * https://leetcode.com/discuss/15153/a-clean-dp-solution-which-generalizes-to-k-transactions
 */
public class StockBuySellKTransactions {

    public int maxProfit(int prices[], int K) {
        int T[][] = new int[K+1][prices.length];

        for (int i = 1; i < T.length; i++) {
            int maxDiff = -prices[0];
            for (int j = 1; j < T[0].length; j++) {
                T[i][j] = Math.max(T[i][j-1], prices[j] + maxDiff);
                maxDiff = Math.max(maxDiff, T[i-1][j] - prices[j]);
            }
        }
        return T[K][prices.length-1];
    }

    public static void main(String args[]) {
        StockBuySellKTransactions sbt = new StockBuySellKTransactions();
        int prices[] = {3, 2, 4, 5, 1, 5, 2, 3};
        System.out.print(sbt.maxProfit(prices, 3));
    }
}
