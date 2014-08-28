package com.interview.dynamic;

/**
 * http://www.geeksforgeeks.org/dynamic-programming-set-3-longest-increasing-subsequence/
 */
public class LongestIncreasingSubsequence {

    public int longestSubsequence(int arr[]){
        
        int temp[] = new int[arr.length];
        
        for(int i=0; i < arr.length; i++){
            temp[i] = 1;
        }
        
        for(int i=1; i < arr.length; i++){
            for(int j=0; j < i; j++){
                if(arr[i] > arr[j]){
                    temp[i] = temp[j] + 1> temp[i] ? temp[j] + 1 : temp[i];
                }
            }
        }
        int max = 0;
        for(int i=0; i < temp.length; i++){
            if(temp[i] > max){
                max = temp[i];
            }
        }
        return max;
    }
    
    public int longestSubsequenceRecursive(int arr[]){
        int maxLen = 1;
        for(int i=0; i < arr.length; i++){
            int len = recursiveSolution(arr,i,1);
            if(len > maxLen){
                maxLen = len;
            }
        }
        return maxLen;
    }
    
    private int recursiveSolution(int arr[],int pos,int len){
        if(pos == arr.length){
            return len;
        }
        int maxLen = len;
        for(int i=pos+1; i < arr.length; i++){
            if(arr[i] > arr[pos]){
                int returnedLen = recursiveSolution(arr, i, len+1);
                if(returnedLen > maxLen){
                    maxLen = returnedLen;
                }
            }else{
                int returnedLen = recursiveSolution(arr, i+1, len);
                if(returnedLen > maxLen){
                    maxLen = returnedLen;
                }
            
            }
        }
        return maxLen;
    }
    
    public static void main(String args[]){
        LongestIncreasingSubsequence lis = new LongestIncreasingSubsequence();
        int arr[] = {23,10,22,5,33,8,9,21,50,41,60,80};
    //  int arr[] = {7,4,7,8};
        int result = lis.longestSubsequence(arr);
        int result1 = lis.longestSubsequenceRecursive(arr);
        System.out.println(result);
        System.out.println(result1);
    }
}
