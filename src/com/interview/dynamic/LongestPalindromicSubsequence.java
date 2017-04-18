package com.interview.dynamic;

/**
 * Date 08/01/2014
 * @author Tushar Roy
 *
 * Given a string find longest palindromic subsequence in this string.
 *
 * Time complexity - O(n2)
 * Space complexity - O(n2
 *
 * Youtube link - https://youtu.be/_nCsPn7_OgI
 *
 * References
 * http://www.geeksforgeeks.org/dynamic-programming-set-12-longest-palindromic-subsequence/
 */
public class LongestPalindromicSubsequence {

    public int calculate1(char []str){
        // Create a table to store results of subproblems
        // T[startOfSubsequence][endOfSubsequence]
        int T[][] = new int[str.length][str.length]; 
        // Strings of length 1 are palindrome of length 1
        for(int i=0; i < str.length; i++){
            T[i][i] = 1;
        }
        // Build the table. Note that the lower diagonal values of table are
        // useless and not filled in the process
        for(int L = 2; L <= str.length; L++){
            for(int i = 0; i < str.length-L + 1; i++){
                int j = i + L - 1;
                if(L == 2 && str[i] == str[j]){
                    T[i][j] = 2;
                }else if(str[i] == str[j]){
                    // startChar == endChar so +2
                    // plus longest palindrome in between
                    T[i][j] = T[i + 1][j-1] + 2;
                }else{
                    // copy max of inner subsequence
                    T[i][j] = Math.max(
                            T[i + 1][j], 
                            T[i][j - 1]);
                }
            } // increment subsequence Length
        }
        return T[0][str.length-1];
    }


    public int calculateRecursive(char str[],int start,int len){
        // Base Case: If there is only 1 character
        if(len == 1){
            return 1;
        }
        // Base Case: If there is no character
        if(len ==0){
            return 0;
        }
        if(str[start] == str[start+len-1]){
            // first and last characters match
            return 2 + calculateRecursive(str,start+1,len-2);
        }else{ // first and last characters do not match
            return Math.max(
                    calculateRecursive(str, start+1, len-1), 
                    calculateRecursive(str, start, len-1));
        }
    }
    
    /* Driver program to test above functions */
    public static void main(String args[]){
        LongestPalindromicSubsequence lps = new LongestPalindromicSubsequence();
        String str = "taco cat, taco cat!";
        int r1 = lps.calculateRecursive(str.toCharArray(), 0, str.length());
        int r2 = lps.calculate1(str.toCharArray());
        System.out.print(r1 + " " + r2);
    }
    
}
