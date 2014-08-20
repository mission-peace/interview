package com.interview.array;

/**
 * http://www.careercup.com/question?id=5179916190482432
 * Look out for division by 0
 */
public class MultiplyAllFieldsExceptOwnPosition {

    public int[] multiply(int input[]){
        int result[] = new int[input.length];
        int left[] = new int[input.length];
        int right[] = new int[input.length];
        left[0] = 1;
        for(int i=1; i < input.length; i++){
            left[i] = left[i-1]*input[i-1];
        }
        
        right[input.length-1] = 1;
        for(int i=input.length-2; i >=0; i--){
            right[i] = right[i+1]*input[i+1];
        }
        
        for(int i=0;i < input.length; i++){
            result[i] = left[i]*right[i];
        }
        return result;
    }
    
    public static void main(String args[]){
        MultiplyAllFieldsExceptOwnPosition maf = new MultiplyAllFieldsExceptOwnPosition();
        int input[] = {2,3,4,5};
        int result[] = maf.multiply(input);
        for(int r : result){
            System.out.print(r + " ");
        }
    }
}
