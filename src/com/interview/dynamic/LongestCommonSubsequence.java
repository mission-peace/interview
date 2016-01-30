package com.interview.dynamic;

/**
 http://www.geeksforgeeks.org/longest-common-substring/
 * @author RANDHESI
 */
public class LongestCommonSubsequence {

    public int lcs(char str1[], char str2[], int len1, int len2) {

        if (len1 == 0 || len2 == 0) {
            return 0;
        }
        if (str1[len1 - 1] == str2[len2 - 1]) {
            return 1 + lcs(str1, str2, len1 - 1, len2 - 1);
        } else {
            return Math.max(lcs(str1, str2, len1 - 1, len2), lcs(str1, str2, len1, len2 - 1));
        }
    }

    public int lcsDynamic(char str1[], char str2[]) {

        int temp[][] = new int[str1.length + 1][str2.length + 1];
        int max = 0;
        for (int i = 1; i < temp.length; i++) {
            for (int j = 1; j < temp[i].length; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    temp[i][j] = temp[i - 1][j - 1] + 1;
                } else {
                    temp[i][j] = Math.max(temp[i][j - 1], temp[i - 1][j]);
                }
                if (temp[i][j] > max) {
                    max = temp[i][j];
                }
            }
        }
        System.out.print("Longest Common Sequence is : ");
        for (int i = 1; i < temp.length; i++) {
            if (temp[i][str2.length] > temp[i - 1][str2.length]) {
                System.out.print(str1[i - 1] + ",");
            }
        }

        return max;

    }

    public static void main(String args[]) {
        LongestCommonSubsequence lcs = new LongestCommonSubsequence();
        String str1 = "ABCDGHLQR";
        String str2 = "AEDPHRGHLQR";

        int result = lcs.lcsDynamic(str1.toCharArray(), str2.toCharArray());

        System.out.print("\nDyanamic Programming Approach Leghth is = " + result);

        int result2 = lcs.lcs(str1.toCharArray(), str2.toCharArray(), str1.length(), str2.length());

        System.out.println("\nNaive appoach length = " + result2);
    }

}
