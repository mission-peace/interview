package com.interview.number;

import java.util.Arrays;
import java.util.Comparator;

/**
 * http://www.geeksforgeeks.org/given-an-array-of-numbers-arrange-the-numbers-to-form-the-biggest-number/
 */
public class RearrangeNumberInArrayToFormLargestNumber {

	public void rearrange(Integer arr[]){
		IntegerComparator comparator = new IntegerComparator();
		Arrays.sort(arr, comparator);
	}
	
	public static void main(String args[]){
		RearrangeNumberInArrayToFormLargestNumber rni = new RearrangeNumberInArrayToFormLargestNumber();
		Integer arr[] = {546,54,2,11,97};
		rni.rearrange(arr);
		for(int a : arr){
			System.out.print(a + " ");
		}
	}
}

class IntegerComparator implements Comparator<Integer>{

	@Override
	public int compare(Integer o1, Integer o2) {
		int pow1 = 1;
		while(pow1 <= o1){
			pow1 = pow1*10;
		}
		pow1 = pow1/10;
		
		int pow2 = 1;
		while(pow2 <= o2){
			pow2 = pow2*10;
		}
		
		pow2 = pow2/10;
		int temp1 = o1/pow1;
		int temp2 = o2/pow2;
		while(pow1 >0 && pow2 > 0){
			int msd1 = o1/pow1;
			int msd2 = o2/pow2;
			if(msd1 < msd2){
				return 1; 
			}else if(msd1 > msd2){
				return -1;
			}
			o1 = o1%pow1;
			o2 = o2%pow2;
			pow1 = pow1/10;
			pow2 = pow2/10;
		}
		if(pow1 > 0){
			if(temp1 > o1/pow1){
				return 1;
			}else{
				return -1;
			}
		}
		if(pow2 > 0){
			if(temp2 > o2/pow2){
				return -1;
			}else{
				return 1;
			}
		}
		return 0;
	}
	
}
