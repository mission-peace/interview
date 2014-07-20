package com.interview.array;

/**
 * http://www.geeksforgeeks.org/find-the-maximum-repeating-number-in-ok-time/
 */
public class MaxRepeatingNumber {

	public int maxRepeatingNumber(int arr[]){
		int len = arr.length;
		for(int i=0;  i < arr.length; i++){
			arr[arr[i]%len] += len;
		}
		int maxRepeating = 0;
		int maxRepeatingIndex =0;
		for(int i=0; i < arr.length; i++){
			if(maxRepeating < arr[i]){
				maxRepeating = arr[i];
				maxRepeatingIndex = i;
			}
		}
		for(int i=0; i < arr.length; i++){
			arr[i] = arr[i] % len;
		}
		return maxRepeatingIndex;
	}
	
	public static void main(String args[]){
		MaxRepeatingNumber mrn = new MaxRepeatingNumber();
		int arr[] = {2,2,1,3,1,2,0,3,0,0,0,4,5,4,4,4,4};
		System.out.println(mrn.maxRepeatingNumber(arr));
	}
}
