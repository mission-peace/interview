package com.interview.dynamic;

/**
 http://www.geeksforgeeks.org/dynamic-programming-set-10-0-1-knapsack-problem/
 */
public class Knapsack01 {

    public int calculate(int val[], int wt[], int W){
        int K[][] = new int[val.length+1][W+1];
        
        for(int i=0; i <= val.length; i++){
            for(int j=0; j <= W; j++){
                if(i == 0 || j == 0){
                    K[i][j] = 0;
                    continue;
                }
                if(j - wt[i-1] >= 0){
                    K[i][j] = Math.max(K[i-1][j], K[i-1][j-wt[i-1]] + val[i-1]);
                }else{
                    K[i][j] = K[i-1][j];
                }
            }
        }
        return K[val.length][W];
    }
    
    public static void main(String args[]){
        Knapsack01 k = new Knapsack01();
        int val[] = {60,20,15,30};
        int wt[] = {4,2,3,5};
        int r = k.calculate(val, wt, 8);
        System.out.print(r);
    }
}
