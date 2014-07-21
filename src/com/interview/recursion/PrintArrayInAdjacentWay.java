package com.interview.recursion;

import java.util.ArrayList;
import java.util.List;

/**
 * http://www.geeksforgeeks.org/find-all-possible-interpretations/
 * This is class fibonacci series example.
 * e.g {1,1,1,1} -> when n = 4 total number of ways possible are
 * f(3) + f(2). This of it as you want to reach at 4 steps and you can only
 * take 1 or 2 steps at a time. So total number of ways to reach 4th step is 
 * total number of reach 3 and then total number to reach 2 because we can go from
 * step 2 to 4 directly
 * Test cases
 * negative number
 * 0
 * null array
 */
public class PrintArrayInAdjacentWay {

	public void printArray(int len,int k){
		List<Integer> result = new ArrayList<Integer>();
		printArray(len,0,result,k);
	}
	
	private void printArray(int len, int pos,List<Integer> result,int k){
		if(pos > len){
			return;
		}
		if(pos == len){
			for(int i:result){
				System.out.print(i + " ");
			}
			System.out.println();
			return ;
		}
		
		for(int i=0; i < k ; i++){
			result.add(i+1);
			printArray(len,pos+i+1,result,k);
			result.remove(result.size()-1);
		}
	}
	
	public int numberOfWaysPossible(int input[],int pos){
		if(pos > input.length){
			return 0;
		}
		if(pos == input.length){
			return 1;
		}
		
		
		int count = numberOfWaysPossible(input,pos+1);
		if(pos + 1 < input.length){
			int num = input[pos]*10 + input[pos+1];
			if(num < 27){
				count += numberOfWaysPossible(input, pos+2);
			}
		}
		return count;
	}
	
	/**
	 * Since we know this is same as fibonacci series all we have to do is either use sum of last two numbers if 
	 * total is less than equal to 26 or use just last number if total is greater than 26
	 * total is calculated by creating a number from current number and previous number
	 * @param input
	 * @return
	 */
	public int numberOfWaysPossibleFaster(int input[]){
		int a0 = 1;
		int a1 = 1;
		int c = 0;
		for(int i=1; i < input.length; i++){
			if(input[i] + input[i-1]*10 <=26){
				c = a1 + a0;
			}else{
				c = a1;
			}
			a0 = a1;
			a1 = c;
		}
		return c;
	}
	
	public static void main(String args[]){
		PrintArrayInAdjacentWay paw = new PrintArrayInAdjacentWay();
	//	paw.printArray(5, 2);
		int input[] = {1,3,7,7,1,7,2,3,2};
		System.out.println(paw.numberOfWaysPossible(input, 0));
		System.out.println(paw.numberOfWaysPossibleFaster(input));
	}
}
