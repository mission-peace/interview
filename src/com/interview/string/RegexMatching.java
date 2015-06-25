package com.interview.string;
/**
 * Date 06/24/2015
 * @author tusroy
 * 
 * Write a program to perform regex matching with * an . 
 * 
 * References : http://leetcode.com/2011/09/regular-expression-matching.html
 * Leetcode verified solution
 */
public class RegexMatching {

    public boolean match(char[] str, char[] pattern){
        return match(str,pattern,0,0);
    }
    
    private boolean match(char text[], char pattern[], int pos1, int pos2){
        //if pos2 has reached end of pattern means pos2 should also reach end of text for match
        //to happen
        if(pos2 == pattern.length) { 
            return pos1 == text.length;
        } 
      
        //if next character is not * means either current value at pattern and text should be same
        //or current value at pattern should be . in which case you can skip one character of text
        if(pos2 == pattern.length - 1 || pattern[pos2+1] != '*') {
            return (pos1 < text.length && (text[pos1] == pattern[pos2] || pattern[pos2] == '.')) && match(text, pattern, pos1+1, pos2+1); 
        }
  
        //if we have case like abc and ad*bc so here we totally skip d*
        if(match(text, pattern, pos1, pos2+2)){
            return true;
        }
  
        //For case like abbc and ab*c match first b with b* and then next b to c. If that does not work out
        //then try next b with b* and then c with c and so on.
        //if pattern current val is . then skip one character at time from text till we either reach end of text
        //or a match is found
        while(pos1 < text.length && (text[pos1] == pattern[pos2] || pattern[pos2] == '.')){
            if( match(text, pattern, pos1+1, pos2+2)){
                return true;
            }
            pos1++;
        }
        return false;
    }
    
    public static void main(String args[]){
        RegexMatching rm = new RegexMatching();
        System.out.println(rm.match("Tushar".toCharArray(),"Tushar".toCharArray()));
        System.out.println(rm.match("Tusha".toCharArray(),"Tushar*a*b*".toCharArray()));
        System.out.println(rm.match("".toCharArray(),"a*b*".toCharArray()));
        System.out.println(rm.match("abbbbccc".toCharArray(),"a*ab*bbbbc*".toCharArray()));
        System.out.println(rm.match("abbbbccc".toCharArray(),"aa*bbb*bbbc*".toCharArray()));
        System.out.println(rm.match("abbbbccc".toCharArray(),".*bcc".toCharArray()));
        System.out.println(rm.match("abbbbccc".toCharArray(),".*bcc*".toCharArray()));
        System.out.println(rm.match("abbbbccc".toCharArray(),".*bcc*".toCharArray()));
        System.out.println(rm.match("aaa".toCharArray(),"ab*a*c*a".toCharArray()));
    }
}
