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
 * Time complexity - O(number of transactions * number of days)
 * Space complexity - O(number of transcations * number of days)
 *
 * https://leetcode.com/discuss/15153/a-clean-dp-solution-which-generalizes-to-k-transactions
 */
public class StockBuySellKTransactions {

    /**
     * Below solution is accepted by leetcode and runs in space proportional to prices length.
     */
    public int maxProfitLinearSpace(int k, int[] prices) {
        if (k == 0 || prices.length == 0) {
            return 0;
        }

        if (k >= prices.length) {
            return allTimeProfit(prices);
        }
        int[] T = new int[prices.length];
        int[] prev = new int[prices.length];
        for (int i = 1; i <= k; i++) {
            int maxDiff = -prices[0];
            for (int j = 1; j < prices.length; j++) {
                T[j] = Math.max(T[j - 1], maxDiff + prices[j]);
                maxDiff = Math.max(maxDiff, prev[j] - prices[j]);
            }
            for (int j = 1; j < prices.length; j++) {
                prev[j] = T[j];
            }
        }
        return T[T.length - 1];
    }

    public int allTimeProfit(int arr[]){
        int profit = 0;
        int localMin = arr[0];
        for(int i=1; i < arr.length;i++){
            if(arr[i-1] >= arr[i]){
                localMin = arr[i];
            }else{
                profit += arr[i] - localMin;
                localMin = arr[i];
            }

        }
        return profit;
    }

    /**
     * This is faster method which does optimization on slower method
     * Time complexity here is O(K * number of days)
     *
     * Formula is
     * T[i][j] = max(T[i][j-1], prices[j] + maxDiff)
     * maxDiff = max(maxDiff, T[i-1][j] - prices[j])
     * 
     * K is maximum number of transaction
     */
    public int maxProfit(int prices[], int K) {
        if (K == 0 || prices.length == 0) {
            return 0;
        }
        // fill matix in bottom up manner
        // rows are transactions
        // columns are days
        int T[][] = new int[K+1][prices.length];
        /* Everything in a valid Java program not explicitly set 
         * to something by the programmer, is initialized to a zero value.
         * row 0: 0 transaction yields 0 profit
         * column 0: no profit possible on 0th day */
        for (int t = 1; t < T.length; t++) { // t: transaction
            // initial best profit is buying on day 0, which is negative price
            int bestPro = -prices[0]; //best profit possible
            for (int d = 1; d < T[0].length; d++) { // d: day
                // T[t][d-1] is no transaction on dth day (value of prior day)
                // prices[d] is profit if sold this day plus best prior profits 
                T[t][d] = Math.max(T[t][d-1], prices[d] + bestPro); // fill matrix
                // T[t-1][d] - prices[d] takes maxProfit of -1 transaction, 
                // subtract price if bought this day and keep max
                bestPro = Math.max(bestPro, T[t-1][d] - prices[d]); 
            } // day increments so bestPro belongs to all days prior
        }
        printActualSolution(T, prices);
        return T[K][prices.length-1];
    }

    /**
     * This is slow method but easier to understand.
     * Time complexity is O(k * number of days ^ 2)
     * T[i][j] = max(T[i][j-1], max(prices[j] - prices[m] + T[i-1][m])) where m is 0...j-1
     */
    public int maxProfitSlowSolution(int prices[], int K) {
        if (K == 0 || prices.length == 0) {
            return 0;
        }
        int T[][] = new int[K+1][prices.length];

        for (int t = 1; t < T.length; t++) {
            for (int d = 1; d < T[0].length; d++) {
                int maxVal = 0;
                for (int m = 0; m < d; m++) { 
                    // buy on mth day, sell on dth day
                    // plus best possible profit from transactions ending on day m
                    maxVal = Math.max(maxVal, prices[d] - prices[m] + T[t-1][m]);
                }
                // max(no transaction on dth day, best profit with transaction on dth day)
                T[t][d] = Math.max(T[t][d-1], maxVal);
            }
        }
        printActualSolution(T, prices);
        return T[K][prices.length - 1];
    }

    public void printActualSolution(int T[][], int prices[]) {
        int t = T.length - 1; //transaction initialized to last row
        int d = T[0].length - 1; //day initialized to last column

        Deque<Integer> stack = new LinkedList<>();
        while(true) {
            if(t == 0 || d == 0) {
                break;
            }
            // find day when profit changes
            // this is where sell occurs
            if (T[t][d] == T[t][d-1]) { 
                d = d - 1;
            } else {
                stack.addFirst(d); //save sell date
                int bestPro = T[t][d] - prices[d];
                for (int k = d-1; k >= 0; k--) {
                    // find where maxProfit - price == bestProfit
                    if (T[t-1][k] - prices[k] == bestPro) { 
                        t = t - 1; // move to previous transaction row
                        d = k;
                        stack.addFirst(d); //save purchase date
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
        int prices[] = {2, 5, 7, 1, 4, 3, 1, 3};

        System.out.println("Max profit fast solution " + sbt.maxProfit(prices, 3));
        System.out.println("Max profit slow solution " + sbt.maxProfitSlowSolution(prices, 3));
    }
}
