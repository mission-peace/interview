package com.interview.dynamic;
/*
 * http://www.geeksforgeeks.org/dynamic-programming-set-18-partition-problem/
 */
public class SubsetSum {

    public boolean partition(int arr[]){
        int sum =0;
        for(int i=0; i < arr.length; i++){
            sum += arr[i];
        }
        
        if(sum % 2 != 0){
            return false;
        }
        sum = sum/2;
        boolean[][] T = new boolean[arr.length+1][sum+1];
        
        for(int i=0; i <= arr.length; i++){
            T[i][0] = true;
        }
        
        for(int i=1; i <= arr.length; i++){
            for(int j=1; j <= sum; j++){
                if(j - arr[i-1] >= 0){
                    T[i][j] = T[i-1][j - arr[i-1]] || T[i-1][j];
                }
            }
        }
        return T[arr.length][sum];
    }
    
    public static void main(String args[]){
        SubsetSum ss = new SubsetSum();
        int arr[] = {1,3,5,5,2,1,1,6};
        boolean r = ss.partition(arr);
        System.out.print(r);
    }
}
