package com.interview.array;

/**
 * http://www.geeksforgeeks.org/maximum-product-subarray/
 */
public class MaxProductSubarray {

    public int maxProduct(int input[]){
        int max = -1;
        int maxNeg = 1;
        int maxSoFar = 1;
        for(int i =0; i < input.length; i++){
            if(input[i] == 0){
                maxNeg = 1;
                maxSoFar = 1;
                continue;
            }
            if(input[i] < 0){
                maxSoFar = 1;
            }else{
                maxSoFar = maxSoFar * input[i];
            }
            maxNeg = maxNeg*input[i];
            if(max < maxNeg){
                max = maxNeg;
            }
            if(max < maxSoFar){
                max = maxSoFar;
            }
        }
        return max;
    }
    
    public static void main(String args[]){
        MaxProductSubarray mps = new MaxProductSubarray();
        int input[] = {-6,-3,8,-9,-1,-1,3,6,9,0,3,-1};
        System.out.println(mps.maxProduct(input));
    }
}
