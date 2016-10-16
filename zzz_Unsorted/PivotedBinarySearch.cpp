#include<iostream>
using namespace std;

int getPivot(int arr[],int l,int r,int size)
{
	if(r  > l)
	{
		if(l==0 && r==size-1 && arr[l] < arr[r])
			return -1;

		int mid = l + (r-l)/2;

		if(arr[mid] > arr[mid+1])
			return mid;
		else if(arr[l] < arr[mid])
			getPivot(arr,mid,r,size);
		else if(arr[mid] < arr[r])
			getPivot(arr,l,mid,size);

	}
	else
		return -1;
}

void reverseArray(int *arr,int *e)
{

}

int main()
{
	int arr[] = {4,5,6,7,8,9,10,11,12,1,2,3};
	int n = sizeof(arr)/sizeof(arr[0]);


	for(int i=0 ; i<=n-1 ; i++)
	{
	    int key = arr[i];
		int res = getPivot(arr,0,n-1,n);

		res == -1 ? 
			cout<<"\n Key = "<<key<<" not found...\n" :
			cout<<"\n Key = "<<key<<" is found at position : "<<res<<endl;

	}
	cin.get();
	cin.get();
	return 0;
}