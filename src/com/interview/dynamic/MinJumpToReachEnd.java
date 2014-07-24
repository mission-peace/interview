package com.interview.dynamic;

/**
 * http://www.geeksforgeeks.org/minimum-number-of-jumps-to-reach-end-of-a-given-array/
 */
public class MinJumpToReachEnd {

	public int minJump(int arr[],int result[]){
		
		int []jump = new int[arr.length];
		jump[0] = 0;
		for(int i=1; i < arr.length ; i++){
			jump[i] = 1000;
		}
		
		for(int i=1; i < arr.length; i++){
			for(int j=0; j < arr.length; j++){
				if(arr[j] + j >= i){
					if(jump[i] > jump[j] + 1){
						result[i] = j;
					}
					jump[i] = Math.min(jump[i],jump[j]+1);
				}
			}
		}
		
		return jump[jump.length-1];
	}
	
	public static void main(String args[]){
		MinJumpToReachEnd mj = new MinJumpToReachEnd();
		int arr[] = {1,3,5,3,2,2,6,1,6,8,9};
		int r[] = new int[arr.length];
		int result = mj.minJump(arr,r);
		System.out.println(result);
		int i = arr.length-1;
		while(i > 0){
			System.out.println(r[i]);
			i = r[i];
		}
	}
}
