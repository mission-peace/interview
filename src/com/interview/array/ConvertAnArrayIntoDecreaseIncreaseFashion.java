package com.interview.array;


/**
 * Convert an unsorted array into an array such that
 * a < b > c < d > e < f and so on
 */
public class ConvertAnArrayIntoDecreaseIncreaseFashion {

    public void convert(int arr[]){
        int k = 0;
        if(arr.length % 2 ==0){
            k = arr.length/2 ;
        }else{
            k = arr.length/2+1;
        }
        KthElementInArray kthElement = new KthElementInArray();
        kthElement.kthElement(arr, k);
        
        int high = k;
        int low = 1;
        while(low < high && high < arr.length){
            swap(arr,low,high);
            high++;
            low += 2;
        }
        
    }
    
    private void swap(int arr[],int low,int high){
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
    }
    
    public static void main(String args[]){
        ConvertAnArrayIntoDecreaseIncreaseFashion can = new ConvertAnArrayIntoDecreaseIncreaseFashion();
        int arr[] = {0,6,9,13,10,-1,8,2,4,14,-5};
        can.convert(arr);
        for(int i=0; i < arr.length; i++){
            System.out.print(arr[i] + " ");
        }
    }

}
