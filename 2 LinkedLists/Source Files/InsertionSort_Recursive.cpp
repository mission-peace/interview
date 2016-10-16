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

void InsertionSort(int arr[],int s,int e)
{
	if(s>e)
		return;

	int keyvalue = arr[s];
	int j = s;

	while(j-1>=0 && arr[j-1] > keyvalue)
	{
		Swap(&arr[j],&arr[j-1]);
		j--;
	}

	InsertionSort(arr,s+1,e);
}

void main()
{
	int arr[] = {13,6,23,15,8,12,3};
	int len = sizeof(arr)/sizeof(arr[0]);

	printArray(arr,len);
	InsertionSort(arr,1,len-1);
	printArray(arr,len);

	cin.get();
}