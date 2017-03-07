package com.interview.dynamic;

/**
 * http://www.geeksforgeeks.org/count-possible-paths-top-left-bottom-right-nxm-matrix/
 */
public class NumberOfPathsInMxNMatrix {

    public int countPathsRecursive(int n, int m){
        // If either given row number is first or given column number is first
        if(n == 1 || m == 1){
            return 1;
        }
        // add number of paths from above and left
        return countPathsRecursive(n-1, m) + countPathsRecursive(n, m-1);
    }
    
    // Returns count of possible paths to reach cell at row number n 
    // and column number m from the topmost leftmost cell (cell at 1, 1)
    public int countPaths(int n,int m){
        
        // Create a 2D table to store results of subproblems
        int T[][] = new int[n][m];
        
        // Count of paths to reach any cell in first row or column is 1
        for(int i=0; i < n; i++){
            T[i][0] = 1;
        }
        for(int i=0; i < m; i++){
            T[0][i] = 1;
        }
        
        // Calculate count of paths for other cells in bottom-up manner using
        // the recursive solution
        for(int i=1; i < n; i++){
            for(int j=1; j < m; j++){
                // since the only moves possible is right or down,
                // possible paths is sum of paths from above or left
                T[i][j] = T[i-1][j] + T[i][j-1];
            }
        }
        return T[n-1][m-1];
    }
    
    public static void main(String args[]){
        NumberOfPathsInMxNMatrix nop = new NumberOfPathsInMxNMatrix();
        System.out.print(nop.countPathsRecursive(3,3));
    }
    
}
