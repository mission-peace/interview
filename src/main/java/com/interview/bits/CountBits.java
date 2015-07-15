package com.interview.bits;

/**
 * http://www.geeksforgeeks.org/count-set-bits-in-an-integer/
 */
public class CountBits {

    public CountBits(){
        preCalculate();
    }
    public int countBits(int num){
        int count=0;
        while(num > 0){
            num &= num-1;
            count++;
        }
        return count;
    }
    
    private int count[] = new int[256];
    
    void preCalculate(){
        for(int i=0; i < 256; i++){
            count[i] = countBits(i);
        }
    }
    
    public int countBitsFaster(int num){
        //get 8 bits at a time and check count from count array
        int total = 0;
        int mask = (1<<8) - 1;
        for(int i=0 ; i < 4; i++){
            total += count[num & mask];
            num = num>>>8;
        }
        return total;
    }
    public static void main(String args[]){
        CountBits cb = new CountBits();
        System.out.println(cb.countBits(3636363));
        System.out.println(cb.countBitsFaster(3636363));
    }
}
