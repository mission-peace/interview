package com.interview.sort;

/*
* Introduction: The array will be gradually separated into two parts as unsorted part and sorted part.
*               Get the values one by one from the unsorted part and place them in the correct positions of the sorted part.
*
* Algorithm (Ascending order):
*   1. 1st element (single element) is always sorted. Start with the second element (pointer starts from 2nd element)
*   2. Take the element at the pointer and check if it's less than it's left element, if so swap them
*   3. Continue 2 until the left side of the pointer is correctly sorted
*   4. Increase the pointer by one and continue 2 & 3
*
* Time Complexity:
*   Best case -> O(n)
*   Average case -> O(n^2)
*   Worst Case -> O(n^2)
* */

public class InsertionSort {
    public void swap(int[] input, int firstPosition, int secondPosition){
        int temp = input[firstPosition];
        input[firstPosition] = input[secondPosition];
        input[secondPosition] = temp;
    }

    //For ascending order
    public void insertionSortAsc(int[] input){
        if(input.length>1){
            for(int pointer = 1; pointer<input.length; pointer++){
                int j = pointer;
                while(j>0 && (input[j]<input[j-1])){
                    swap(input,j,j-1);
                    j--;
                }
            }
        }
    }

    //For descending order
    public void insertionSortDesc(int[] input){
        if(input.length>1){
            for(int pointer = 1; pointer<input.length; pointer++){
                int j = pointer;
                while(j>0 && (input[j]>input[j-1])){
                    swap(input,j,j-1);
                    j--;
                }
            }
        }
    }

    public void displaySortedArray(int[] input){
        for(int x =0; x<input.length; x++){
            System.out.print(input[x] + "\t");
        }
        System.out.println();
    }

    public static void main(String[] args){
        //one element
        int[] A = {3};
        //Two elements
        int[] B = {5,8};
        //Best case -> sorted
        int[] C = {1,3,5,6,7,9};
        //Average case -> unsorted
        int[] D = {4,5,9,1,4,2,7,2,4};
        //Worst case - sorted in descending order
        int[] E = {9,7,4,3,2,1};

        InsertionSort is = new InsertionSort();

        is.insertionSortAsc(A);
        is.displaySortedArray(A);

        is.insertionSortAsc(B);
        is.displaySortedArray(B);

        is.insertionSortAsc(C);
        is.displaySortedArray(C);

        is.insertionSortAsc(D);
        is.displaySortedArray(D);

        is.insertionSortAsc(E);
        is.displaySortedArray(E);
    }
}
