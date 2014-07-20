package com.interview.array;

public class BuySellStockProfit {

	public int oneProfit(int arr[]){
		int minPrice = arr[0];
		int maxProfit = 0;
		for(int i=1; i < arr.length; i++){
			if(arr[i] - minPrice > maxProfit){
				maxProfit = arr[i] - minPrice;
			}
			if(arr[i] < minPrice){
				minPrice = arr[i];
			}
		}
		return maxProfit;
	}
	
	public int allTimeProfit(int arr[]){
		int profit = 0;
		int localMin = arr[0];
		for(int i=1; i < arr.length;i++){
			if(arr[i-1] < arr[i]){
				continue;
			}
			
			profit += arr[i-1] - localMin;
			localMin = arr[i];
		}
		return profit;
	}
	
	public static void main(String args[]){
		int arr[] = {7,10,15,5,11,2,7,9,3};
		BuySellStockProfit bss = new BuySellStockProfit();
		System.out.println(bss.oneProfit(arr));
		
		System.out.print(bss.allTimeProfit(arr));
		
	}
}
