package com.interview.number;

/**
 * Number such that 11 + 11 = 22, 11 +22 = 33, 22 +33 = 55
 */
public class AggregateNumber {

    public boolean isAggregateNumber(String number){
        for(int i=0; i < number.length()/2; i++){
            for(int j= i + 1; j <= number.length()/2; j++){
                int num1 = getNumber(number,0,i);
                int num2 = getNumber(number,i+1,j);
                int k=0;
                int r =0;
                boolean flag = false;
                int j1 = j;
                for(k=j1+1; k < number.length(); k++){
                    r = getNumber(number,j1+1,k);
                    flag = false;
                    if(num1 + num2 == r){
                        num1 = num2;
                        num2 = r;
                        j1 = k;
                        flag = true;
                    }
                }
                if(k == number.length() && flag){
                    return true;
                }
            }
        }
        return false;
    }
    
    private int getNumber(String number, int low, int high) {
        int pow = 1;
        int r = 0;
        for (int i = high; i >= low; i--) {
            r += pow * (number.charAt(i) - '0');
            pow *= 10;
        }
        return r;
    }
    
    public static void main(String args[]){
        String number = "111122335";
        AggregateNumber an= new AggregateNumber();
        System.out.println(an.isAggregateNumber(number));
    }
}
