package com.interview.number;

/**
 * http://saikatd.wordpress.com/author/saikatd/page/4/
 */
public class NotIncluding4 {

    public int number(int chinaNumber){
        
        int result = 0;
        int mul = 1;
        while(chinaNumber > 0){
            int r = chinaNumber % 10;
            chinaNumber /= 10;
            if(r == 4){
                throw new IllegalArgumentException();
            }
            if(r >=5){
                r--;
            }
            result += r*mul;
            mul = mul*9;
        }
        return result;
    }
    
    public static void main(String args[]){
        NotIncluding4 ni = new NotIncluding4();
        System.out.print(ni.number(16));
    }
}
