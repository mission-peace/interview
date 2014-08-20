package com.interview.array;

import java.util.Deque;
import java.util.LinkedList;

/**
 * http://www.geeksforgeeks.org/next-greater-element/
 */
public class LargerElementOnRight {

    public int[] larger(int input[]){
        Deque<Integer> stack = new LinkedList<Integer>();
        int result[] = new int[input.length];
        for(int i=0; i < result.length; i++){
            result[i] = -1;
        }
        
        stack.offerFirst(0);
        for(int i=1; i < input.length; i++){
            while(stack.size() > 0){
                int t = stack.peekFirst();
                if(input[t] < input[i]){
                    result[t] = i;
                    stack.pollFirst();
                }else{
                    break;
                }
            }
            stack.offerFirst(i);
        }
        return result;
    }
    
    public static void main(String args[]){
        LargerElementOnRight leo = new LargerElementOnRight();
        int input[] = {4,2,8,6,0,-3,-1,1,9};
        int result[] = leo.larger(input);
        for(int i=0; i < result.length; i++){
            System.out.print(result[i]);
        }
    }
}
