#include<iostream>
using namespace std;

int firstOccur(int arr[],int l,int r,int key)
{
	if(l<=r)
	{
		int mid = l+ ((r-l)/2);

		if(key == arr[mid] && (arr[mid-1]<key || mid==0)) 
			return mid;
		else if(key <= arr[mid])
			firstOccur(arr,l,mid-1,key);
		else if(key > arr[mid])
			firstOccur(arr,mid+1,r,key);

	}
	else
		return -1;
}

void printArray(int arr[],int n)
{
	for(int i=0 ; i<=n-1 ; i++)
		cout<<arr[i]<<" -> "<<i<<"\n";
}

int main()
{
	int arr[] = {1,2,2,2,3,3,3,3,3,3,5,5,6,6,6,6,7,7,7,8,8,8,9,9,9};
	int n = sizeof(arr)/sizeof(arr[0]);

	printArray(arr,n);

	for(int i=1 ; i<=9 ; i++,cout<<endl)
	cout<<"key = "<<i<<"  "<<firstOccur(arr,0,n-1,i);

	cin.get();
	return 0;
}