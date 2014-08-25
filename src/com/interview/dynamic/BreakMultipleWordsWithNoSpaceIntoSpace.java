package com.interview.dynamic;

import java.util.HashSet;
import java.util.Set;

public class BreakMultipleWordsWithNoSpaceIntoSpace {

    public String breakWord(char[] str,int low,Set<String> dictionary){
        
        StringBuffer buff = new StringBuffer();
        for(int i= low; i < str.length; i++){
            buff.append(str[i]);
            if(dictionary.contains(buff.toString())){
                String result = breakWord(str, i+1, dictionary);
                if(result != null){
                    return buff.toString() + " " + result;
                }
            }
        }
        if(dictionary.contains(buff.toString())){
            return buff.toString();
        }
        return null;
    }
    
    public String dynamic(char str[], Set<String> dictionary){
        
        int[][] T = new int[str.length][str.length];
        for(int i=0; i < T.length; i++){
            for(int j=0; j < T[i].length; j++){
                if(i == j && dictionary.contains(str[i])){
                    T[i][j] = i;
                }else{
                    T[i][j] = -1;
                }
            }
        }
        StringBuffer buff = new StringBuffer();
        
        for(int l = 2; l <= str.length; l++){
            for(int i = 0; i <= str.length-l; i++){
                int j = i + l-1;
                buff.append(str[i]);
                int k;
                for(k=i+1; k <=j; k++){
                    if(dictionary.contains(buff.toString()) && T[k][j] != -1){
            //          T[i][j] = k;
                        break;
                    }
                    buff.append(str[k]);
                }
                if(dictionary.contains(buff.toString())){
                    T[i][j] = k;
                }
                buff.delete(0, buff.length());
            }
        }
        int low =0;
        int high = str.length-1;
        StringBuffer buffer = new StringBuffer();
        while(true){
            int r = T[low][high];
            if(r==-1){
                return null;
            }
            buffer.append(get(str,low,r)).append(" ");
            low = r;
            if(low == str.length){
                break;
            }
        }
        return buffer.toString();
    }
    
    /**
     * Easier implementation to understand
     * Gives preference to longer words over splits
     * e.g peanutbutter with dict{pea nut butter peanut} it would result in
     * peanut butter instead of pea nut butter. Above method does the opposite
     * @return
     */
    public String breakWordDP(String word, Set<String> dict){
        int T[][] = new int[word.length()][word.length()];
        
        for(int i=0; i < T.length; i++){
            for(int j=0; j < T[i].length ; j++){
                T[i][j] = -1;
            }
        }
        
        for(int l = 1; l <= word.length(); l++){
            for(int i=0; i < word.length() -l + 1 ; i++){
                int j = i + l-1;
                String str = word.substring(i,j+1);
                if(dict.contains(str)){
                    T[i][j] = i;
                    continue;
                }
                for(int k=i+1; k <= j; k++){
                    if(T[i][k-1] != -1 && T[k][j] != -1){
                        T[i][j] = k;
                        break;
                    }
                }
            }
        }
        if(T[0][word.length()-1] == -1){
            return null;
        }
        StringBuffer buffer = new StringBuffer();
        int i = 0; int j = word.length() -1;
        while(i < j){
            int k = T[i][j];
            if(i == k){
                buffer.append(word.substring(i, j+1));
                break;
            }
            buffer.append(word.substring(i,k) + " ");
            i = k;
        }
        
        return buffer.toString();
    }

    
    private String get(char[] str,int low,int high){
        StringBuffer b = new StringBuffer();
        for(int i=low; i < high; i++){
            b.append(str[i]);
        }
        return b.toString();
    }
    
    public static void main(String args[]){
        Set<String> dictionary = new HashSet<String>();
        dictionary.add("I");
        dictionary.add("like");
        dictionary.add("had");
        dictionary.add("play");
        dictionary.add("to");
        String str = "Ihadliketoplay";
        BreakMultipleWordsWithNoSpaceIntoSpace bmw = new BreakMultipleWordsWithNoSpaceIntoSpace();
        String result = bmw.dynamic(str.toCharArray(), dictionary);
        String result1 = bmw.breakWordDP(str, dictionary);
        
        System.out.println(result);
        System.out.print(result1);
    }
}
