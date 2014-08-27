package com.interview.string;

public class SubstringSearch {

    public boolean hasSubstring(char[] str, char[] subString){
        
        int i=0;
        int j=0;
        int k = 0;
        while(i < str.length && j < subString.length){
            if(str[i] == subString[j]){
                i++;
                j++;
            }else{
                j=0;
                k++;
                i = k;
            }
        }
        if(j == subString.length){
            return true;
        }
        return false;
    }
    
    private int[] computeLPSArray(char str[]){
        
        int [] lps = new int[str.length];
        int index =0;
        for(int i=1; i < str.length;){
            if(str[i] == str[index]){
                lps[i] = index + 1;
                index++;
                i++;
            }else{
                if(index != 0){
                    index = lps[index-1];
                }else{
                    lps[i] =0;
                    i++;
                }
            }
        }
        return lps;
    }
    
    public boolean KMP(char []str, char []subString){
        
        int lps[] = computeLPSArray(subString);
        int i=0;
        int j=0;
        while(i < str.length && j < subString.length){
            if(str[i] == subString[j]){
                i++;
                j++;
            }else{
                if(j!=0){
                    j = lps[j-1];
                }else{
                    i++;
                }
            }
        }
        if(j == subString.length){
            return true;
        }
        return false;
    }
        
    public static void main(String args[]){
        
        String str = "AABDAABDAABLM";
        String subString = "AABDAABL";
        SubstringSearch ss = new SubstringSearch();
        boolean result = ss.KMP(str.toCharArray(), subString.toCharArray());
        System.out.print(result);
        
    }
}
