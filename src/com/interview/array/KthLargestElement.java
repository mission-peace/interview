package com.interview.array;

public class KthLargestElement {

	public int kthLargest(int arr1[],int arr2[],int low1,int high1,int low2,int high2,int k){
		int len1 = high1-low1 +1;
		int len2 = high2 - low2+1;
		
		if(len1 == 0){
			return arr2[low2+k];
		}
		if(len2 ==0){
			return arr1[low1+k];
		}
		if(k == 0){
			return arr1[low1] < arr2[low2] ? arr1[low1] : arr2[low2];
		}
		
		//TODO - understand how mid is calculated
		int mid1 = len1*k/(len1 + len2);
		int mid2 = k - mid1 - 1;
		
		mid1 = low1+mid1;
		mid2 = low2 + mid2;
		
		if(arr1[mid1] > arr2[mid2]){
			k = k - mid2 + low2 -1;
			high1 = mid1;
			low2 = mid2 + 1;
		}else{
			k = k - mid1 + low1 -1;
			high2 = mid2;
			low1 = mid1+1;
		}
		return kthLargest(arr1, arr2, low1, high1, low2, high2, k);
	}

	public static void main(String args[]){
		int arr1[] = {1,3,6,9,15};
		int arr2[] = {4,5,18};
		
		KthLargestElement kle = new KthLargestElement();
		System.out.print(kle.kthLargest(arr1, arr2, 0, arr1.length-1, 0, arr2.length-1, 5));
	}
}
