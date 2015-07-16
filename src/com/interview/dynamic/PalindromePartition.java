package com.interview.dynamic;

/**
 * http://www.geeksforgeeks.org/dynamic-programming-set-17-palindrome-partitioning/
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
    
    public static void main(String args[]){
        String str = "ABCCDCCLMLCCD";
        PalindromePartition pp = new PalindromePartition();
        int r = pp.minCuts(str.toCharArray());
        System.out.print(r);
    }
}
