package com.interview.recursion;

/**
 * e.g a, b c 
 * * * *
 * a * *
 * a b *
 * a b c
 * * b *
 * * b c
 * * * c
 * 
 * Idea is to store the index of values instead of actual values and
 * while printing it print the indexes which are in result and if not 
 * in result print *
 */
public class CombinationWithStar {

	public void combine(char input[],int result[],int start,int r){
		if(r == result.length){
			return;
		}
		print(input,result,r);
		for(int i=start; i < input.length; i++){
			result[r] = i;
			combine(input,result,i+1,r+1);
		}
	}
	
	private void print(char input[],int result[],int r){
		int index = 0;
		for(int i=0; i < input.length ;i++){
			if(r > 0 && index <r && (i == result[index])){
				System.out.print(input[result[index]] + " ");
				index++;
			}else{
				System.out.print("* ");
			}
		}
		System.out.println();
	}
	
	public static void main(String args[]){
		char input[] = {'a','b','c','d'};
		CombinationWithStar cws = new CombinationWithStar();
		int result[] = new int[input.length];
		cws.combine(input, result, 0, 0);
	}
}
