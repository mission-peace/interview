package com.interview.dynamic;
/**
 * Date 06/24/2015
 * @author Tushar Roy
 * 
 * Write a program to perform regex matching with * an . 
 * 
 * References : http://leetcode.com/2011/09/regular-expression-matching.html
 */
public class RegexMatching {

    public boolean matchRegexRecursive(char[] str, char[] pattern){
        return matchRegexRecursive(str,pattern,0,0);
    }
    
    private boolean matchRegexRecursive(char text[], char pattern[], int posT, int posP){
        //if posP has reached end of pattern 
        //means posP should also reach end of text for match to happen
        if(posP == pattern.length) { 
            return posT == text.length;
        } 
      
        //if next character is not * means either current value at pattern and text should be same
        //or current value at pattern should be . in which case you can skip one character of text
        if(posP == pattern.length - 1 || pattern[posP+1] != '*') {
            return (posT < text.length && (text[posT] == pattern[posP] 
                    || pattern[posP] == '.')) && matchRegexRecursive(text, pattern, posT+1, posP+1);
        }
  
        //if we have case like abc and ad*bc so here we totally skip d*
        if(matchRegexRecursive(text, pattern, posT, posP+2)){
            return true;
        }
  
        //For case like abbc and ab*c match first b with b* and then next b to c. 
        //If that does not work out then try next b with b* and then c with c and so on.
        //if pattern current val is . then skip one character at time from text till we either reach end of text
        //or a match is found
        while(posT < text.length && (text[posT] == pattern[posP] || pattern[posP] == '.')){
            if( matchRegexRecursive(text, pattern, posT+1, posP+2)){
                return true;
            }
            posT++;
        }
        return false;
    }

    /**
     * Dynamic programming technique for regex matching.
     * bottom up solution
     * Space complexity: O(patternLength * stringLength)
     * Time complexity: O(patternLength * stringLength)
     *   since each cell is written once
     */
    public boolean matchRegex(char[] text, char[] pattern) {
        // booleanMatrix[textRow][patternColumn]
        boolean T[][] = new boolean[text.length + 1][pattern.length + 1];

        T[0][0] = true; // 0 text matches 0 pattern
        //Deals with patterns like a* or a*b* or a*b*c*
        for (int i = 1; i < T[0].length; i++) {
            if (pattern[i-1] == '*') {
                T[0][i] = T[0][i - 2];
            }
        }

        // since matrix[t][p] starts at 1, adjust matrix index by -1
        for (int t = 1; t < T.length; t++) {
            for (int p = 1; p < T[0].length; p++) {
                // pattern'.' always true || valid char match
                if (pattern[p - 1] == '.' || pattern[p - 1] == text[t - 1]) {
                    // subtract matching char, check if all prior matches
                    T[t][p] = T[t-1][p-1];
                } else if (pattern[p - 1] == '*')  {
                    T[t][p] = T[t][p - 2]; // 0 occurances of char before *
                    // '.*' allows any combination of 0+ characters
                    // || textChar == patternCharBefore*
                    if (pattern[p-2] == '.' || pattern[p - 2] == text[t - 1]) {
                        // skip current textChar by copying result of prior textChar
                        // OR keep true from T[t][p-2]
                        T[t][p] = T[t][p] | T[t - 1][p]; //bitwise OR assignment
                    }
                } else {
                    T[t][p] = false;
                }
            }
        }
        return T[text.length][pattern.length];
    }

    public static void main(String args[]){
        RegexMatching rm = new RegexMatching();
        System.out.println(rm.matchRegexRecursive("Tushar".toCharArray(),"Tushar".toCharArray()));
        System.out.println(rm.matchRegexRecursive("Tusha".toCharArray(),"Tushar*a*b*".toCharArray()));
        System.out.println(rm.matchRegexRecursive("".toCharArray(),"a*b*".toCharArray()));
        System.out.println(rm.matchRegexRecursive("abbbbccc".toCharArray(),"a*ab*bbbbc*".toCharArray()));
        System.out.println(rm.matchRegexRecursive("abbbbccc".toCharArray(),"aa*bbb*bbbc*".toCharArray()));
        System.out.println(rm.matchRegexRecursive("abbbbccc".toCharArray(),".*bcc".toCharArray()));
        System.out.println(rm.matchRegexRecursive("abbbbccc".toCharArray(),".*bcc*".toCharArray()));
        System.out.println(rm.matchRegexRecursive("abbbbccc".toCharArray(),".*bcc*".toCharArray()));
        System.out.println(rm.matchRegexRecursive("aaa".toCharArray(),"ab*a*c*a".toCharArray()));

        System.out.println(rm.matchRegex("aa".toCharArray(), "a*".toCharArray()));
    }
}
