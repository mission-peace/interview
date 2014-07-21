package com.interview.number;

import java.util.ArrayList;
import java.util.List;

/**
 * http://www.geeksforgeeks.org/generate-unique-partitions-of-an-integer/
 * Test cases:
 * 0 or negative number
 */
public class UniquePartitionOfInteger {

	private int i=0;
	public void partition(int n){
		List<Integer> result = new ArrayList<Integer>();
		partition(n,n,result);
	}
	
	private void partition(int n, int start,List<Integer> result){
		if(n == 0){
			i++;
			System.out.print(i + " ");
			for(int c : result){
				System.out.print(c + " ");
			}
			System.out.println();
			return;
		}
			
		for(int i= start; i >=1 ; i--){
			result.add(i);
			if(n-i < i){
				start = n-i;
			}else{
				start = i;
			}
			partition(n-i,start,result);
			result.remove(result.size()-1);
		}
	}
	
	public static void main(String args[]){
		UniquePartitionOfInteger upi = new UniquePartitionOfInteger();
		upi.partition(12);
	}
}
