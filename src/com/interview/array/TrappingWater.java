package com.interview.array;
/**
 * https://oj.leetcode.com/problems/trapping-rain-water/
 */
public class TrappingWater {

    public int trapWater(int input[]){
        if(input.length < 2){
            return 0;
        }
        
        int maxFoundSoFar = 0;
        int result = 0;
        for(int i = 1; i < input.length; i++){
            if(input[i] < input[maxFoundSoFar]){
                continue;
            }
            else{
                int minOfTwo = Math.min(input[maxFoundSoFar], input[i]);
                for(int j = i-1; j > maxFoundSoFar; j--){
                    if(minOfTwo > input[j]){
                        result += minOfTwo - input[j];
                    }else{
                        minOfTwo = input[j];
                    }
                }
                maxFoundSoFar = i;
            }
        }
        
        int minOfTwo = input[input.length-1];
        for(int j = input.length-2; j > maxFoundSoFar; j--){
            if(minOfTwo > input[j]){
                result += minOfTwo - input[j];
            }else{
                minOfTwo = input[j];
            }
        }
        return result;
    }
   
    /**
     * Keep two array left and right which has max till that point
     * either from left side or right side. 
     * Now for every point i check if it is less than left[i] and right[i].
     * If yes then add this to total since water can be trapped here.
     * @param input
     * @return
     */
    public int trapWater1(int input[]){
        assert input != null && input.length > 0;
        int left[] = new int[input.length];
        int right[] = new int[input.length];
        left[0] = input[0];
        for(int i=1; i < input.length; i++){
            left[i] = (input[i] > left[i-1] ? input[i] : left[i-1]);
        }
        right[input.length-1] = input[input.length-1];
        for(int i=input.length-2; i >= 0; i--){
            right[i] = (input[i] > right[i+1] ? input[i] : right[i+1]);
        }
        
        int result = 0;
        for(int i=1; i < input.length-1; i++){
            int min = Math.min(left[i], right[i]) - input[i];
            if(min > 0){
                result += min;
            }
        }
        return result;
    }
    
    public static void main(String args[]){
        int input[] = {0,1,0,2,1,0,1,3,2,1,2,1};
        TrappingWater tw = new TrappingWater();
        System.out.println(tw.trapWater(input));
        System.out.println(tw.trapWater1(input));
    }
}
