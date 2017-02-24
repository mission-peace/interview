package com.interview.dynamic;

/**
 * http://www.geeksforgeeks.org/dynamic-programming-set-24-optimal-binary-search-tree/
 */
public class OptimalTreeSearch {

    // A recursive function to calculate cost of optimal binary search tree
    public int minCostRec(int[] keys, int[] freq) {

        return minCostRec(keys, freq, 0, keys.length - 1, 1);
    }

    private int minCostRec(int[] keys, int[] freq, int low, int high, int level) {
        // Base cases
        if (low > high) {   // If there are no elements in this subarray
            return 0;
        }
        if (low == high) {  // If there is one element in this subarray
            return freq[low]; 
        }

        // Initialize minimum value
        int min = Integer.MAX_VALUE;
        
        // Try making all keys 'k' in interval keys[low...high] as root
        for (int k = low; k <= high; k++) {
            int val = minCostRec(keys, freq, low, k - 1, level + 1) //add nodes before key
                    + minCostRec(keys, freq, k + 1, high, level + 1) //add nodes after key
                    + level * freq[k]; // add key
            if (val < min) { //keep best value
                min = val;
            }
        }
        return min;
    }

    /* A Dynamic Programming based function that calculates minimum cost of
       a Binary Search Tree. */
    public int minCost(int[] keys, int[] freq) {
        /* Create an auxiliary 2D matrix to store results of subproblems */
        int cost[][] = new int[keys.length][keys.length];

        /* cost[i][j] = Optimal cost of binary search tree that can be
           formed from input[i] to input[j].
           cost[0][n-1] will store the resultant cost */
        
        // For a single key, cost is equal to frequency of the key
        for (int i = 0; i < cost.length; i++) {
            cost[i][i] = freq[i];
        }
        
        // Now we need to consider chains of length 2, 3, ... .
        // L is chain length.
        for (int L = 2; L <= keys.length; L++) {
            
            // i is row number in cost[][]
            for (int i = 0; i <= keys.length - L; i++) {
                // Get column number j from row number i and chain length L
                int j = i + L - 1;
                cost[i][j] = Integer.MAX_VALUE;
                // get sum of array elements freq[i] to freq[j]
                int sum = getSum(freq, i, j);

                // Try making all keys 'k' in interval keys[i..j] as root
                for (int k = i; k <= j; k++) {
                    // val = value when when keys[k] becomes root of this subtree
                    int val = sum 
                            + (k - 1 < i ? 0 : cost[i][k - 1]) //add nodes before key
                            + (k + 1 > j ? 0 : cost[k + 1][j]); //add nodes after key
                    if (val < cost[i][j]) { //keep best value
                        cost[i][j] = val;
                    }
                }
            }
        }
        return cost[0][keys.length - 1];
    }

    // A utility function to get sum of array elements freq[i] to freq[j]
    private int getSum(int[] freq, int i, int j) {
        int sum = 0;
        for (int x = i; x <= j; x++) {
            sum += freq[x];
        }
        return sum;
    }

    // Driver program to test above functions
    public static void main(String args[]) {
        int input[] = {10, 12, 20, 35, 46};
        int freq[] = {34, 8, 50, 21, 16};
        OptimalTreeSearch ots = new OptimalTreeSearch();
        System.out.println(ots.minCost(input, freq));
        System.out.println(ots.minCostRec(input, freq));
    }
}
