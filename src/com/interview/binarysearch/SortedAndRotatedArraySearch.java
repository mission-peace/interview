package com.interview.binarysearch;

/**
 * http://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/
 * This does not works if there are duplicates in the array.
 */
public class SortedAndRotatedArraySearch {

    public int search(int arr[],int search){
        
        int low =0;
        int high = arr.length-1;
        while(low <= high){
            int mid = (low + high)/2;
            if(arr[mid] == search){
                return mid;
            }
            
            if(arr[mid] < arr[high]){
                if(arr[mid] < search && search <= arr[high]){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }else{
                if(search >= arr[low] && search < arr[mid]){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }
        }
        return -1;
    }
    
    public static void main(String args[]){
        SortedAndRotatedArraySearch ras = new SortedAndRotatedArraySearch();
        int arr1[] = {1,2,5,6,7,8,11,21};
        System.out.print(ras.search(arr1, 1));
        System.out.print(ras.search(arr1, 5));
        System.out.print(ras.search(arr1, 22));
        System.out.println();
    
        int arr2[] = {18,21,1,2,5,6,7,8,10,15};
        System.out.print(ras.search(arr2, 1));
        System.out.print(ras.search(arr2, 5));
        System.out.print(ras.search(arr2, 10));
        System.out.print(ras.search(arr2, 14));
        System.out.println();

        int arr3[] = {7,8,15,17,18,21,1,2,5,6};
        System.out.print(ras.search(arr3, 1));
        System.out.print(ras.search(arr3, 5));
        System.out.print(ras.search(arr3, 10));
        System.out.print(ras.search(arr3, 7));
        System.out.print(ras.search(arr3, 6));
        System.out.print(ras.search(arr3, 16));
    }
}
