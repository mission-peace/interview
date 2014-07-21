package com.interview.string;

/**
.Given an input string S write a function which returns true if it satisfies S = nT. Basically you have to find if a given string can be represented from a substring by iterating it ÒnÓ times. n >= 2
An example would suffice Ğ
Function should return true if
1) S = ÒababÓ
2) S = ÒabcdabcdÓ
3) S = ÒabcabcabcÓ
4) S = ÒzzxzzxzzxÓ

Function should return false if
1) S = ÒabacÓ
2) S = ÒabcdabbdÓ
3) S = ÒabcabcefgÓ
4) S = ÒzzxzzyzzxÓ
 */
public class NTMatch {

	public boolean match(char str[]){
		int kmp[] = buildKMP(str);
		int index = kmp[str.length-1];
		int end = str.length - index-1;
		if(end >= str.length/2){
			return false;
		}
		int j = end+1;
		int i = 0;
		while(j < str.length){
			if(str[i] != str[j]){
				return false;
			}
			i = (i+1)%(end+1);
			j++;
		}
		
		if(i == 0){
			return true;
		}
		return false;
	}
	
	private int[] buildKMP(char str[]){

		int result[] = new int[str.length];
		
		int i =1;
		result[0] = 0;
		int len =0;
		while(i < str.length){
			if(str[i] == str[len]){
				len++;
				result[i] = len;
				i++;
			}else{
				if(len != 0){
					len = result[len-1];
				}else{
					len =0;
					result[i] = 0;
					i++;
				}
			}
		}
		return result;
	}
	
	public static void main(String args[]){
		NTMatch ntMatch = new NTMatch();
		System.out.println(ntMatch.match("bababababa".toCharArray()));
	}
}
