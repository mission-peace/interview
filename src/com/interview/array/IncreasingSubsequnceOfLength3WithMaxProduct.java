package com.interview.array;

public class IncreasingSubsequnceOfLength3WithMaxProduct {

    public int maxProduct(int arr[]){
        int RGN[] = new int[arr.length];
        int LGN[] = new int[arr.length];
        RGN[arr.length-1] = arr[arr.length-1];
        int max = arr[arr.length-1];
        for(int i=arr.length-2; i>=0; i--){
            if(max < arr[i]){
                max = arr[i];
            }
            if(max > arr[i]){
                RGN[i] = max;
            }
            else{
                RGN[i] = 0;
            }
        }
        LGN[0] = 0;
        for(int i=1; i < arr.length; i++){
            getLGN(arr,i,LGN);
        }
        int maxProduct = 0;
        for(int i=1; i < arr.length-1; i++){
            int product = arr[i]*LGN[i]*RGN[i];
            if(maxProduct < product){
                maxProduct = product;
            }
        }
        return maxProduct;
    }
    
    private void getLGN(int arr[],int pos,int LGN[]){
        int max = 0;
        int i =0;
        while(i < pos){
            if(arr[i] < arr[pos]){
                if(arr[i] > max){
                    max = arr[i];
                }
            }
            i++;
        }
        LGN[pos] = max;
    }
    
    public static void main(String args[]){
        int arr[] = {6, 7, 8, 1, 2, 3, 9, 10};
        IncreasingSubsequnceOfLength3WithMaxProduct iss = new IncreasingSubsequnceOfLength3WithMaxProduct();
        System.out.println(iss.maxProduct(arr));
        int arr1[] = {1, 5, 10, 8, 9};
        System.out.println(iss.maxProduct(arr1));
    }
}
