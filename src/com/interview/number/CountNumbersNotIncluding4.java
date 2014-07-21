package com.interview.number;

/**
 * http://www.geeksforgeeks.org/count-numbers-that-dont-contain-3/
 */
public class CountNumbersNotIncluding4 {

	public int count(int n){
		if(n < 4){
			return n;
		}
		if( n >=4 && n <=10){
			return n-1;
		}
		
		int pow = 1;
		while(n/pow > 9){
			pow = pow*10;
		}
		
		int msd = n/pow;
		if(msd == 4){
			return count(msd*pow -1);
		}else{
			return count(msd)*count(pow-1) + count(msd) + count(n%pow);
		}
	}
	
	public static void main(String args[]){
		CountNumbersNotIncluding4 cn = new CountNumbersNotIncluding4();
		int c = cn.count(44);
		System.out.print(c);
	}
}
