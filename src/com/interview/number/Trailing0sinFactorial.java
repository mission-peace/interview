package com.interview.number;

/**
 * 150qs hard section
 */
public class Trailing0sinFactorial {

    public int trailing0s(int num){
        int pow = 5;
        int count = 0;
        while(pow <= num){
            count += num/pow;
            pow *= 5;
        }
        return count;
    }
    
    public static void main(String args[]){
        Trailing0sinFactorial t0 = new Trailing0sinFactorial();
        System.out.println(t0.trailing0s(625));
        System.out.println(t0.trailing0s(146));
        System.out.println(t0.trailing0s(1046));
        System.out.println(t0.trailing0s(4617));
    }
}
