package com.interview.recursion;

public class Combination {

    private void printArray(int arr[],int pos){
        for(int i=0; i < pos; i++){
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
    
    private void combination(int arr[],int pos,int start,int result[]){
    
        printArray(result,pos);
        for(int i = start ; i < arr.length; i++){
            result[pos] = arr[i];
            combination(arr,pos+1,i+1,result);
        }
    }
    
    public static void main(String args[]){
        Combination c = new Combination();
        int arr[] = {1,2,3,4};
        int result[] = new int[arr.length];
        c.combination(arr, 0, 0, result);
    }
    
}
