package com.interview.array;

/**
 * Date 12/31/2015
 * @author Tushar Roy
 *
 * Given an array of postive and negative numbers find max product subarray.
 *
 * Time complexity is O(n)
 * Space complexity is O(1)
 *
 * http://www.geeksforgeeks.org/maximum-product-subarray/
 */
public class MaxProductSubarray {

    public int maxProduct(int input[]){
        int maxEnding = 1;
        int minEnding = 1;
        int maxSoFar = 1;
        for (int i = 0; i < input.length; i++) {
            if (input[i] > 0) {
                maxEnding = maxEnding*input[i];
                minEnding = Math.min(minEnding*input[i], 1);
            } else if (input[i] == 0) {
                maxEnding = 1;
                minEnding = 1;
            } else {
                int t = maxEnding;
                maxEnding = Math.max(minEnding*input[i], 1);
                minEnding = t * input[i];
            }

            if (maxSoFar < maxEnding) {
                maxSoFar = maxEnding;
            }
        }
        return maxSoFar;
    }
    
    public static void main(String args[]){
        MaxProductSubarray mps = new MaxProductSubarray();
        int input[] = {-6,-3,8,-9,-1,-1,3,6,9,0,3,-1};
        System.out.println(mps.maxProduct(input));
    }
}
