package com.interview.string;
/**
 * http://leetcode.com/2011/09/regular-expression-matching.html
 */
public class RegexMatching {

	public boolean match(char[] str, char[] pattern){
		return match(str,pattern,0,0);
	}
	
	private boolean match(char[] str,char pattern[],int pos1, int pos2){
		if(pos1 == str.length && pos2 == pattern.length){
			return true;
		}
		if(pos2 == pattern.length){
			return false;
		}
		if(pos1 == str.length){
			return pos2 + 1 < pattern.length && pattern[pos2+1] == '*' && 
					match(str,pattern,pos1, pos2+2);
		}
		
		if(pos2 + 1 >= pattern.length || pattern[pos2+1] != '*'){
			if(pattern[pos2] == '.'){
				return match(str,pattern,pos1+1,pos2+1);
			}else{
				return str[pos1] == pattern[pos2] && match(str,pattern,pos1+1,pos2+1);
			}
		}
		
		if(match(str,pattern,pos1,pos2+2)){
			return true;
		}
		for(int i=pos1+1; i <= str.length; i++){
			if(pattern[pos2] == '.'){
				boolean flag = match(str,pattern,i,pos2+2);
				if(flag){
					return true;
				}
			}else{
				if(str[i-1] != pattern[pos2]){
					break;
				}
				boolean flag = match(str,pattern,i,pos2+2);
				if(flag){
					return true;
				}
			}
		}
		return false;
	}
	
	public static void main(String args[]){
		RegexMatching rm = new RegexMatching();
		System.out.println(rm.match("Tushar".toCharArray(),"Tushar".toCharArray()));
		System.out.println(rm.match("Tusha".toCharArray(),"Tushar*a*b*".toCharArray()));
		System.out.println(rm.match("".toCharArray(),"a*b*".toCharArray()));
		System.out.println(rm.match("abbbbccc".toCharArray(),"a*ab*bbbbc*".toCharArray()));
		System.out.println(rm.match("abbbbccc".toCharArray(),"aa*bbb*bbbc*".toCharArray()));
		System.out.println(rm.match("abbbbccc".toCharArray(),".*bcc".toCharArray()));
		System.out.println(rm.match("abbbbccc".toCharArray(),".*bcc*".toCharArray()));
		System.out.println(rm.match("abbbbccc".toCharArray(),".*bcc*".toCharArray()));
	}
}
