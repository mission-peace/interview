package com.interview.dynamic;

import java.util.TreeMap;

/**
 * http://www.geeksforgeeks.org/remove-minimum-elements-either-side-2min-max/
 */
public class RemoveFromEndToMake2IntoMinGreaterThanMax {

    public int removeFromEnd(int input[]){
        return removeFromEnd(input,0,input.length-1);
    }
    
    private int removeFromEnd(int input[],int low,int high){
        if(low > high){
            return input.length;
        }
        int min = min(input,low,high);
        int max = max(input,low,high);
        if(2*min > max){
            return 0;
        }

        return Math.min(removeFromEnd(input,low,high-1), removeFromEnd(input,low+1,high)) +1;
    }
    
    private int min(int input[],int low,int high){
        int min = Integer.MAX_VALUE;
        for(int i=low; i <=high; i++){
            if(min > input[i]){
                min = input[i];
            }
        }
        return min;
    }
    private int max(int input[],int low,int high){
        int max = Integer.MIN_VALUE;
        for(int i=low; i <=high; i++){
            if(max < input[i]){
                max = input[i];
            }
        }
        return max;
    }
    
    public int removeFromEndDynamic(int input[]){
        int T[][] = new int[input.length][input.length];
        for(int l=1; l <= input.length; l++){
            for(int i=0, j = i + l-1; i < input.length-l+1; i++,j++){
                int min = min(input,i,j);
                int max = max(input,i,j);
                if(2*min > max){
                    T[i][j] = 0;
                }else{
                    T[i][j] = Math.min(T[i+1][j] , T[i][j-1]) +1;
                }
            }
        }
        return T[0][input.length-1];
    }
    
    //O(nlogn) approach : Think of which elements will remain in the array
    //Maintain a sliding window with a TreeMap that keeps count of the elements in the current interval
    //If the condition holds for the window, then increment right pointer, if not increment left
    //This method will return the max subarray that satisfies the given condition
    //Our final answer would be size of array - max subarray
    static int removeMinElements(int[] a) {
        int n = a.length;
        int i=0, j=0;
        TreeMap<Integer, Integer> tree = new TreeMap<>();
        int max = 1;
        while (j<n) {
            add(tree, a[j]);
            if(works(tree)) {
                j++;
                continue;
            }
            max = Math.max(max, j-i);
            while(!works(tree)) {
                remove(tree, a[i]);
                i++;
            }
            j++;
        }
        if(works(tree))
            max = Math.max(max, j-i);
        return n-max;
    }

    static void add(TreeMap<Integer, Integer> tree, int key) {
        tree.put(key, tree.getOrDefault(key, 0)+1);
    }

    static void remove(TreeMap<Integer,Integer> tree, int key) {
        if(tree.get(key)==1) tree.remove(key);
        else tree.put(key, tree.get(key)-1);
    }

    static boolean works(TreeMap<Integer,Integer> tree) {
        return 2*tree.firstKey() > tree.lastKey();
    }
    
    // end of O(nlogn) approach
    
    
    
    
    public static void main(String args[]){
        int input[] = {5,1,3,1,3,8,3};
        RemoveFromEndToMake2IntoMinGreaterThanMax rme = new RemoveFromEndToMake2IntoMinGreaterThanMax();
        System.out.println(rme.removeFromEnd(input));
        System.out.println(rme.removeFromEndDynamic(input));
    }
}
