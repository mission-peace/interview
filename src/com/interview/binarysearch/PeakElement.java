package com.interview.binarysearch;

public class PeakElement {

    public int peakElement(int arr[]){
        int low = 0;
        int high = arr.length-1;
        while(low < high){
            int mid = (low+high)/2;
            if(mid == 0 || mid == arr.length-1){
                return arr[mid];
            }
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){
                return arr[mid];
            }
            if(arr[mid] < arr[mid-1]){
                high = mid-1;
                continue;
            }
            if(arr[mid] < arr[mid+1]){
                low = mid+1;
                continue;
            }
        }
        return arr[low];
    }
    
    public static void main(String args[]){
        int arr[] = {10,5,15,2,23,90,67};
        PeakElement pe = new PeakElement();
        System.out.println(pe.peakElement(arr));
        int arr1[] = {10,20,30,40,50};
        System.out.println(pe.peakElement(arr1));
        int arr2[] = {100,90,80,70,60};
        System.out.println(pe.peakElement(arr2));
                
    }
}
