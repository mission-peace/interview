package com.interview.number;

/**
 * http://www.geeksforgeeks.org/write-a-c-program-to-calculate-powxn/
 */
public class PowerFunction {

    public int power(int n, int m){
        if(m == 0){
            return 1;
        }
        int pow = power(n,m/2);
        if(m % 2 ==0){
            return pow*pow;
        }else{
            return n*pow*pow;
        }
    }
    
    public static void main(String args[]){
        PowerFunction pf = new PowerFunction();
        long pow = pf.power(3, 5);
        System.out.print(pow);
    }
}
