package com.interview.bits;

/**
 * http://www.careercup.com/question?id=5748016728244224
 * Square of number without using * or ^ operation.
 * Test cases
 * How to deal with negative number
 * 0
 * Power of 2 number
 * Regular numbers
 */
public class SquareOfNumber {

    public int square(int n){
        if(n < 0){
            n = -n;
        }
        int result = 0;
        int k = n;
        //saw we doing 7*7. First lets get rid of 3 from that 7 by below opeeration.
        //Once we are left with 4 then it all about using >> and <<
        while((k & (k-1))!= 0){
            result += n;
            k--;
        }
        
        while(k > 1){
            n = n<<1;
            k = k>>1;
        }
        return result + n;
    }
    
    public static void main(String args[]){
        SquareOfNumber sn = new SquareOfNumber();
        System.out.println(sn.square(9));
        System.out.println(sn.square(7));
        System.out.println(sn.square(6));
        System.out.println(sn.square(8));
        System.out.println(sn.square(14));
    }
}