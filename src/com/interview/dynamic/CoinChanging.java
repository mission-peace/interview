package com.interview.dynamic;

import java.util.ArrayList;
import java.util.List;

/**
 * Given a total and coins of certain denominations find number of ways total
 * can be formed from coins assuming infinity supply of coins
 *
 * References:
 * http://www.geeksforgeeks.org/dynamic-programming-set-7-coin-change/
 */
public class CoinChanging {

    public int numberOfSolutions(int total, int coins[]){
        // temporary array table will be storing the number of solutions
        // to avoid recomputations of same subproblem. 
        // We need n+1 col as the table is constructed in 
        // bottom up manner using the base case (total = 0)
        // [coinValues][naturalNumbersToTotal]
        int temp[][] = new int[coins.length+1][total+1];
        for(int i=0; i <= coins.length; i++){
            temp[i][0] = 1; // Base case (If given total is 0)
        }
        for(int C=1; C <= coins.length; C++){ //C: coin row
            for(int T=1; T <= total ; T++){ //T: total col
                if(coins[C-1] > T){ //coinValue > total
                    temp[C][T] = temp[C-1][T];
                }
                else{
                    temp[C][T] = temp[C][T-coins[C-1]] //combination using current coin
                        + temp[C-1][T]; //combinations using only above coins
                }
            }
        }
        return temp[coins.length][total];
    }

    /**
     * Space efficient DP solution
     */
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

    /**
     * This method actually prints all the combination. It takes exponential time.
     */
    public void printCoinChangingSolution(int total,int coins[]){
        List<Integer> result = new ArrayList<>();
        printActualSolution(result, total, coins, 0);
    }
    
    private void printActualSolution(List<Integer> result,int total,int coins[],int pos){
        if(total == 0){ //print valid results
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
    // Driver Function to test above function
    public static void main(String args[]){
        CoinChanging cc = new CoinChanging();
        int total = 15;
        int coins[] = {3,4,6,7,9};
        System.out.println(cc.numberOfSolutions(total, coins));
        System.out.println(cc.numberOfSolutionsOnSpace(total, coins));
        cc.printCoinChangingSolution(total, coins);
    }
}
