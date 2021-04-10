package com.interview.sort;

/*
 * Introduction: The array will be gradually separated into two parts as unsorted part and sorted part.
 *               Select the minimum value from the unsorted part and put it at the end of the sorted part.
 *
 * Algorithm (Ascending order):
 *   1. Mark the first index of the array as the sortedIndex
 *   2. Mark the first element of the array as the currentMinimum
 *   3. Starting from the sortedIndex move the pointer across the array
 *   4. If the pointer element is less than currentMinimum element, mark the pointer element as the new currentMinimum
 *   5. Once the pointer reaches the end of the array, swap the element at the unsorted index with currentMinimum element
 *   6. Move the sortedIndex to the next position and mark that element as the currentMinimum
 *   7. Repeat 3,4,5 & 6 until the sortedIndex reaches the end of the array
 *
 * Time Complexity:
 *   Best case -> O(n^2)
 *   Average case -> O(n^2)
 *   Worst Case -> O(n^2)
 * */

public class SelectionSort {
    public void swap(int[] input, int firstPosition, int secondPosition){
        int temp = input[firstPosition];
        input[firstPosition] = input[secondPosition];
        input[secondPosition] = temp;
    }

    //For ascending order
    public void selectionSortAsc(int[] input){
        if(input.length>1){
            int sortedIndex = 0;
            int currentMinimumIndex = 0;
            while(sortedIndex<input.length){
                for(int pointer = sortedIndex; pointer<input.length; pointer++){
                    if(input[pointer]<input[currentMinimumIndex]){
                        currentMinimumIndex = pointer;
                    }
                }
                swap(input,sortedIndex,currentMinimumIndex);
                sortedIndex++;
                currentMinimumIndex = sortedIndex;
            }
        }
    }

    //For descending order
    public void selectionSortDesc(int[] input){
        if(input.length>1){
            int sortedIndex = 0;
            int currentMaximumIndex = 0;
            while(sortedIndex<input.length){
                for(int pointer = sortedIndex; pointer<input.length; pointer++){
                    if(input[pointer]>input[currentMaximumIndex]){
                        currentMaximumIndex = pointer;
                    }
                }
                swap(input,sortedIndex,currentMaximumIndex);
                sortedIndex++;
                currentMaximumIndex = sortedIndex;
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

        SelectionSort ss = new SelectionSort();

        ss.selectionSortAsc(A);
        ss.displaySortedArray(A);

        ss.selectionSortAsc(B);
        ss.displaySortedArray(B);

        ss.selectionSortAsc(C);
        ss.displaySortedArray(C);

        ss.selectionSortAsc(D);
        ss.displaySortedArray(D);

        ss.selectionSortAsc(E);
        ss.displaySortedArray(E);
    }
}
