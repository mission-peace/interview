package com.interview.stackqueue;

import java.util.Deque;
import java.util.LinkedList;

/**
 * 12/23/2014
 * @author tusroy
 * 
 * Video link https://youtu.be/ZmnqCZp9bBs
 * 
 * Given an array representing height of bar in bar graph, find max histogram
 * area in the bar graph. Max histogram will be max rectangular area in the
 * graph.
 * 
 * Maintain a stack
 * 
 * If stack is empty or value at index of stack is less than or equal to value at current 
 * index, push this into stack.
 * Otherwise keep removing values from stack till value at index at top of stack is 
 * less than value at current index.
 * While removing value from stack calculate area
 * if stack is empty 
 * it means that till this point value just removed has to be smallest element
 * so area = input[top] * i
 * if stack is not empty then this value at index top is less than or equal to 
 * everything from stack top + 1 till i. So area will
 * area = input[top] * (i - stack.peek() - 1);
 * Finally maxArea is area if area is greater than maxArea.
 * 
 * 
 * Time complexity is O(n)
 * Space complexity is O(n)
 * 
 * References:
 * http://www.geeksforgeeks.org/largest-rectangle-under-histogram/
 */
public class MaximumHistogram {

    public int maxHistogram(int input[]){
        Stack<Integer> s=new Stack<Integer>();
        int maxArea = 0;
        int area = 0;
        int i;
        for(i=0; i < input.length;i++){
           if(s.size()==0){
                s.push(i);
                        }
            else{
                    //if height at current index in greater than height at index=s.peek()
                    //then while loop will not execute and current index will directly be
                    //pushed to the stack
                    while(s.size()!=0 && input[i]<=input[s.peek()]){
                        area=0;
                       
                       int height=input[s.pop()];
                //if stack is empty means everything till i has to be
                //greater or equal to input[top] so width =i ;
                
                //if stack is not empty then everythin from i-1 to input.peek() + 1
                //has to be greater or equal to input[top]
                //so width = i - stack.peek() - 1;
                       int width=s.size()==0?i:i-s.peek()-1;
                       area=width*height;
                       if(area>maxArea){maxArea=area;}
                   }
                
                s.push(i); 
               
            }
        }
    
        return maxArea;
    }
    
    public static void main(String args[]){
        MaximumHistogram mh = new MaximumHistogram();
        int input[] = {2,2,2,6,1,5,4,2,2,2,2,-1};
        int maxArea = mh.maxHistogram(input);
        //System.out.println(maxArea);
        assert maxArea == 12;
    }
}
