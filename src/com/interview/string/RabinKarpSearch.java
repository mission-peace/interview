package com.interview.string;

/**
 * http://www.geeksforgeeks.org/searching-for-patterns-set-3-rabin-karp-algorithm/
 */
public class RabinKarpSearch {

    private int prime = 11;
    
    public boolean subString(char[] mainString, char[] subString){
        int subStringHash = createHash(subString,0, subString.length-1);
        int mainStringHash = createHash(mainString,0,subString.length-1);
        if(subStringHash == mainStringHash){
            if(checkEqual(mainString,0,subString.length-1,subString,0,subString.length-1)){
                return true;
            }
        }
        for(int i=subString.length; i < mainString.length; i++){
            mainStringHash = recalculateHash(mainString, i - subString.length, i, subString.length, mainStringHash);
            if(subStringHash == mainStringHash){
                if(checkEqual(mainString,i - subString.length+1,i,subString,0,subString.length-1)){
                    return true;
                }
            }
        }
        return false;
    }
    
    private int recalculateHash(char[] str,int oldIndex, int newIndex,int size,int hash){
        hash = hash/prime;
        hash -= str[oldIndex];
        hash += str[newIndex]*Math.pow(prime, size);
        return hash;
    }
    
    private int createHash(char[] str,int start, int end){
        int hash = 0;
        int pow= 1;
        for(int i=start; i <= end; i++){
            hash += str[i]*Math.pow(prime,pow);
            pow++;
        }
        return hash;
    }
    
    private boolean checkEqual(char str1[],int start1,int end1, char str2[],int start2,int end2){
        int i = start1;
        int j = start2;
        while(i <= end1 && j <= end2){
            if(str1[i] != str2[j]){
                return false;
            }
            i++;
            j++;
        }
        if(i != end1 +1 || j != end2 + 1){
            return false;
        }
        return true;
    }
    
    public static void main(String args[]){
        RabinKarpSearch rks = new RabinKarpSearch();
        System.out.println(rks.subString("Tushar".toCharArray(), "shas".toCharArray()));
    }
}
