package com.interview.graph;

/**
 * http://www.careercup.com/question?id=5727310284062720
 */
public class FillOsWIthXsIfSurroundedByXs {

    public void fill(char board[][]){
        for(int i = 0; i < board.length; i++){
            if(board[i][0] == 'O'){
                markNotFill(board,i,0);
            }
        }
        for(int i = 0; i < board.length; i++){
            if(board[i][board.length-1] == 'O'){
                markNotFill(board,i,board.length-1);
            }
        }
        for(int i = 0; i < board[0].length; i++){
            if(board[0][i] == 'O'){
                markNotFill(board,0,i);
            }
        }
        for(int i = 0; i < board[0].length; i++){
            if(board[board.length-1][i] == 'O'){
                markNotFill(board,board.length-1,i);
            }
        }
        
        for(int i=0; i < board.length; i++){
            for(int j=0; j < board[0].length; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '-'){
                    board[i][j] = 'O';
                }
            }
        }
    }
    
    private void markNotFill(char board[][],int i,int j){
        
        if(i < 0 || i >= board.length || j < 0 || j > board[i].length){
            return;
        }
        if(board[i][j] == 'X' || board[i][j] == '-'){
            return;
        }
        board[i][j] = '-';
        for(int k = i-1; k <= i+1; k++){
            for(int l=j-1; l <= j+1; l++){
                if(k == i && j == l){
                    continue;
                }
                markNotFill(board,k,l);
            }
        }
    }
    
    void printArray(char[][] board){
        for(int i=0; i < board.length; i++){
            for(int j=0; j < board[i].length ; j++){
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
    }
    
    public static void main(String args[]){
        FillOsWIthXsIfSurroundedByXs fo = new FillOsWIthXsIfSurroundedByXs();
        char board[][] = {{'X','X','X','X'},
                          {'X','X','O','X'},
                          {'X','O','X','X'},
                          {'X','X','O','X'}};
        
        fo.fill(board);
        fo.printArray(board);
    }
}
