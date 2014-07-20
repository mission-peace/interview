package com.interview.dynamic;

/**
 * 150 qs 18.11 
 * Find maximum subsquare such that all four borders are filled with black pixels
 */
public class SubsquareSurrounedByXs {

	class Cell{
		int ver;
		int hori;
	}
	public int findSubSquare(char input[][]){
		Cell T[][] = new Cell[input.length+1][input.length+1];
		for(int i=0; i < T.length; i++){
			for(int j=0; j < T[0].length; j++){
				T[i][j] = new Cell();
 			}
		}
	
		for(int i=1; i <= input.length; i++){
			for(int j=1; j <= input.length; j++){
				if(input[i-1][j-1] == 'X'){
					T[i][j].hori = T[i][j-1].hori +1;
					T[i][j].ver = T[i-1][j].ver + 1;
				}
			}
		}
		for(int i=0; i < T.length; i++){
			for(int j=0; j < T[0].length; j++){
				System.out.print(T[i][j].hori + "," + T[i][j].ver + "  ");
 			}
			System.out.println();
		}
		
		int max = 1;
		for(int i=T.length -1; i >=1 ; i--){
			for(int j= T[0].length-1 ; j >=1; j--){
				if(T[i][j].ver == 0 || T[i][j].ver == 1 || T[i][j].hori ==1 ){
					continue;
				}
				if(T[i][j].ver < T[i][j].hori){
					//check left bottom corner
					int leftBottom = T[i][j - T[i][j].ver + 1].ver;
					if(leftBottom < T[i][j].ver){
						continue;
					}
					
					//check right top corner
					int rightTop = T[i - T[i][j].ver + 1][j].hori;
					if(rightTop < T[i][j].ver){
						continue;
					}
					if(max < T[i][j].ver){
						max = T[i][j].ver;
					}
				}else{
					//check left bottom corner
					int leftBottom = T[i][j - T[i][j].hori + 1].ver;
					if(leftBottom < T[i][j].hori){
						continue;
					}
					
					//check right top corner
					int rightTop = T[i - T[i][j].hori + 1][j].hori;
					if(rightTop < T[i][j].hori){
						continue;
					}
					if(max < T[i][j].hori){
						max = T[i][j].hori;
					}
				}
			}
		}
		
		return max;
	}
	
	public static void main(String args[]){
		char[][] input = {{'X','O','O','O','O','O'},
						  {'O','O','O','O','O','O'},
						  {'X','X','X','X','O','O'},
						  {'X','X','X','X','X','O'},
						  {'X','O','O','X','X','O'},
						  {'X','O','X','X','X','O'}};
		SubsquareSurrounedByXs ss = new SubsquareSurrounedByXs();
		System.out.println(ss.findSubSquare(input));
	}
	
}
