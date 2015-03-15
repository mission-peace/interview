package com.interview.multiarray;

/**
 * Date 03/15/2015 
 * @author tusroy
 * 
 * Given a 2D matrix(square or rectangular) print it in spiral way.
 * e.g 1 2 3
 *     4 5 6
 *     7 8 9 
 * Printing should be 1 2 3 6 9 8 7 4 5    
 *    
 * Solution:
 * Keep 4 pointers which are bounds for this matrix, up, down, left, right. Print each
 * row or column and keep incrementing and decrementing the bounds. As soon as up meets down
 * or left meets right we are done.
 * 
 * Test cases
 * Null matrix
 * Empty matrix
 * square matrix
 * rectangular matrix
 *
 * Reference
 * http://stackoverflow.com/questions/726756/print-two-dimensional-array-in-spiral-order
 * http://www.geeksforgeeks.org/print-a-given-matrix-in-spiral-form/
 */
public class SpiralPrinting {

    public void print(int matrix[][]) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return;
        }

        int left = 0;
        int right = matrix[0].length - 1;
        int up = 0;
        int down = matrix.length - 1;

        while (left < right && up < down) {
            for (int i = left; i <= right; i++) {
                System.out.print(matrix[up][i] + " ");
            }
            up++;

            for (int i = up; i <= down; i++) {
                System.out.print(matrix[i][right] + " ");
            }
            right--;

            for (int i = right; i >= left; i--) {
                System.out.print(matrix[down][i] + " ");
            }
            down--;

            for (int i = down; i >= up; i--) {
                System.out.print(matrix[i][left] + " ");
            }
            left++;
        }
    }
    
    public static void main(String args[]){
        SpiralPrinting sp = new SpiralPrinting();
        int matrix[][] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20}};
        sp.print(matrix);
    }
}
