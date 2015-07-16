package com.interview.string;

/**
 * http://www.geeksforgeeks.org/wildcard-character-matching/
 */
public class WildCardSearch {

    //Tushar Roy , Tus*oy ->returns true. So does wild card char search
    public boolean searchStar(char mainStr[], char pattern[]){
        for(int i= 0; i < mainStr.length ; i++){
            boolean r = searchStar(mainStr, pattern, i, 0);
            if(r){
                return true;
            }
        }
        return false;
    }
    
    private boolean searchStar(char mainStr[], char pattern[], int pos1, int pos2){
        if(pos2 == pattern.length){
            return true;
        }
        if(pos1 == mainStr.length){
            return false;
        }
        if(pattern[pos2] == '*'){
            boolean result = searchStar(mainStr,pattern,pos1,pos2+1) || searchStar(mainStr,pattern,pos1+1,pos2);
            if(result){
                return true;
            }
        }
        if(pattern[pos2] == '?'){
            return searchStar(mainStr,pattern,pos1+1,pos2+1);
        }
        else if(mainStr[pos1] == pattern[pos2]){
            return searchStar(mainStr,pattern,pos1+1, pos2+1);
        }
        return false;
    }
    
    public static void main(String args[]){
        String str = "Tusssshar Roy";
        String pattern = "us*s";
        WildCardSearch psw = new WildCardSearch();
        System.out.println(psw.searchStar(str.toCharArray(), pattern.toCharArray()));
    }
}
