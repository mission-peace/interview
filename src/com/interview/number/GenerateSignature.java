package com.interview.number;

/**
 * You are given an array of n elements [1,2,....n]. For example {3,2,1,6,7,4,5}.
Now we create a signature of this array by comparing every consecutive pair of elements.
If they increase, write I else write D. For example for the above array, 
the signature would be "DDIIDI". The signature thus has a length of N-1. Now the question is given a signature, 
compute the lexicographically smallest permutation of [1,2,....n]. 
Write the below function in language of your choice.
 */
public class GenerateSignature {

    /**
     * Idea is first to get long increasing subsequence sum using kadane. Then see if we have enough
     * I before longest kadane sequence. If yes then we can start filling with 1 else use kadane - I's count to start
     * the increasing sequence.
     * @param input
     * @return
     */
    public int[] generate(char input[]){
        Pair p = kadane(input);
        int result[] = new int[input.length+1];
        if(p.start == -1){
            fillResult(input,result,1);
            return result;
        }
        int count = 0;
        for(int i = 0; i < p.start; i++){
            if(input[i] == 'I'){
                count++;
            }else{
                count--;
            }
        }
        fillResult(input,result,count < p.size ? p.size - count +1 : 1);
        return result;
        
    }
    
    private void fillResult(char input[],int result[], int start){
        result[0] = start;
        for(int i=0 ; i < input.length; i++){
            if(input[i] == 'D'){
                result[i+1] = result[i] -1;
            }else{
                result[i+1] = result[i] + 1;
            }
        }
    }
    
    class Pair{
        int start;
        int size;
    }
    
    private Pair kadane(char input[]){
        int max = -1;
        int index = 0;
        int val = 0;
        int sum = 0;
        for(int i =0; i < input.length; i++){
            val = input[i] == 'D' ? 1 : -1;
            sum += val;
            if(sum <= 0){
                sum = 0;
                index = i+1;
                continue;
            }
            if(max < sum){
                max = sum;
            }
        }
        Pair p = new Pair();
        p.size = max;
        p.start = index;
        return p;
    }
    
    public static void main(String args[]){
        String input = "IIIDIIDDDDIIDDD";
        GenerateSignature gs = new GenerateSignature();
        int result[] = gs.generate(input.toCharArray());
        for(int i=0; i < result.length; i++){
            System.out.print(result[i] + " ");
        }
    }
}
