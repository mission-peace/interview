package com.interview.array;

import java.lang.reflect.Array;
import java.util.Arrays;

/**
 * http://www.geeksforgeeks.org/find-a-triplet-that-sum-to-a-given-value/
 */
public class TripletToSum {

	public void findTriplet(int input[],int sum){
		
		Arrays.sort(input);
		for(int i=0; i < input.length-2; i++){
			int j = i + 1;
			int k = input.length-1;
			int newSum = sum - input[i]; 
			while(j < k){
				if(input[j] + input[k] == newSum){
					System.out.println(input[i] + " " + input[j] + " " + input[k]);
					j++;k--;
				}else if(input[j] + input[k] > newSum){
					k--;
				}else{
					j++;
				}
			}
		}
	}
	public static void main(String args[]){
		TripletToSum tts = new TripletToSum();
		int input[] = {2,5,3,8,9,11,-3,-6};
		tts.findTriplet(input, 0);
		
	}
}
