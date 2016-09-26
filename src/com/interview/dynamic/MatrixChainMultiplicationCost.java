package com.interview.dynamic;

/**
 * Created by Abhinav on 27-09-2016.
 * This is more inline with https://www.youtube.com/watch?v=vgLJZMUfnsU
 */
public class MatrixChainMultiplicationCost {


    int row, col;

    MatrixChainMultiplicationCost(int r, int c) {
        row = r;
        col = c;
    }

    public static int findCost(MatrixChainMultiplicationCost arr[]){
        int cost[][] = new int[arr.length][arr.length];

        for(int L=1; L <= arr.length; L++){
            int numElemsToPair = L - 1;
            int numTimesElementsHaveToBePaired = arr.length - L;
        	/* For every position i, we check every chain of len L */
            for(int i=0; i <= numTimesElementsHaveToBePaired; i++){
                int j = i + numElemsToPair;
                if (i == j) { /* numElemsToPair =0 essentially */
                    cost[i][j] = 0;
                    continue;
                }
                cost[i][j] = Integer.MAX_VALUE;
                /* For matrix i to j, check every split K */
                for(int k=i; k < j; k++){
                    int q = cost[i][k] + cost[k+1][j] + arr[i].row * arr[k].col * arr[j].col;
                    if(q < cost[i][j]){
                        cost[i][j] = q;
                    }
                }
            }
        }
        return cost[0][arr.length-1];
    }

    public static void main(String args[]) throws Exception {
        MatrixChainMultiplicationCost arr[] = new MatrixChainMultiplicationCost[4];
        arr[0] = new MatrixChainMultiplicationCost(4,2);
        arr[1] = new MatrixChainMultiplicationCost(2,3);
        arr[2] = new MatrixChainMultiplicationCost(3,5);
        arr[3] = new MatrixChainMultiplicationCost(5,3);
        int cost = MatrixChainMultiplicationCost.findCost(arr);
        assert cost == 84;

        arr[0] = new MatrixChainMultiplicationCost(2,3);
        arr[1] = new MatrixChainMultiplicationCost(3,6);
        arr[2] = new MatrixChainMultiplicationCost(6,4);
        arr[3] = new MatrixChainMultiplicationCost(4,5);
        cost = MatrixChainMultiplicationCost.findCost(arr);
        assert cost == 124;
    }
}
