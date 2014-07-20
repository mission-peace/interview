package com.interview.dynamic;

/**
 * http://www.geeksforgeeks.org/dynamic-programming-set-6-min-cost-path/
 */
public class MinCostPath {

	public int minCost(int [][]cost,int m,int n){
		
		int temp[][] = new int[m+1][n+1];
		for(int i=1; i <= n; i++){
			temp[0][i] = cost[0][i-1] + cost[0][i];
		}
		
		for(int i=1; i <= m; i++){
			temp[i][0] = cost[i-1][0] + cost[i][0];
		}
		
		for(int i=1; i <= m; i++){
			for(int j=1; j <= n; j++){
				temp[i][j] = cost[i][j] + min(temp[i-1][j-1], temp[i-1][j],temp[i][j-1]);
			}
		}
		return temp[m][n];
	}
	
	private int min(int a,int b, int c){
		int l = Math.min(a, b);
		return Math.min(l, c);
	}
	
	public static void main(String args[]){
		MinCostPath mcp = new MinCostPath();
		int cost[][] = {{1,2,3},{4,8,2},{1,5,3}};
		int result = mcp.minCost(cost, 2, 2);
		System.out.print(result);
	}

}
