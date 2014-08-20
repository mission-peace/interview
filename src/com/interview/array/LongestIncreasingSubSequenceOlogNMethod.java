package com.interview.array;

/**
 * http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
 * http://www.geeksforgeeks.org/construction-of-longest-monotonically-increasing-subsequence-n-log-n/
 */
public class LongestIncreasingSubSequenceOlogNMethod {

    private int ceilIndex(int input[],int end, int s){
        int start = 0;
        int middle;
        int len = end;
        while(start <= end){
            middle = (start + end)/2;
            if(middle < len && input[middle] < s && s <= input[middle+1]){
                return middle+1;
            }else if(input[middle] < s){
                start = middle+1;
            }else{
                end = middle-1;
            }
        }
        return -1;
    }
    
    public int longestIncreasingSubSequence(int input[]){
        int temp[] = new int[input.length];
        temp[0] = input[0];
        int len =1;
        for(int i=1; i < input.length; i++){
            if(temp[0] > input[i]){
                temp[0] = input[i];
            }else if(temp[len-1] < input[i]){
                temp[len] = input[i];
                len++;
            }else{
                int index = ceilIndex(temp, len-1,input[i]);
                temp[index] = input[i];
            }
        }
        return len;
    }
    
    public static void main(String args[]){
        int input[] = {2,5,3,1,2,10,6,7,8,-10,-9,-8,-7,-6,-5,-4};
        LongestIncreasingSubSequenceOlogNMethod lis = new LongestIncreasingSubSequenceOlogNMethod();
        System.out.println(lis.longestIncreasingSubSequence(input));
    }
}
