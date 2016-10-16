#include<iostream>
using namespace std;

int BinarySearchFirst(int arr[],int l,int r,int key)
{
	if( l <= r)
	{
	int mid = l+(r-l)/2;

	if(arr[mid]==key && (arr[mid-1]<key || mid==l) )
		return mid;
	else if(key > arr[mid])
		return BinarySearchFirst(arr,mid+1,r,key);
	else
		return BinarySearchFirst(arr,l,mid-1,key);
	}
	else
		return -1;

}

int BinarySearchLast(int arr[],int l,int r,int key)
{
	if( l <= r)
	{
	int mid = l+(r-l)/2;

	if(arr[mid]==key && (key < arr[mid+1] || mid==r) )
		return mid;
	else if(key < arr[mid])
		return BinarySearchLast(arr,l,mid-1,key);
	else
		return BinarySearchLast(arr,mid+1,r,key);
	}
	else
		return -1;
}

int main()
{
	int arr[] = {0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1};
	int n = sizeof(arr)/sizeof(arr[0]);

	int l = BinarySearchFirst(arr,0,n-1,1);
	int r = BinarySearchLast(arr,0,n-1,1);

	cout<<"The no. of ones in the Array is : "<<r<<" - "<<l<<" + 1 = "<<r-l+1;

	cin.get();
	cin.get();
	return 0;
}