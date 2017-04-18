package com.interview.dynamic;

/**
 * Date 07/31/2014
 * @author tusroy
 * 
 * Write a program to find maximum sum rectangle in give 2D matrix.
 * Assume there is at least one positive number in the 2D matrix.
 * 
 * Solution:
 * Keep temp array with size as number of rows. Start left and right from 0
 * and keep adding values for each row and maintain them in this temp array.
 * Run Kadane's algorithm to find max sum subarray in temp. Now increment right by
 * 1. When right reaches last column reset right to 1 and left to 1.
 * 
 * Space complexity of this algorithm is O(row), array[row] used for Kadane's algorithm
 * Time complexity of this algorithm is O(row*col*col)
 * 
 * References
 * http://www.geeksforgeeks.org/dynamic-programming-set-27-max-sum-rectangle-in-a-2d-matrix/
 */
public class SubRectangularMatrixWithMaximumSum {

    class Result{
        int maxSum;
        int leftBound;
        int rightBound;
        int upBound;
        int lowBound;
        @Override
        public String toString() {
            return "Result [maxSum=" + maxSum + ", leftBound=" + leftBound
                    + ", rightBound=" + rightBound + ", upBound=" + upBound
                    + ", lowBound=" + lowBound + "]";
        }
        
    }
    // Time complexity of this algorithm is O(row*col*col)
    // since there is 2xcolumn_loop and 1xrow_loop
    // leftBound column loop * rightBound column loop (inside leftBound column loop)
    // * kadane row calculations (inside rightBound column loop)
    public Result maxSum(int input[][]){
        int rows = input.length;
        int cols = input[0].length;
        int temp[] = new int[rows]; // holds row sum of input[row][leftBound to rightBound]
        Result result = new Result(); // result stays outside loop so it doesn't reset
        for(int left = 0; left < cols ; left++){ // increment leftBound
            for(int i=0; i < rows; i++){
                temp[i] = 0; // reset 1d array everytime leftBound increments
            }
            // reset rightBound everytime leftBound increments so rightBound==leftBound
            for(int right = left; right < cols; right++){ 
                for(int i=0; i < rows; i++){
                    temp[i] += input[i][right]; //add input[column] to temp[]
                }
                KadaneResult kadaneResult = kadane(temp); //calculate maxSum
                if(kadaneResult.maxSum > result.maxSum){ // update result condition
                    result.maxSum = kadaneResult.maxSum;
                    result.leftBound = left; // current left
                    result.rightBound = right; // current right
                    result.upBound = kadaneResult.start; // maxSum left
                    result.lowBound = kadaneResult.end; // maxSum right
                }
            } // rightBound has reached end of matrix, 
              // increment leftBound && reset rightBound to leftBound
        } // leftBound has reached end of column, algorithm complete
        return result;
    }
    
    class KadaneResult{
        int maxSum;
        int start;
        int end;
        public KadaneResult(int maxSum, int start, int end) {
            this.maxSum = maxSum;
            this.start = start;
            this.end = end;
        }
    }
    
    // find maxSum in 1D array
    // return {maxSum, left, right}
    private KadaneResult kadane(int arr[]){
        int max = 0;
        int maxStart = -1;
        int maxEnd = -1;
        int currentStart = 0;
        int maxSoFar = 0;
        for(int i=0; i < arr.length; i++){
            maxSoFar += arr[i]; // keep adding array values
            if(maxSoFar < 0){ //if maxSoFar < 0, reset to 0
                maxSoFar = 0;
                currentStart = i+1;
            }
            if(max < maxSoFar){
                maxStart = currentStart;
                maxEnd = i;
                max = maxSoFar; //update max
            }
        }
        return new KadaneResult(max, maxStart, maxEnd);
    }
    
    
    public static void main(String args[]){
        int input[][] = {{ 2,  1, -3, -4,  5},
                         { 0,  6,  3,  4,  1},
                         { 2, -2, -1,  4, -5},
                         {-3,  3,  1,  0,  3}};
        SubRectangularMatrixWithMaximumSum saw = new SubRectangularMatrixWithMaximumSum();
        System.out.println(saw.maxSum(input));
    }       
}
