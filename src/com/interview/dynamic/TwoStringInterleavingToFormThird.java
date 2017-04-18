package com.interview.dynamic;

/**
 *
 * http://www.geeksforgeeks.org/check-whether-a-given-string-is-an-interleaving-of-two-other-given-strings-set-2/
 */
public class TwoStringInterleavingToFormThird {

    public boolean isInterleavedRecursive(char str1[], char str2[], char str3[],int pos1, int pos2, int pos3){
        if(pos1 == str1.length && pos2 == str2.length && pos3 == str3.length){
            return true; // recursion successful
        }
        
        if(pos3 == str3.length){
            return false; // end of recursion without using all input char
        }
        // char1 matches char3, increment pos1 && pos3, enter recursion ||
        // char2 matches char3, increment pos2 && pos3, enter recursion
        return (pos1 < str1.length 
                    && str1[pos1] == str3[pos3] 
                    && isInterleavedRecursive(str1, str2, str3, pos1+1, pos2, pos3+1))
            || (pos2 < str2.length 
                    && str2[pos2] == str3[pos3] 
                    && isInterleavedRecursive(str1, str2, str3, pos1, pos2+1, pos3+1));
        
    }
    // string C is interleaved string of A & B
    public boolean isInterleaved(char[] A, char[] B, char[] C){
        // A runs horizontally, B runs vertically
        boolean T[][] = new boolean[A.length +1][B.length +1];
        
        // string C can be an interleaving of string A and string B only if 
        // sum of lengths A & B is equal to length of C
        if(A.length + B.length != C.length){
            return false;
        }
        
        for(int r=0; r < T.length; r++){ //fill matrix topRow down
            for(int c=0; c < T[r].length; c++){ //fill matrix column left2right
                int p = r + c -1; //p: position on C
                // two empty strings have an empty string as interleaving
                if(r == 0 && c == 0){
                    T[r][c] = true;
                }
                // A is empty
                else if(r == 0){
                    if(C[p] == B[c-1]){
                        T[r][c] = T[r][c-1];
                    }
                }
                // B (column) is empty
                else if(c == 0){
                    if(A[r-1] == C[p]){
                        T[r][c] = T[r-1][c];
                    }
                }
                else{
                    // charA matches charC ? check if previous charB is valid ||
                    // charB matches charC ? check if previous charA is valid
                    T[r][c] = (A[r-1] == C[p] ? T[r-1][c] : false) 
                            || (B[c-1] == C[p] ? T[r][c-1] : false);
                }
            }
        }
        return T[A.length][B.length];
    }
    
    public static void main(String args[]){
        String str1 = "XXYM";
        String str2 = "XXZT";
        String str3 = "XXXZXYTM";
        TwoStringInterleavingToFormThird sti = new TwoStringInterleavingToFormThird();
        System.out.println(sti.isInterleaved(str1.toCharArray(), str2.toCharArray(), str3.toCharArray()));
    }
    
}
