package com.interview.dynamic;

import java.util.ArrayList;
import java.util.List;

/**
 http://www.geeksforgeeks.org/dynamic-programming-set-7-coin-change/
 */
public class CoinChanging {

    public int numberOfSolutions(int total, int arr[]){
        
        int temp[][] = new int[arr.length+1][total+1];
        
        for(int i=0; i <= arr.length; i++){
            temp[i][0] = 1;
        }
        
        for(int i=1; i <= arr.length; i++){
            for(int j=1; j <= total ; j++){
                if(arr[i-1] > j){
                    temp[i][j] = temp[i-1][j];
                }
                else{
                    temp[i][j] = temp[i][j-arr[i-1]] + temp[i-1][j];
                }
            }
        }
        return temp[arr.length][total];
    }
    
    public void printCoinChangingSolution(int total,int coins[]){
        List<Integer> result = new ArrayList<Integer>();
        printActualSolution(result, total, coins, 0);
    }
    
    private void printActualSolution(List<Integer> result,int total,int coins[],int pos){
        if(total == 0){
            for(int r : result){
                System.out.print(r + " ");
            }
            System.out.print("\n");
        }
        for(int i=pos; i < coins.length; i++){
            if(total >= coins[i]){
                result.add(coins[i]);
                printActualSolution(result,total-coins[i],coins,i);
                result.remove(result.size()-1);
            }
        }
    }

    public int numberOfSolutionsOnSpace(int total, int arr[]){
        
        int temp[] = new int[total+1];
        
        temp[0] = 1;
        for(int i=0; i < arr.length; i++){
            for(int j=1; j <= total ; j++){
                if(j >= arr[i]){
                    temp[j] += temp[j-arr[i]];
                }
            }
        }
        return temp[total];
    }
    
    
    public int minCoinChangeInfinteSupply(int total, int arr[]){
        int temp[] = new int[total+1];
        temp[0] = 0;
        for(int i=1; i <= total; i++){
            temp[i] = Integer.MAX_VALUE;
        }
        for(int i=0; i < arr.length; i++){
            for(int j=1; j <= total; j++){
                if(j >= arr[i]){
                    temp[j] = Math.min(temp[j], temp[j-arr[i]] +1);
                }
            }
        }
        return temp[total];
    }

    
    public static void main(String args[]){
        CoinChanging cc = new CoinChanging();
        int total =10;
        int coins[] = {6,1,3,4};
        cc.printCoinChangingSolution(total, coins);
    }
}
