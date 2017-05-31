package com.interview.array;

/**
 * http://stackoverflow.com/questions/4686823/given-2-sorted-arrays-of-integers-find-the-nth-largest-number-in-sublinear-time
 * http://articles.leetcode.com/2011/01/find-k-th-smallest-element-in-union-of.html
 */
public class KthLargestInTwoSortedArray {

    
    public int kthLargest(int A1[],int A2[],int k){
        int size1 = A1.length, size2 = A2.length;

        int index1 = 0, index2 = 0, step = 0;
        while (index1 + index2 < k - 1) {
            step = (k - index1 - index2) / 2;
            int step1 = index1 + step;
            int step2 = index2 + step;
            if (size1 > step1 - 1 && (size2 <= step2 - 1 || A1[step1 - 1] < A2[step2 - 1])) {
                index1 = step1; // commit to element at index = step1 - 1
            } else {
                index2 = step2;
            }
        }
        // the base case of (index1 + index2 == k - 1)
        if (size1 > index1 && (size2 <= index2 || A1[index1] < A2[index2])) {
            return A1[index1];
        } else {
            return A2[index2];
        }
    }
    
    public static void main(String args[]){
        KthLargestInTwoSortedArray kis = new KthLargestInTwoSortedArray();
        int input1[] = {1,4,7,11,17,21};
        int input2[] = {-4,-1,3,4,6,28,35,41,56,70};
        for(int i = 0; i < input1.length + input2.length; i++){
            System.out.println(kis.kthLargest(input1, input2, i+1));
        }
//      System.out.println(kis.kthLargest(input1, input2, 6));

    }
}
