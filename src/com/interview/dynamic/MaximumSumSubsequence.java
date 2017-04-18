package com.interview.dynamic;

/**
 * Problem Statement:
 *
 * Given an array of n positive integers. Write a program to find the sum of maximum sum subsequence of the given array
 * such that the integers in the subsequence are in increasing order.
 *
 *
 * Video: https://youtu.be/99ssGWhLPUE
 *
 * Reference:
 * http://www.geeksforgeeks.org/dynamic-programming-set-14-maximum-sum-increasing-subsequence/
 */
public class MaximumSumSubsequence {

    public int maxSum(int arr[]){
        int T[] = new int[arr.length]; //stores max sequence
        int S[] = new int[arr.length]; //stores running sequence
        S[0] = -1; //0th index has no prior index. Prevents printing bug

        for (int i = 0; i < T.length; i++) {
            T[i] = arr[i]; //initialize with max value of single sequence
        }
        
        /* Compute maximum sum values in bottom up manner */
        for(int i=1; i < T.length; i++){
            for(int j = 0; j < i; j++){ 
                if(arr[j] < arr[i]){ // add value at j if it's less than value at i
                    if( T[j] + arr[i] > T[i]){ //keep max total
                        T[i] = T[j] + arr[i];
                        S[i] = j; //store index that was added to msis
                    }
                }
            } //restart j to 0 every time i increments
        }

        /* Pick maximum of all msis values */
        int max = T[0];
        int index = 0;
        for (int i=1; i < T.length; i++){
            if(T[i] > max){
                max = T[i];
                index = i;
            }
        }
        
        /* print sequence */
        Stack st = new Stack();
        while(true){
            st.push(arr[index]);
            index = S[index];
            if(index < 0) // exit condition
                break;
        }
        while(!st.empty()){
            System.out.print(st.pop() + " ");
        }
         System.out.println("");
            
        return max;
    }
    
    public static void main(String args[]){
        MaximumSumSubsequence mss = new MaximumSumSubsequence();
        int arr[] = {1, 101, 10, 2, 3, 100,4};
        int r = mss.maxSum(arr);
        System.out.print(r);
    }
}
