package com.interview.stackqueue;

import java.util.Deque;
import java.util.LinkedList;

/**
 * http://www.geeksforgeeks.org/largest-rectangle-under-histogram/
 * The reason it works is because it always keeps minimum till the point in the queue and 
 * multiplies minimum with i+1;
 */
public class MaximumHistogram {

    public int maxHistogram(int input[]){
        Deque<Integer> stack = new LinkedList<Integer>();
        int maxArea = 0;
        int area = 0;
        int i;
        for(i=0; i < input.length;){
            if(stack.isEmpty() || input[stack.peekFirst()] <= input[i]){
                stack.offerFirst(i++);
            }else{
                int top = stack.pollFirst();
                area = input[top] * (i - (!stack.isEmpty() ? stack.peekFirst() : -1) -1);
                if(area > maxArea){
                    maxArea = area;
                }
            }
        }
        while(!stack.isEmpty()){
            int top = stack.pollFirst();
            area = input[top] * (i - (!stack.isEmpty() ? stack.peekFirst() : -1 ) -1 );
            if(area > maxArea){
                maxArea = area;
            }
        }
        return maxArea;
    }
    
    public static void main(String args[]){
        MaximumHistogram mh = new MaximumHistogram();
        int input[] = {2,2,2,6,1,5,4,2,2,2,2};
        System.out.println(mh.maxHistogram(input));
    }
}
