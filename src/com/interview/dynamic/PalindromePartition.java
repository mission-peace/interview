package com.interview.dynamic;

import com.interview.recursion.StringPermutation;

import java.util.*;

/**
 * Date 04/03/2016
 * @author Tushar Roy
 *
 * http://www.geeksforgeeks.org/dynamic-programming-set-17-palindrome-partitioning/
 * https://leetcode.com/problems/palindrome-partitioning/
 */
public class PalindromePartition {

    public int minCuts(char[] str){
        
        int T[][] = new int[str.length][str.length];
        boolean P[][] = new boolean[str.length][str.length];
        
        for(int i=0; i < P.length; i++){
            P[i][i] = true;
        }
        
        for(int l= 2; l <= str.length; l++){
            for(int i = 0; i <= str.length - l; i++){
                int j = i + l-1;
                if(l == 2){
                    P[i][j] = str[i] == str[j];
                }else{
                    P[i][j] = (str[i] == str[j]) && P[i+1][j-1];
                }
                if(P[i][j]){
                    T[i][j] = 0;
                }else{
                    T[i][j] = 10000;
                    int r = 0;
                    for(int k = i; k < j; k++){
                        r = T[i][k] + T[k+1][j] +1 ;
                        if(r < T[i][j]){
                            T[i][j] = r;
                        }
                    }
                }
            }
        }
        return T[0][T.length-1];
    }

    /**
     * Given a string s, partition s such that every substring of the partition is a palindrome.
     * https://leetcode.com/problems/palindrome-partitioning/
     */
    public List<List<String>> partition(String s) {
        Map<Integer, List<List<String>>> dp = new HashMap<>();
        List<List<String>> result =  partitionUtil(s, dp, 0);
        List<List<String>> r = new ArrayList<>();
        for (List<String> l : result) {
            r.add(l);
        }
        return r;
    }

    private List<List<String>> partitionUtil(String s, Map<Integer, List<List<String>>> dp, int start) {
        if (start == s.length()) {
            List<String> r = new ArrayList<>();
            return Collections.singletonList(r);
        }

        if (dp.containsKey(start)) {
            return dp.get(start);
        }

        List<List<String>> words = new ArrayList<>();
        for (int i = start; i < s.length(); i++) {
            if (!isPalindrome(s, start, i) ) {
                continue;
            }
            String newWord = s.substring(start, i + 1);
            List<List<String>> result = partitionUtil(s, dp, i + 1);
            for (List l : result) {
                List<String> l1 = new ArrayList<>();
                l1.add(newWord);
                l1.addAll(l);
                words.add(l1);
            }
        }
        dp.put(start, words);
        return words;
    }

    private  boolean isPalindrome(String str, int r, int t) {
        while(r < t) {
            if (str.charAt(r) != str.charAt(t)) {
                return false;
            }
            r++;
            t--;
        }
        return true;
    }
}
