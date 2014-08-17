package com.interview.number;

import com.interview.sort.QuickSort;

/**
 e.g 1 7 9 8 4 will transform to 1 8 4 7 9
 or  4 2 6 4 3 will transform to 4 3 2 4 6
 */
public class PermutationBiggerThanNumber {

    public void findLargerNumber(int arr[]){
        
        for(int i=arr.length-1; i > 0 ; i--){
            if(arr[i-1] < arr[i]){
                int swapPoint = findNextLargerNumber(arr,arr[i-1],i);
                swap(arr,i-1,swapPoint);
                QuickSort qs = new QuickSort();
                qs.sort(arr,i,arr.length-1);
                break;
            }
        }
        
    }
    
    private int findNextLargerNumber(int arr[],int num,int pos){
        for(int i=pos; i < arr.length; i++){
            if(num < arr[i]){
                continue;
            }
            return i-1;
        }
        return arr.length-1;
    }
    
    private void swap(int arr[],int i,int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
    public static void main(String args[]){
        PermutationBiggerThanNumber pb = new PermutationBiggerThanNumber();
        int arr[] = {1,7,9,8,4};
        pb.findLargerNumber(arr);
        for(int i=0; i < arr.length; i++){
            System.out.print(arr[i] + " ");
        }
    }
}
