package com.interview.sort;

/*
 * Introduction: Swaps the adjacent elements to sort those elements,
 *               so that at the end, all the elements bubbles up in their sorted position.
 *
 * Algorithm (Ascending order):
 *   1. Mark the pointer at the first index
 *   2. Take the pointer element and the one after the pointer element
 *   3. If pointer element is greater than next element, swap them
 *   4. Move the pointer across by one position
 *   5. Continue 2,3,4 until the pointer reaches sorted index
 *      In every iteration the largest element of the unsorted part will bubble up at the end of the array in its sorted position.)
 *   6. Repeat the above steps until the whole array is sorted (until the sorted index equals to the beginning index of the array.)
 *
 * Time Complexity:
 *   Best case -> O(n)
 *   Average case -> O(n^2)
 *   Worst Case -> O(n^2)
 * */

public class BubbleSort {
    public void swap(int[] input, int firstPosition, int secondPosition){
        int temp = input[firstPosition];
        input[firstPosition] = input[secondPosition];
        input[secondPosition] = temp;
    }

    public void bubbleSortAsc(int[] input){
        if(input.length>1){
            for(int j = (input.length-1); j>0; j--){
                for(int i=0; i<j; i++){
                    if(input[i]>input[i+1]){
                        swap(input,i,(i+1));
                    }
                }
            }
        }
    }

    public void bubbleSortDesc(int[] input){
        if(input.length>1){
            for(int j = (input.length-1); j>0; j--){
                for(int i=0; i<j; i++){
                    if(input[i]<input[i+1]){
                        swap(input,i,(i+1));
                    }
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

        BubbleSort bs = new BubbleSort();

        bs.bubbleSortAsc(A);
        bs.displaySortedArray(A);

        bs.bubbleSortAsc(B);
        bs.displaySortedArray(B);

        bs.bubbleSortAsc(C);
        bs.displaySortedArray(C);

        bs.bubbleSortAsc(D);
        bs.displaySortedArray(D);

        bs.bubbleSortAsc(E);
        bs.displaySortedArray(E);
    }
}
