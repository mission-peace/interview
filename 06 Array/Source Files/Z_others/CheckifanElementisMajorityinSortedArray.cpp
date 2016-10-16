#include<iostream>
using namespace std;

int binarysearch(int arr[],int l,int r,int key)
{
	if(r>=l)
	{
		int m = (l+r)/2;

		if((m==0 || arr[m-1]<key) && arr[m]==key)
			return m;
		else if(key > arr[m])
			binarysearch(arr,++m,r,key);
		else 
			binarysearch(arr,l,--m,key);
	}
	else
		return -1;
}

bool checkifMajority(int arr[],int n,int candidate)
{
	int index = binarysearch(arr,0,n-1,candidate);

	return (index>=0 && index<n) && (arr[index]==candidate && arr[index+(n/2)]==candidate) ? true : false;

}

int main()
{
	int arr[] = {1, 2, 3, 3, 3, 3, 10};
	int n = sizeof(arr)/sizeof(arr[0]);

	checkifMajority(arr,n,3) ? cout<<"Yes! Its Majority Element!": cout<<"No! Itsn't";

	cin.get();
	return 0;
}