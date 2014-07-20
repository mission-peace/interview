package com.interview.tree;


/**
 * http://www.geeksforgeeks.org/check-for-identical-bsts-without-building-the-trees/
 */
public class IsSameBSTWithoutCreatingTree {

	public boolean isSameBST(int arr1[],int arr2[],int pos,int min, int max){
		if(pos >= arr1.length){
			return true;
		}
		int pos1 = -1;
		for(int i=0; i < arr2.length; i++){
			if(arr2[i] == arr1[pos]){
				pos1 = i;
				break;
			}
		}
		int firstSmaller1 = -10000;
		int firstLarger1 = -10000;
		
		int firstSmaller2 = -10000;
		int firstLarger2 = -10000;
		for(int i = pos1+1; i < arr2.length ; i++){
			if(firstLarger2 == -10000 && max > arr2[i] && arr2[pos1] < arr2[i]){
				firstLarger2 = arr2[i];
			}
			if(firstSmaller2 == -10000 && min < arr2[i] && arr2[i] < arr2[pos1]){
				firstSmaller2 = arr2[i];
			}
		}
		int lowPos = -1;
		int highPos = -1;
		for(int i = pos+1; i < arr1.length ; i++){
			if(firstLarger1 == -10000 && max > arr1[i] && arr1[pos] < arr1[i]){
				highPos = highPos != -1 ? highPos : i;
				firstLarger1 = arr1[i];
			}
			if(firstSmaller1 == -10000 && min < arr1[i] && arr1[pos] > arr1[i]){
				lowPos = lowPos != -1 ? lowPos : i;
				firstSmaller1 = arr1[i]; 
			}
		}
		boolean r = (firstSmaller1 == firstSmaller2 && firstLarger1 == firstLarger2);
		if(!r){
			return false;
		}
		boolean b1 = true, b2 = true;
		if(lowPos != -1){
			b1 = isSameBST(arr1, arr2, lowPos, min, arr1[pos]);
		}
		if(highPos != -1){
			b2 = isSameBST(arr1, arr2, highPos, arr1[pos], max);
		}
		return b1 && b2;
	}
	
	public static void main(String args[]){
		int arr1[] = {10,5,2,13,-1,12,15,17,11};
		int arr2[] = {10,13,12,5,11,15,2,17,-1};
		
		IsSameBSTWithoutCreatingTree ism = new IsSameBSTWithoutCreatingTree();
		System.out.println(ism.isSameBST(arr1, arr2, 0, -100000, 1000000));
	}
}
