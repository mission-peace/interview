package com.interview.dynamic;

/**
 http://www.geeksforgeeks.org/dynamic-programming-set-4-longest-common-subsequence/
 */
public class LongestCommonSubsequence {

    public int lcs(char str1[],char str2[],int len1, int len2){
        
        if(len1 == str1.length || len2 == str2.length){
            return 0;
        }
        if(str1[len1] == str2[len2]){
            return 1 + lcs(str1,str2,len1+1,len2+1);
        }
        else{
            return Math.max(lcs(str1,str2,len1+1,len2),lcs(str1,str2,len1,len2+1));
        }
    }

    public int lcsDynamic(char str1[],char str2[]){
        //populate 1st row+column with 0 since algorithm makes decisions based on prior row/col's values
        int temp[][] = new int[str1.length + 1][str2.length + 1]; //initialized with extra row/col
        int max = 0;
        for(int i=1; i < temp.length; i++){ //java is "row major", so row first
            for(int j=1; j < temp[i].length; j++){ //column
                if(str1[i-1] == str2[j-1]) {
                    temp[i][j] = temp[i - 1][j - 1] + 1; //-1 diagonal's value +1 when match
                }
                else
                {
                    temp[i][j] = Math.max(temp[i][j-1],temp[i-1][j]); //copy max(prior row,column)
                }
                if(temp[i][j] > max){
                    max = temp[i][j];
                }
            }
        }
        return max;
    
    }
    
    public static void main(String args[]){
        LongestCommonSubsequence lcs = new LongestCommonSubsequence();
        String str1 = "ABCDGHLQR";
        String str2 = "AEDPHR";
        
        int result = lcs.lcsDynamic(str1.toCharArray(), str2.toCharArray());
        System.out.print(result);
    }
    
    
    
}
