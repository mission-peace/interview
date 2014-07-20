package com.interview.dynamic;

/**
 * http://www.geeksforgeeks.org/dynamic-programming-set-27-max-sum-rectangle-in-a-2d-matrix/
 */
public class SubArrayWithMaximumSum {

	public int maxSum(int input[][]){
		int rows = input.length;
		int cols = input[0].length;
		int temp[] = new int[rows];
		int max = 0;
		for(int left = 0; left < cols ; left++){
			for(int i=0; i < rows; i++){
				temp[i] = 0;
			}
			for(int right = left; right < cols; right++){
				for(int i=0; i < rows; i++){
					temp[i] += input[i][right];
				}
				int maxSoFar = kadane(temp);
				if(maxSoFar > max){
					max = maxSoFar;
				}
		}
		}
		return max;
	}
	
	private int kadane(int arr[]){
		int max = 0;
		int maxSoFar = 0;
		for(int i=0; i < arr.length; i++){
			maxSoFar += arr[i];
			if(maxSoFar < 0){
				maxSoFar = 0;
			}
			if(max < maxSoFar){
				max = maxSoFar;
			}
		}
		return max;
	}
	
	
	public static void main(String args[]){
		int input[][] = {{1,2,-1,-4,-20},
						 {-8,-3,4,2,1},
						 {3,8,10,1,3},
						 {-4,-1,1,7,-6}};
		SubArrayWithMaximumSum saw = new SubArrayWithMaximumSum();
		System.out.println(saw.maxSum(input));
	}		
}
