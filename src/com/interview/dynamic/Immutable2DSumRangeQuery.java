package com.interview.dynamic;

/**
 * Date 03/11/2016
 * @author Tushar Roy
 *
 * Given a 2D array find the sum in given range defining a rectangle.
 *
 * Time complexity construction O(n*m)
 * Time complexity of query O(1)
 * Space complexity is O(n*m)
 * 
 * Reference
 * https://leetcode.com/problems/range-sum-query-2d-immutable/
 */
public class Immutable2DSumRangeQuery {
    private int[][] T;

    public Immutable2DSumRangeQuery(int[][] matrix) {
        int row = 0;
        int col = 0;
        if (matrix.length != 0) {
            row = matrix.length;
            col = matrix[0].length;
        }
        // additional 0th row && col initialized to all 0
        // to prevent out of range error
        T = new int[row + 1][col + 1];
        for (int r = 1; r < T.length; r++) {
            for (int c = 1; c < T[0].length; c++) {
                // matrix cell == sumOfRecW/1LessRow + sumOfRecW/1LessCol
                //                    - overlappingRectAdded2x + currentCell
                T[r][c] = T[r - 1][c] + T[r][c - 1] 
                        - T[r - 1][c - 1] + matrix[r - 1][c - 1] ;
            }
        }
   }

    public int sumQuery(int row1, int col1, int row2, int col2) {
        row1++;
        col1++;
        row2++;
        col2++;
        // bottomRightArea - areaAboveTopRightCorner
        //   - areaLeftOfBottomLeftCorner + topLeftAreaOverlappingButSubtacted2x
        return T[row2][col2] - T[row1 - 1][col2] 
                - T[row2][col1 - 1] + T[row1 - 1][col1 - 1];
    }

    public static void main(String args[]) {
        int[][] input = {{3, 0, 1, 4, 2},
                        {5, 6, 3, 2, 1},
                        {1, 2, 0, 1, 5},
                        {4, 1, 0, 1, 7},
                        {1, 0, 3, 0, 5}};

        int[][] input1 = {{2,0,-3,4}, {6, 3, 2, -1}, {5, 4, 7, 3}, {2, -6, 8, 1}};
        Immutable2DSumRangeQuery isr = new Immutable2DSumRangeQuery(input1);
        System.out.println(isr.sumQuery(1, 1, 2, 2));
    }
}
