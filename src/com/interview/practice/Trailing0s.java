package com.interview.practice;

public class Trailing0s {

	public int trailing0s(int num){
		int a1 = num / 5;
		int a2 = 0;
		int i = 1;
		num = num/5;
		while(num >= 5){
			a2 += i;
			i++;
			num /= 5;
		}
		return a1 + a2;
	}
	
	public static void main(String args[]){
		Trailing0s tt = new Trailing0s();
		System.out.println(tt.trailing0s(146));
		System.out.println(tt.trailing0s(1046));
		System.out.println(tt.trailing0s(46));
	}
}
