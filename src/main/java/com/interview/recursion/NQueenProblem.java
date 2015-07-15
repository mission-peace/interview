package com.interview.recursion;

/**
 * http://www.geeksforgeeks.org/category/c-programs/page/7/
 * diag is of lenght 2n-1. It starts from 00 - 01 10 - 02 11 20 - 12 21 - 22
 * diag1 is also of length 2n-1. It starts from 02 - 01 12 - 00 11 22 - 10 21 - 20 . The trick is to convert column into n-1 -j so treat 
 * columns from right to left instead of left to right as we do in normal case.
 */
public class NQueenProblem {

    public boolean[][] place(int n) {
        boolean[][] board = new boolean[n][n];
        boolean colUsed[] = new boolean[n];
        boolean diagUsed[] = new boolean[2 * n - 1];
        boolean diag1Used[] = new boolean[2 * n - 1];
        boolean r = place(board, n, 0, colUsed, diagUsed, diag1Used);
        if(!r){
            return null;
        }
        return board;
    }

    private boolean place(boolean board[][], int n, int rowStart,
            boolean colUsed[], boolean diagUsed[], boolean diag1Used[]) {
        if(rowStart == n){
            return true;
        }
        for (int j = 0; j < board.length; j++) {
            if (colUsed[j] == false && diagUsed[rowStart + j] == false && diag1Used[rowStart + (n - 1 - j)] == false) {
                board[rowStart][j] = true;
                colUsed[j] = true;
                diagUsed[rowStart + j] = true;
                diag1Used[rowStart + (n - 1 - j)] = true;
                boolean r = place(board, n, rowStart + 1, colUsed, diagUsed,diag1Used);
                if (r) {
                    return true;
                }
                board[rowStart][j] = false;
                colUsed[j] = false;
                diagUsed[rowStart + j] = false;
                diag1Used[rowStart + (n - 1 - j)] = false;
            }
        }
        return false;
    }

    public static void main(String args[]) {
        NQueenProblem nqp = new NQueenProblem();
        boolean board[][] = nqp.place(6);
        if(board == null){
            System.out.println("No result possible");
        }else{
            for (int i = 0; i < board.length; i++) {
                for (int j = 0; j < board.length; j++) {
                    System.out.print(board[i][j] + " ");
                }
                System.out.println();
            }
        }
    }
}
