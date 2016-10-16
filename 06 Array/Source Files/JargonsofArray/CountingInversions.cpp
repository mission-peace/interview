#include<iostream>
using namespace std;

void printArray(int arr[],int n)
{
	cout<<endl;
	for(int i=0 ; i<=n-1 ; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int Merge(int arr[],int l,int m,int r)
{
	int inv_count = 0;

	int n1 = m-l+1;
	int n2 = r-m;

	int *L = new int[n1];
	int *R = new int[n2];

	for(int i=0 ; i<=n1-1 ; i++)
		L[i] = arr[l+i];
	for(int i=0 ; i<=n2-1 ; i++)
		R[i] = arr[m+1+i];

	int i=0,j=0,k=l;
	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j])			// Stability expression
			arr[k++]=L[i++];
		else
		{
			arr[k++]=R[j++];
			inv_count += m-i-l+1;
		}
	}

	while(i < n1)
		arr[k++]=L[i++];
	while(j < n2)
		arr[k++]=R[j++];

	return inv_count;
}

int MergeSort(int arr[],int l,int r)
{
	int inv_count = 0;
	if(l < r)
	{
		int m=l+(r-l)/2;
		inv_count += MergeSort(arr,l,m);
		inv_count += MergeSort(arr,m+1,r);
		inv_count += Merge(arr,l,m,r);
	}
	return inv_count;
}

int main()
{
	int arr[] = {1, 4, 5,6,20};
	int n = sizeof(arr)/sizeof(arr[0]);

	printArray(arr,n);
	cout<<"The Number of Inversions in the array : "<<MergeSort(arr,0,n-1);
	printArray(arr,n);

	cin.get();
	return 0;
}