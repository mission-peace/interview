#include<iostream>
using namespace std;

template<class T>void printArray(T *arr,int len)
{
	cout<<endl;
	for(int i=0 ; i<=len-1 ; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

void Merging(int *arr,int l,int m,int r)
{
	int i=0,j=0,k=l;
	int n1 = m-l+1;
	int n2 = r-m;

	int *L = new int[n1];
	int *R = new int[n2];

	for(int i=0 ; i < n1 ; i++)
		L[i] = arr[l+i];
	for(int j=0 ; j < n2 ; j++)
		R[j] = arr[m+1+j];

	for( ; i<n1 && j<n2; k++)
	{
		if(L[i] <= R[j])
			arr[k]=L[i++];
		else
			arr[k]=R[j++];
	}

	while(i < n1)
		arr[k++]=L[i++];
	while(j < n2)
		arr[k++]=R[j++];

}

void MergeSort(int *arr,int left, int right)
{
	int mid;
	if(left < right)
	{
		mid = (left+right-1)/2;
		MergeSort(arr,left,mid);
		MergeSort(arr,mid+1,right);
		Merging(arr,left,mid,right);
	}
}

void main()
{
	int a[10]={-1,6,8,0,6,5,7,-3,6,1};

	MergeSort(a,0,sizeof(a)/sizeof(a[0])-1);
	printArray(a,sizeof(a)/sizeof(a[0]));

	cin.get();

}