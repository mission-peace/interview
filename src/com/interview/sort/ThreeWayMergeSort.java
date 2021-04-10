package com.interview.sort;

/*
*Introduction: Same as the merge sort. The only difference is instead of recursively splitting the problem into 2 sub problems,
*              in 3 way merge sort, we recursively split the problem into three sub problems.
*
* Algorithm
*   Three way merge sort->
*   1. Recursively divide the problem into 3 sub problems until we have individual elements
*   2. Take those elements three by three and merge them (perform three way merge)
*   3. Repeat 2 until we get the sorted array
*   Three way merge->
*   1. Take the three arrays
*   2. Set pointer indexes at the beginning of each one of them
*   3. Take a temporary array and set a pointer index at the beginning of it
*   4. Until one of the pointers of the three input arrays reach the end of that particular array,
*           compare the three elements at the three indexes,
*           get the smallest element out of the three elements and put it in the temp array,
*           increase the temp array index and the index of the array which contained the smallest element by one
*   5. If at least one input array index reach the end,
*      take the rest of the 2 arrays and perform 2 way merge for the rest of the elements in those 2 arrays
*
*Time Complexity:
*    Best case -> O(nlog3n)
*    Average case -> O(nlog3n)
*    Worst case-> O(nlog3n)
* */

public class ThreeWayMergeSort {
    public void threeWayMergeSort(int[] input, int low, int high){
        if(low<high){
            int mid1 = low + (high-low)/3;
            int mid2 = low + (2*((high-low)/3))+1;
            threeWayMergeSort(input,low,mid1);
            threeWayMergeSort(input,(mid1+1),mid2);
            threeWayMergeSort(input,(mid2+1),high);
            threeWayMerge(input,low,mid1,mid2,high);
        }
    }

    public void threeWayMerge(int[] input, int low, int mid1, int mid2, int high){
        int[] temp = new int[high-low+1];
        int i = low;
        int j = mid1+1;
        int k = mid2+1;
        int l = 0;
        //perform merge using all three input arrays
        while(i<=mid1 && j<=mid2 && k<=high){
            if((input[i]<=input[j]) && input[i]<=input[k]){
                temp[l] = input[i];
                i++;
            } else if((input[j]<=input[i]) && input[j]<=input[k]){
                temp[l] = input[j];
                j++;
            } else if((input[k]<=input[i]) && input[k]<=input[j]){
               temp[l] = input[k];
               k++;
            }
            l++;
        }

        //Perform 2 way merge for the rest of the elements of the rest of the 2 arrays
        if(i>mid1){
            while(j<=mid2 && k<=high){
                if(input[j]<=input[k]){
                    temp[l] = input[j];
                    j++;
                } else if(input[j]>input[k]){
                    temp[l] = input[k];
                    k++;
                }
                l++;
            }
            for(;j<=mid2;j++){
                temp[l] = input[j];
                l++;
            }
            for(;k<=high;k++){
                temp[l] =input[k];
                l++;
            }
        } else if(j>mid2){
            while(i<=mid1 && k<=high){
                if(input[i]<=input[k]){
                    temp[l] = input[i];
                    i++;
                } else if(input[i]>input[k]){
                    temp[l] = input[k];
                    k++;
                }
                l++;
            }
            for(;i<=mid1;i++){
                temp[l] = input[i];
                l++;
            }
            for(;k<=high;k++){
                temp[l] =input[k];
                l++;
            }
        } else if(k>high){
            while(i<=mid1 && j<=mid2){
                if(input[i]<=input[j]){
                    temp[l] = input[i];
                    i++;
                } else if(input[i]>input[j]){
                    temp[l] = input[j];
                    j++;
                }
                l++;
            }
            for(;i<=mid1;i++){
                temp[l] = input[i];
                l++;
            }
            for(;j<=mid2;j++){
                temp[l] =input[j];
                l++;
            }
        }

        int y = low;
        for(int x=0; x< temp.length; x++){
            input[y] = temp[x];
            y++;
        }
    }

    public void sort(int[] input){
        threeWayMergeSort(input,0,(input.length-1));
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

        ThreeWayMergeSort twms = new ThreeWayMergeSort();

        twms.sort(A);
        twms.displaySortedArray(A);

        twms.sort(B);
        twms.displaySortedArray(B);

        twms.sort(C);
        twms.displaySortedArray(C);

        twms.sort(D);
        twms.displaySortedArray(D);

        twms.sort(E);
        twms.displaySortedArray(E);
    }
}
