package com.interview.dynamic;

/**
 * http://www.geeksforgeeks.org/maximum-sum-such-that-no-two-elements-are-adjacent/
 */
public class MaxSumForNonAdjacentElements {
	
	public int maxSum(int arr[]){
		int excl = 0;
		int incl = arr[0];
		for(int i=1; i < arr.length; i++){
			if(excl + arr[i] > incl){
				int temp = incl;
				incl = excl + arr[i];
				excl = temp;
			}else{
				excl = incl;
			}
		}
		return Math.max(excl, incl);
	}
	
	public static void main(String args[]){
		int arr[] = {2,10,3,4,15,10};
		MaxSumForNonAdjacentElements msn = new MaxSumForNonAdjacentElements();
		System.out.println(msn.maxSum(arr));
	}
}
