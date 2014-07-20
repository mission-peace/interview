package com.interview.dynamic;

/**
 * http://www.geeksforgeeks.org/dynamic-programming-set-24-optimal-binary-search-tree/
 */
public class OptimalTreeSearch {

	public int minCost(int input[],int freq[]){
		
		return minCost(input,freq,0,input.length-1,1);
	}
	
	private int minCost(int input[],int freq[],int low,int high,int level){
		if(low > high){
			return 0;
		}
		
		int min = 1000000;
		for(int i=low; i <= high; i++){
			int val = minCost(input,freq,low,i-1,level+1) + 
					minCost(input,freq,i+1,high,level+1)
					+ level*freq[i];
			if(val < min){
				min = val;
			}
		}
		return min;
	}
	
	public static void main(String args[]){
		int input[] = {10,12,20,35};
		int freq[] = {34,8,50,21};
		OptimalTreeSearch ots = new OptimalTreeSearch();
		System.out.println(ots.minCost(input, freq));
	}
}
