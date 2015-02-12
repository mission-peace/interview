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
            if(arr[i-1] >= arr[i]){
                localMin = arr[i];
            }else{
                profit += arr[i] - localMin;
                localMin = arr[i];
            }
            
        }
        return profit;
    }
    
    public int allTimeProfit1(int arr[]){
        int profit = 0;
        int i =0;
        while(i < arr.length){
            while(i+1 < arr.length && arr[i] >= arr[i+1]){
                i++;
            }
            while(i+1 < arr.length && arr[i] < arr[i+1]){
                profit += arr[i+1] - arr[i];
                i++;
            }
            i++;
        }
        return profit;
    }
    public static void main(String args[]){
        int arr[] = {7,10,15,5,11,2,7,9,3};
        int arr1[] = {6,4,1,3,5,7,3,1,3,4,7,9,2,5,6,0,1,2};
        BuySellStockProfit bss = new BuySellStockProfit();
        System.out.println(bss.oneProfit(arr));
        System.out.print(bss.allTimeProfit(arr1));
        
    }
}
