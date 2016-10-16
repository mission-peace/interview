#include<iostream>
using namespace std;

void Swap(int *a,int *b)
{
	int temp = *a;
	*a=*b;
	*b = temp;

}

void printArray(int arr[],int len)
{
	cout<<endl;
	for(int i=0 ; i<=len-1 ; i++)
		cout<<arr[i]<<" ";
}

void mergeArray(int arr[],int s,int m,int e)
{
	int h1 = m-s+1;
	int h2 = e-m;

	int *half1 = new int[h1];
	int *half2 = new int[h2];

	for(int i=0 ; i<= h1-1 ; i++)
		half1[i] = arr[s+i];

	for(int i=0 ; i <= h2-1 ; i++ )
		half2[i] = arr[m+1+i];

	int i=0;
	int j=0;
	int k=s;
	for( ; i < h1 && j < h2 ; )
	{
		if(half1[i] <= half2[j])
			arr[k++] = half1[i++];
		else
			arr[k++] = half2[j++];
	}

	while(i < h1)
		arr[k++] = half1[i++];

	while(j < h2)
		arr[k++] = half2[j++];

}

void MergeSort(int arr[],int s,int e)
{
	if(e-s >=1 )
	{
		int mid = (s+e-1)/2;
		MergeSort(arr,s,mid);
		MergeSort(arr,mid+1,e);
		mergeArray(arr,s,mid,e);
	}
}


void main()
{
	int arr[] = {13,6,23,15,8,12,3,28,2,16,15};
	int len = sizeof(arr)/sizeof(arr[0]);

	printArray(arr,len);
	MergeSort(arr,0,len-1);
	printArray(arr,len);


	cin.get();
}