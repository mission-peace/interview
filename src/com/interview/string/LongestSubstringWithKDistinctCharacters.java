package com.interview.string;

/**
 * Date 04/03/2016
 * @author Tushar Roy
 *
 * Given a string, find the length of the longest substring T that contains at most k distinct characters.
 * For example, Given s = “eceba” and k = 2,
 * T is "ece" which its length is 3.
 *
 * Time complexity O(n)
 * Space complexity O(n)
 *
 * https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/
 */
public class LongestSubstringWithKDistinctCharacters {
    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        if (k == 0 || s.length() == 0) {
            return 0;
        }
        int[] ascii = new int[256];
        int count = 0;
        int start = 0;
        int max = 0;
        for (int i = 0; i < s.length(); i++) {
            int ch = s.charAt(i);
            if (count < k) {
                if (ascii[ch] == 0) {
                    count++;
                }
            } else if (ascii[ch] == 0){
                while (start < i) {
                    char ch1 = s.charAt(start++);
                    ascii[ch1]--;
                    if (ascii[ch1] == 0) {
                        break;
                    }
                }
            }
            ascii[ch]++;
            max = Math.max(max, i - start + 1);
        }
        return max;
    }
}
