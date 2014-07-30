package com.interview.multiarray;

public class GameOfLife {

	boolean [][]board = null;
	boolean [][]tempBoard = null;
	public GameOfLife(boolean[][] initialState){
		board = initialState;
		tempBoard = new boolean[board.length][board.length];
	}
	
	public void printState(){
		for(int i=0; i < board.length; i++){
			for(int j=0; j < board[i].length; j++){
				if(board[i][j]){
					System.out.print("1 ");
				}else{
					System.out.print("0 ");
				}
			}
			System.out.print("\n");
		}
		System.out.print("\n\n");
	}
	
	public void next(){
		
		int count=0;
		for(int i=0; i < board.length; i++){
			for(int j=0; j < board[i].length; j++){
				count = countNeighbors(i, j);
				tempBoard[i][j] = board[i][j];
				if(count <= 1){
					tempBoard[i][j] = false;
				}
				if(count ==3){
					tempBoard[i][j] = true;
				}
				if(count >= 4){
					tempBoard[i][j] = false;
				}
			}
		}
		boolean[][] rBoard = tempBoard;
		tempBoard = board;
		board = rBoard;
	}

	public void nextOptimized(){
		
		boolean temp1[] = new boolean[board[0].length];
		boolean temp2[] = new boolean[board[0].length];
		calculate(board,temp1,0);
		for(int i=1; i < board.length; i++){
			calculate(board,temp2,i);
			copy(i-1,temp1);
			copy(temp1,temp2);
		}
		copy(board.length-1,temp1);
	}
	
	void copy(boolean arr1[],boolean arr2[]){
		for(int i=0; i <arr2.length; i++){
			arr1[i] = arr2[i];
		}
	}
	
	void calculate(boolean [][]board,boolean temp[],int i){
		int count=0;
		for(int j=0; j < board[i].length; j++){
			count = countNeighbors(i, j);
			temp[j] = board[i][j];
			if(count <= 1){
				temp[j] = false;
			}
			if(count ==3){
				temp[j] = true;
			}
			if(count >= 4){
				temp[j] = false;
			}
		}

	}
	
	private void copy(int i,boolean []temp){
		for(int x=0; x < temp.length; x++){
			board[i][x] = temp[x];
		}
	}

	private int countNeighbors(int i,int j){
		int count =0;
		for(int k = i-1; k <= i+1; k++){
			for(int l = j-1; l <= j+1; l++){
				if((i ==k && j == l) || k < 0 || l < 0 || k >= board.length || l >= board[k].length){
					continue;
				}
				if(board[k][l]){
					count++;
				}
			}
		}
		return count;
	}
	
	public static void main(String args[]){
		boolean[][] initialState = new boolean[10][10];
		initialState[3][6] = true;
		initialState[4][6] = true;
		initialState[5][6] = true;
		initialState[5][7] = true;
		initialState[5][8] = true;
		GameOfLife gol = new GameOfLife(initialState);
		gol.printState();
		gol.nextOptimized();
		gol.printState();
		gol.nextOptimized();
		gol.printState();
		gol.nextOptimized();
		gol.printState();
		gol.nextOptimized();
		gol.printState();
		
	}
}
