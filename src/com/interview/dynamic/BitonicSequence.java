package com.interview.dynamic;

/**
 * http://www.geeksforgeeks.org/dynamic-programming-set-15-longest-bitonic-subsequence/
 */
public class BitonicSequence {

    /* lbs() returns the length of the Longest Bitonic Subsequence in arr[]
    The function mainly creates two temporary arrays lis[] and lds[] 
    that stores the greatest 1-way sequence and returns the maximum lis[i] + lds[i] - 1.
    -1 to adjust for value at i being count twice.
 
    lis[i] ==> Longest Increasing subsequence ending with arr[i]
    lds[i] ==> Longest decreasing subsequence starting with arr[i]
    */
    public int longestSequence(int arr[]){
        int lis[] = new int[arr.length];
        int lds[] = new int[arr.length];
        // initialize minimum sequence as 1 for all indexes
        for(int i=0; i < arr.length; i++){
            lis[i] = 1;
            lds[i] = 1;
        }
        
        /* Compute LIS values from left to right */
        for(int i=1 ; i < arr.length; i++){ //leftmost will always be 1
            for(int j=0; j < i ; j++){ //reset whenever i increments
                if(arr[i] > arr[j]){ //keep best sequence
                    lis[i] = Math.max(lis[i], lis[j] + 1);
                }
            } //best sequence up to arr[i] found, increment i
        }
        
        /* Compute LDS values from right to left */
        for(int i = arr.length-2; i >=0 ; i--){ //rightmost will always be 1
            for(int j = arr.length-1; j > i; j--){ //reset whenever i increments
                if(arr[i] > arr[j]){ //keep best sequence
                    lds[i] = Math.max(lds[i], lds[j] + 1);
                }
            } //best sequence up to arr[i] found, increment i
        }
        
        /* Return the maximum value of lis[i] + lds[i] - 1*/
        int max = 0;
        for(int i=0; i < arr.length; i++){
            if(max < lis[i] + lds[i]-1){
                max = lis[i] + lds[i] -1;
            }
        }
        return max;
    }
    
    public static void main(String args[]){
        BitonicSequence bs = new BitonicSequence();
        int[] arr = {1,4,3,7,2,1,8,11,13,0};
        int r = bs.longestSequence(arr);
        System.out.print(r);
    
    }
}
