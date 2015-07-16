package com.interview.recursion;

/**
 * http://www.careercup.com/question?id=4793416529477632
 */
public class OneEditApart {

    public boolean matchRecurisve(char[] str1, char[] str2){
        return match(str1,str2,0,0,true);
    }
    
    private boolean match(char[] str1, char[] str2, int pos1,int pos2, boolean areSame){
        if(pos1 == str1.length && pos2 == str2.length){
            return true;
        }
        if(areSame){
            if((pos1 == str1.length && pos2 == str2.length-1) || 
                    (pos1 == str1.length -1 && pos2 == str2.length)){
                return true;
            }
        }
        if(pos1 == str1.length || pos2 == str2.length){
            return false;
        }
        if(areSame){
            return match(str1,str2,pos1+1,pos2+1, str1[pos1] == str2[pos2]) || 
                    match(str1,str2,pos1,pos2+1,false) || match(str1,str2,pos1+1,pos2,false);
        }else{
            return str1[pos1] == str2[pos2] && match(str1,str2,pos1+1,pos2+1,areSame);
        }
    }
    
    public boolean matchIterative(char str1[], char str2[]){
        if(str1.length < str2.length){
            char temp[] = str1;
            str1 = str2;
            str2 = temp;
        }
        
        if(str1.length - str2.length > 1){
            return false;
        }
        int k = 1;
        if(str1.length == str2.length){
            int i =0;
            int j =0;
            while(k >= 0 && i < str1.length){
                if(str1[i] != str2[j]){
                    k--;
                }
                i++;
                j++;
            }
            if(k < 0){
                return false;
            }
        }else{
            int i=0;
            int j =0;
            while(k >= 0 && i < str1.length && j < str2.length){
                if(str1[i] != str2[j]){
                    i++;
                    k--;
                    continue;
                }
                i++;
                j++;
            }
            if(k == -1){
                return false;
            }
        }
        return true;
    }
    
    
    public static void main(String args[]){
        OneEditApart oea = new OneEditApart();
        System.out.println(oea.matchRecurisve("cat".toCharArray(), "dog".toCharArray()));
        System.out.println(oea.matchRecurisve("cat".toCharArray(), "cats".toCharArray()));
        System.out.println(oea.matchRecurisve("cat".toCharArray(), "cut".toCharArray()));
        System.out.println(oea.matchRecurisve("cats".toCharArray(), "casts".toCharArray()));
        System.out.println(oea.matchRecurisve("catsts".toCharArray(), "casts".toCharArray()));
            
        System.out.println(oea.matchIterative("cat".toCharArray(), "dog".toCharArray()));
        System.out.println(oea.matchIterative("cat".toCharArray(), "cats".toCharArray()));
        System.out.println(oea.matchIterative("cat".toCharArray(), "cut".toCharArray()));
        System.out.println(oea.matchIterative("cats".toCharArray(), "casts".toCharArray()));
        System.out.println(oea.matchIterative("catsts".toCharArray(), "casts".toCharArray()));
    }
}
