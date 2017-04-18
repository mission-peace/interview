package com.interview.dynamic;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

/**
 * Date 05/02/2014
 * @author tusroy
 *
 * Youtube link - https://youtu.be/CE2b_-XfVDk
 *
 * Find a subsequence in given array in which the subsequence's elements are 
 * in sorted order, lowest to highest, and in which the subsequence is as long as possible
 *
 * Solution : 
 * Dynamic Programming is used to solve this question. DP equation is 
 * if(arr[i] > arr[j]) { T[i] = max(T[i], T[j] + 1 }
 *
 * Time complexity is O(n^2).
 * Space complexity is O(n)
 *
 * Reference 
 * http://en.wikipedia.org/wiki/Longest_increasing_subsequence
 * http://www.geeksforgeeks.org/dynamic-programming-set-3-longest-increasing-subsequence/
 */
public class LongestIncreasingSubsequence {
    
    
    
    /**
     * Greedy algorithm for longest increasing subsequence. Time complexity is nlg(n).
     * for short description of the algorithm and proof of correctness visit 
     * https://www.cs.princeton.edu/courses/archive/spring13/cos423/lectures/LongestIncreasingSubsequence.pdf
     */
    public int longestStrictlyIncreasingSubsequenceWithGreedyAlgorithm(int[] arr){
        List<Stack<Integer>> piles =  new ArrayList<>();
        for(int i =0 ; i < arr.length ; i++)
            addCardToPiles(arr[i] , piles);
        return piles.size();
    }
    
    public List<Integer> longestStrictlyIncreasingSubsequenceListWithGreedyAlgorithm(int[] arr){
        List<Stack<Integer>> piles =  new ArrayList<>();
        for(int i =0 ; i < arr.length ; i++)
            addCardToPiles(arr[i] , piles);
        List<Integer> ret = new ArrayList<>();
        for(Stack<Integer > s : piles)
            ret.add(s.peek());
        return ret;
    }
    
    
    /**
     * inserts the integer to the appropriate position among piles. The position may be a new stack added to the piles.
     * @param i arbitrary integer
     * @param piles a list of stacks of integers such that top elements of each stack is in sorted order.
     */
    private void addCardToPiles(int i , List<Stack<Integer>> piles) {
        //simply do a binary search among top of each pile
        //at this point it is known that top of each stack is sorted.
        int lo = 0;
        int hi = piles.size()-1;
        //handle if the integer should be a new pile 
        if(piles.size() == 0 || i >= piles.get(hi).peek()){
            Stack<Integer> newStack = new Stack<>();
            newStack.push(i);
            piles.add(newStack);
            return;
        }
        while(hi!=lo){
            int mid = (hi+lo) >>> 1; //taking average
            if(piles.get(mid).peek() <= i)
                lo = mid+1;
            else
                hi = mid;
        }
        piles.get(hi).push(i);
    }
    
    
    /**
     * DP way of solving LIS
     */
    public int longestSubsequenceWithActualSolution(int arr[]){
        int T[] = new int[arr.length];
        int actualSolution[] = new int[arr.length];
        for(int i=0; i < arr.length; i++){
            T[i] = 1;
            actualSolution[i] = i;
        }
        
        for(int i=1; i < arr.length; i++){
            for(int j=0; j < i; j++){
                if(arr[i] > arr[j]){
                    if(T[j] + 1 > T[i]){
                        T[i] = T[j] + 1;
                        //set the actualSolution to point to guy before me
                        actualSolution[i] = j;
                    }
                }
            }
        }
        
        //find the index of max number in T 
        int maxIndex = 0;
        for(int i=0; i < T.length; i++){
            if(T[i] > T[maxIndex]){
                maxIndex = i;
            }
        }
        
        //lets print the actual solution
        int t = maxIndex;
        int newT = maxIndex;
        do{
            t = newT;
            System.out.print(arr[t] + " ");
            newT = actualSolution[t];
        }while(t != newT);
        System.out.println();
        
        return T[maxIndex];
    }
    
    /**
     * Recursive way of solving LIS
     */
    public int longestSubsequenceRecursive(int arr[]){
        int maxLen = 0;
        for(int i=0; i < arr.length-1; i++){
            int len = longestSubsequenceRecursive(arr,i+1,arr[i]);
            if(len > maxLen){
                maxLen = len;
            }
        }
        return maxLen + 1;
    }
    
    private int longestSubsequenceRecursive(int arr[], int pos, int lastNum){
        if(pos == arr.length){
            return 0;
        }
        int t1 = 0;
        if(arr[pos] > lastNum){
            t1 = 1 + longestSubsequenceRecursive(arr, pos+1, arr[pos]);
        }
        int t2 = longestSubsequenceRecursive(arr, pos+1, lastNum);
        return Math.max(t1, t2);
    }
    
    public static void main(String args[]){
        LongestIncreasingSubsequence lis = new LongestIncreasingSubsequence();
        int arr[] = {23,10,22,5,33,8,9,21,50,41,60,80,99, 22,23,24,25,26,27};
        int result = lis.longestSubsequenceWithActualSolution(arr);
        int result1 = lis.longestSubsequenceRecursive(arr);
        int result2 = lis.longestStrictlyIncreasingSubsequenceWithGreedyAlgorithm(arr);
        List<Integer> subsequence = lis.longestStrictlyIncreasingSubsequenceListWithGreedyAlgorithm(arr);
        System.out.println(result);
        System.out.println(result1);
        System.out.println(result2);
        System.out.println(subsequence);
    }
}
