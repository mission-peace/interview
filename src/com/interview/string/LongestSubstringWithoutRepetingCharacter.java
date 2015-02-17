package com.interview.string;

import java.util.HashSet;
import java.util.Set;

/**
 * http://www.geeksforgeeks.org/length-of-the-longest-substring-without-repeating-characters/
 * Test cases
 * All unique characters
 * all repetitions
 * combination of unique and reps
 */
public class LongestSubstringWithoutRepetingCharacter {

    public int longestSubstring(char str[]){
        int maxLen = -1 ;
        int len =0;
        int start=0;
        Set<Character> visited = new HashSet<Character>();
        for(int i=0; i < str.length; i++){
            //if visited contains current character 
            //remove all characters from start till previous version of current
            //character if found.
            if(visited.contains(str[i])){
                if(len > maxLen){
                    maxLen = len;
                }
                do{
                    visited.remove(str[start]);
                    start++;
                    len--;
                }while(str[start-1] != str[i]);
            }
            //this needs to be done always no matter character is found in visisted
            //or not
            visited.add(str[i]);
            len++;
        }
        return Math.max(len, maxLen);
    }
    
    public static void main(String args[]){
        LongestSubstringWithoutRepetingCharacter lsw = new LongestSubstringWithoutRepetingCharacter();
        System.out.println(lsw.longestSubstring("ABCDECAMNCZB".toCharArray()));
    }
}
