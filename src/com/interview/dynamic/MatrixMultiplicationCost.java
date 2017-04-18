package com.interview.dynamic;

/**
 * http://www.geeksforgeeks.org/dynamic-programming-set-8-matrix-chain-multiplication/
 */
public class MatrixMultiplicationCost {

    public int findCost(int arr[]){
        int temp[][] = new int[arr.length][arr.length];
        int q = 0;
        //l is chain length
        for(int L=2; L < arr.length; L++){
            for(int i=0; i < arr.length - L; i++){
                int j = i + L;
                temp[i][j] = Integer.MAX_VALUE;
                for(int k=i+1; k < j; k++){
                    // q = cost/scalar multiplications
                    q = temp[i][k] + temp[k][j] + arr[i]*arr[k]*arr[j];
                    if(q < temp[i][j]){ //keep best answer
                        temp[i][j] = q; //store cost
                    }
                }
            }
        }
        return temp[0][arr.length-1];
    }
    
    public static void main(String args[]){
        MatrixMultiplicationCost mmc = new MatrixMultiplicationCost();
        int arr[] = {4,2,3,5,3};
        int cost = mmc.findCost(arr);
        System.out.print(cost);
    }
}
