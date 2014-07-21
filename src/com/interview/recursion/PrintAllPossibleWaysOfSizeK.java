package com.interview.recursion;

/**
 * http://www.geeksforgeeks.org/print-all-combinations-of-given-length/
 * Time complexity is n*n..k times.
 * Test case : k is 0 or negative.
 * str is null
 */
public class PrintAllPossibleWaysOfSizeK {

	public void print(char str[],int k){
		char result[] = new char[str.length];
		print(str,k,result,0);
	}
	private int count=0;
	private void print(char str[],int k, char result[], int pos){
		if(pos == k){
			count++;
			for(int i=0; i < k; i++){
				System.out.print(result[i] + " ");
			}
			System.out.println();
			return;
		}
		for(int i=0; i < str.length; i++){
			result[pos] = str[i];
			print(str,k,result,pos+1);
		}
	}
	
	public static void main(String args[]){
		PrintAllPossibleWaysOfSizeK pap = new PrintAllPossibleWaysOfSizeK();
		pap.print("abcd".toCharArray(), 3);
		System.out.println(pap.count);
	}
}
