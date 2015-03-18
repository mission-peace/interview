package com.interview.stackqueue;

import java.util.Deque;
import java.util.LinkedList;

/**
 * Date 03/17/2015
 * @author tusroy
 * 
 * Given a string with unbalanced brackets how do you remove minimum number
 * of extra brackets so that you are left with balanced brackets in the string
 * 
 * Solution
 * Keep a stack. When non bracket character shows up just skip it.
 * When an opening bracket shows up just add it.
 * When closing bracket shows up, see if top of stack is opening bracket. If yes
 * then just remove that from stack else add closing bracket into the stack.
 * 
 * Test cases:
 * empty string
 * String with )(
 * String with all opening brackets
 * String with all closing brackets
 * String with mix of open close brackets and characters between them
 *
 */
public class RemoveExtraBrackets {

    public int remove(char input[]){
        if(input == null){
            return 0;
        }
        Deque<Integer> dq = new LinkedList<Integer>();
        for(int i=0; i < input.length; i++){
            //skip non bracket characters
            if(input[i] != '(' && input[i] != ')'){
                continue;
            }
            
            //add opening brackets
            if(input[i] == '('){
                dq.addFirst(i);
            }
            else if(input[i] == ')'){
                //if top is opening bracket just remove from stack else add closing bracket
                if(!dq.isEmpty() && input[dq.peekFirst()] == '('){
                    dq.pollFirst();
                }else{
                    dq.addFirst(i);
                }
            }
        }
        int index = 0;
        //iterate through list again and don't add leftover
        //characters from stack in final result
        for(int i=0; i < input.length; i++){
            if(!dq.isEmpty() && i == dq.peekLast()) {
                dq.pollLast();
            }else {
                input[index++] = input[i];
            }
        }
        return index;
    }
    
    public static void printArray(char input[], int size) {
        for(int i=0; i < size; i++){
            System.out.print(input[i] + " ");
        }
        System.out.println();
    }
    
    public static void main(String args[]){
        RemoveExtraBrackets reb = new RemoveExtraBrackets();
        char input1[] = ")(".toCharArray();
        int pos = reb.remove(input1);
        printArray(input1, pos);
        
        char input2[] = "(((abc)(lm)(()".toCharArray();
        pos = reb.remove(input2);
        printArray(input2, pos);
        
        char input3[] = "(((c)(l))))(()))".toCharArray();
        pos = reb.remove(input3);
        printArray(input3, pos);
 
        char input4[] = "((((".toCharArray();
        pos = reb.remove(input4);
        printArray(input4, pos);
 
        char input5[] = "))))".toCharArray();
        pos = reb.remove(input5);
        printArray(input5, pos);
 
    }
}
