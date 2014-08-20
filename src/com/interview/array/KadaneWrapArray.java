package com.interview.array;

/**
 * http://www.geeksforgeeks.org/maximum-contiguous-circular-sum/
 * Test cases
 * All negative
 * All positives
 * all 0s
 */
public class KadaneWrapArray {

    public int kadaneWrap(int arr[]){
        int straightKadane = kadane(arr);
        int sum =0;
        for(int i=0; i < arr.length; i++){
            sum += Math.abs(arr[i]);
            arr[i] = -arr[i];
        }
        int wrappedNegKadane = kadane(arr);
        for(int i=0; i < arr.length; i++){
            arr[i] = -arr[i];
        }
        return Math.max(straightKadane, sum - wrappedNegKadane);
        
    }
    
    private int kadane(int arr[]){
        int sum =0;
        int maxSum = Integer.MIN_VALUE;
        for(int i=0; i < arr.length; i++){
            sum += arr[i];
            if(sum <= 0){
                sum = 0;
            }else{
                if(sum > maxSum){
                    maxSum = sum;
                }
            }
        }
        return maxSum;
    }
}
