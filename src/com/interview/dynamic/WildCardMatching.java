package com.interview.dynamic;

/**
 * Date 02/11/2016
 * @author Tushar Roy
 *
 * Wild car matching with ? and *
 *
 * Reference
 * https://leetcode.com/problems/wildcard-matching/
 */
public class WildCardMatching {
    // bottom up solution
    // Space complexity: O(patternLength * stringLength)
    // Time complexity: O(patternLength * stringLength)
    //   since each cell is written once
    public boolean isMatch(String stringIn, String patternIn) {
        char[] str = stringIn.toCharArray();
        char[] pattern = patternIn.toCharArray();

        //replace multiple * with one * since it's logically same
        //e.g a**b***c --> a*b*c
        int writeIndex = 0; // new pattern length after condensing *s
        boolean isFirst = true;
        for ( int i = 0 ; i < pattern.length; i++) {
            if (pattern[i] == '*') {
                if (isFirst) {
                    pattern[writeIndex++] = pattern[i];
                    isFirst = false;
                }
            } else {
                pattern[writeIndex++] = pattern[i];
                isFirst = true;
            }
        }
        // booleanMatrix[stringRow][patternColumn]
        boolean T[][] = new boolean[str.length + 1][writeIndex + 1];

        //corner case where pattern starts with *
        if (writeIndex > 0 && pattern[0] == '*') {
            T[0][1] = true;
        }

        T[0][0] = true; // null string == null pattern

        for (int s = 1; s < T.length; s++) {
            for (int p = 1; p < T[0].length; p++) {
                //valid char match
                if (pattern[p-1] == '?' || str[s-1] == pattern[p-1]) { //single char
                    //up+left cell indicates if all prior string matches pattern
                    T[s][p] = T[s-1][p-1]; 
                } else if (pattern[p-1] == '*'){ //any number of char
                    // T[s][p-1]: subtract * from pattern indicating * == blank
                    //   and determine match from left cell
                    // T[s-1][p]: * represents current stringChar. subtract char
                    //   and determine match from above cell
                    T[s][p] = T[s-1][p] || T[s][p-1];
                }
            }
        }

        return T[str.length][writeIndex];
    }


    /**
     * Recursive and slow version of wild card matching.
     */
    public boolean isMatchRecursive(String s, String p) {
        return isMatchRecursiveUtil(s.toCharArray(), p.toCharArray(), 0, 0);
    }

    // posT: position Text, posP: position Pattern
    private boolean isMatchRecursiveUtil(char[] text, char[] pattern, int posT, int posP) {
        if (posP == pattern.length) {
            return text.length == posT;
        }

        if (pattern[posP] != '*') {
            if (posT < text.length && (text[posT] == pattern[posP]) || pattern[posP] == '?') {
                // valid match, increment posT && posP, enter recursion
                return isMatchRecursiveUtil(text, pattern, posT + 1, posP + 1);
            } else {
                return false; // exit condition
            }
        } else { // pattern[] == *
            //if we have a***b then skip to the last *
            while (posP < pattern.length - 1 && pattern[posP + 1] == '*') {
                posP++;
            }
            posT--; // backstep text[] in case * represents textChar
            while (posT < text.length) {
                if (isMatchRecursiveUtil(text, pattern, posT + 1, posP + 1)) {
                    return true;
                }
                posT++; // advance text[] until stringChar matches patternChar
            } // end of text[], no match, return false
            return false;
        }
    }

    public static void main(String args[]) {
        WildCardMatching wcm = new WildCardMatching();
        System.out.println(wcm.isMatch("xbylmz", "x?y*z"));
    }
}
