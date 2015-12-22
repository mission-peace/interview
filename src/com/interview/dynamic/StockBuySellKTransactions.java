package com.interview.dynamic;

import java.util.Deque;
import java.util.LinkedList;

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
        printActualSolution(T, prices);
        return T[K][prices.length-1];
    }

    public void printActualSolution(int T[][], int prices[]) {
        int i = T.length - 1;
        int j = T[0].length - 1;

        Deque<Integer> stack = new LinkedList<>();
        while(true) {
            if(i == 0 || j == 0) {
                break;
            }
            if (T[i][j] == T[i][j-1]) {
                j = j - 1;
            } else {
                stack.addFirst(j);
                int maxDiff = T[i][j] - prices[j];
                for (int k = j-1; k >= 0; k--) {
                    if (T[i-1][k] - prices[k] == maxDiff) {
                        i = i - 1;
                        j = k;
                        stack.addFirst(j);
                        break;
                    }
                }
            }
        }

        while(!stack.isEmpty()) {
            System.out.println("Buy at price " + prices[stack.pollFirst()]);
            System.out.println("Sell at price " + prices[stack.pollFirst()]);
        }

    }

    public static void main(String args[]) {
        StockBuySellKTransactions sbt = new StockBuySellKTransactions();
        int prices[] = {3, 2, 4, 5, 1, 5, 2, 3};
        int prices1[] = {1, 4, 6, 5, 7};

        System.out.print("Max profit " + sbt.maxProfit(prices, 3));
    }
}
