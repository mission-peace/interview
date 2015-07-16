package com.interview.dynamic;

/**
 * http://www.geeksforgeeks.org/maximum-sum-such-that-no-two-elements-are-
 * adjacent/
 */
public class MaxSumForNonAdjacentElements {

	/**
	 * Fast DP solution.
	 */
    public int maxSum(int arr[]) {
        int excl = 0;
        int incl = arr[0];
        for (int i = 1; i < arr.length; i++) {
            int temp = incl;
            incl = Math.max(excl + arr[i], incl);
            excl = temp;
        }
        return incl;
    }
    
    /**
     * Recursive slow solution.
     */
	public int maxSum(int arr[], int index) {
		if (index == 0) {
			return arr[0];
		} else if (index == 1) {
			return Math.max(arr[0], arr[1]);
		}
		return Math.max(this.maxSum(arr, index - 2) + arr[index], this.maxSum(arr, index - 1));
	}    	
   
    public static void main(String args[]) {
        MaxSumForNonAdjacentElements msn = new MaxSumForNonAdjacentElements();
        int arr[] = { 2, 10, 13, 4, 2, 15, 10 };
        System.out.println(msn.maxSum(arr));
        System.out.println(msn.maxSum(arr, arr.length-1));
                
    }
}
