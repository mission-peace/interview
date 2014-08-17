package com.interview.number;

/**
 * 150qs hard section
 */
public class Trailing0sinFactorial {

    public int trailing0s(int num){
        
        int total = num/5;
        
        int pow = 1;
        while(pow <= num){
            pow = pow*5;
        }
        
        pow /= 5;
        
        int index = 1;
        while(pow > 5){
            total = total + index;
            index++;
            pow = pow/5;
        }
        
        return total;
    }
    
    public static void main(String args[]){
        Trailing0sinFactorial t0 = new Trailing0sinFactorial();
        System.out.println(t0.trailing0s(625));
        System.out.println(t0.trailing0s(146));
        System.out.println(t0.trailing0s(1046));
        System.out.println(t0.trailing0s(46));
    
    }
}
