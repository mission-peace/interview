package com.interview.sort;

/**
 * http://www.geeksforgeeks.org/pancake-sorting/
 */
public class PanCakeSorting {

	public void sort(int arr[]){
		for(int i=arr.length-1; i >= 0 ; i--){
			int pos = findMax(arr,i);
			flip(arr,pos);
			flip(arr,i);
		}
	}
	
	private int findMax(int arr[],int pos){
		int max = pos;
		for(int i= pos-1 ;i >= 0 ;i--){
			if(arr[i] > arr[max]){
				max = i;
			}
		}
		return max;
	}
	
	private void flip(int arr[],int pos){
		for(int i=0; i <= pos/2; i++){
			swap(arr,i,pos-i);
		}
	}
	
	private void swap(int arr[],int i,int j){
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	
	public static void main(String args[]){
		int arr[] = {9,2,7,11,3,6,1,10,8};
		PanCakeSorting pcs = new PanCakeSorting();
		pcs.sort(arr);
		for(int i=0; i < arr.length; i++){
			System.out.print(arr[i] + " ");
		}
	}
}
