package com.interview.dynamic;

/**
 * http://www.geeksforgeeks.org/dynamic-programming-set-14-maximum-sum-increasing-subsequence/
 */
public class MaximumSumSubsequence {

    public int maxSum(int arr[]){
        int T[] = new int[arr.length+1];
        
        for(int i=1; i < T.length; i++){
            T[i] = arr[i-1];
        }
        
        for(int i=1; i < T.length; i++){
            for(int j = 1; j <i; j++){
                if(arr[i-1] > arr[j-1]){
                    T[i] = Math.max(T[i], T[j] + arr[i-1]);
                }
            }
        }
        
        int max = 0;
        for(int i=1; i <= arr.length; i++){
            if(T[i] > max){
                max = T[i];
            }
        }
        return max;
    }
    
    public static void main(String args[]){
        MaximumSumSubsequence mss = new MaximumSumSubsequence();
        int arr[] = {1,101,10,2,3,100,4};
        int r = mss.maxSum(arr);
        System.out.print(r);
    }
}
