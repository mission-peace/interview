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
        Integer arr[] = {54,545,2,11,97};
        rni.rearrange(arr);
        for(int a : arr){
            System.out.print(a + " ");
        }
    }
}

class IntegerComparator implements Comparator<Integer>{

    /**
     * If o1 is 95 o2 is 116
     * Compare 95116 with 11695 and see which one is greater to pick first guy
     */
    @Override
    public int compare(Integer o1, Integer o2) {
        int pow1 = 1;
        while(pow1 <= o1){
            pow1 *= 10;
        }
        int pow2 = 1;
        while(pow2 <= o2){
            pow2 *= 10;
        }
        
        if(o1*pow2 + o2 >= o2*pow1 + o1){
            return -1;
        }else{
            return 1;
        }
   }
    
}
