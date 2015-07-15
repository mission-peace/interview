package com.interview.dynamic;

/**
 http://www.geeksforgeeks.org/dynamic-programming-set-5-edit-distance/
 */
public class EditDistance {

    private static int EDIT_COST = 1;
    
    public int recEditDistance(char[]  str1, char str2[], int len1,int len2){
        
        if(len1 == str1.length){
            return str2.length - len2;
        }
        if(len2 == str2.length){
            return str1.length - len1;
        }
        return min(recEditDistance(str1,str2,len1+1,len2+1) + str1[len1] == str2[len2] ? 0 : 1, recEditDistance(str1,str2,len1,len2+1) + 1, recEditDistance(str1,str2,len1+1,len2) + 1);
    }
    
    private int min(int a,int b, int c){
        int l = Math.min(a, b);
        return Math.min(l, c);
    }
    
    
    public int dynamicEditDistance(char[] str1, char[] str2){
        int temp[][] = new int[str1.length+1][str2.length+1];
        
        for(int i=0; i < temp[0].length; i++){
            temp[0][i] = i;
        }
        
        for(int i=0; i < temp.length; i++){
            temp[i][0] = i;
        }
        
        for(int i=1;i <=str1.length; i++){
            for(int j=1; j <= str2.length; j++){
                if(str1[i-1] == str2[j-1]){
                    temp[i][j] = temp[i-1][j-1];
                }else{
                    temp[i][j] = min(temp[i-1][j-1] + 1,temp[i-1][j] + EDIT_COST,temp[i][j-1] + EDIT_COST);
                }
            }
        }
        return temp[str1.length][str2.length];
        
    }
    
    public static void main(String args[]){
        String str1 = "SUNDAY";
        String str2 = "SATURDAY";
        EditDistance editDistance = new EditDistance();
        int result = editDistance.dynamicEditDistance(str1.toCharArray(), str2.toCharArray());
        System.out.print(result);
    }

}
