package com.interview.string;

/**
 * http://www.geeksforgeeks.org/longest-palindrome-substring-set-1/
 * http://www.geeksforgeeks.org/longest-palindromic-substring-set-2/
 */
public class LongPanlindromeSubstring {

    public int longestPalindromeSubstringEasy(char arr[]) {

        int longest_substring = 1;
        for (int i = 0; i < arr.length; i++) {

            int x, y;
            int palindrome;
            x = i;
            y = i + 1;
            palindrome = 0;
            while (x >= 0 && y < arr.length && arr[x] == arr[y]) {
                x--;
                y++;
                palindrome += 2;
            }
            longest_substring = Math.max(longest_substring, palindrome);
            
            x = i - 1;
            y = i + 1;
            palindrome = 1;
            while (x >= 0 && y < arr.length && arr[x] == arr[y]) {
                x--;
                y++;
                palindrome += 2;
            }
            longest_substring = Math.max(longest_substring, palindrome);
        }
        return longest_substring;
    }
    
    public int longestPalindromeDynamic(char []str){
        boolean T[][] = new boolean[str.length][str.length];
        
        for(int i=0; i < T.length; i++){
            T[i][i] = true;
        }
        
        int max = 1;
        for(int l = 2; l <= str.length; l++){
            int len = 0;
            for(int i=0; i < str.length-l+1; i++){
                int j = i + l-1;
                len = 0;
                if(l == 2){
                    if(str[i] == str[j]){
                        T[i][j] = true;
                        len = 2;
                    }
                }else{
                    if(str[i] == str[j] && T[i+1][j-1]){
                        T[i][j] = true;
                        len = j -i + 1;
                    }
                }
                if(len > max){
                    max = len;
                }
            }
        }
        return max;
    }

    public static void main(String args[]) {

        char[] str = { 'a', 'b', 'a', 'e', 'a', 'b','a' };
        LongPanlindromeSubstring lps = new LongPanlindromeSubstring();
        int result = lps.longestPalindromeDynamic(str);
        System.out.print(result);
    }

}
