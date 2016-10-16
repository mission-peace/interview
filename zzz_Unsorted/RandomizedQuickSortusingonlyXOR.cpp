#include<iostream>
using namespace std;

void printArray(int *arr,int n)
{
	cout<<endl;
	for(int i=0 ; i<=n-1 ; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

void Swap(int *a,int *b)
{
	if(a!=b)
	{
		*a = (*a) ^ (*b);
		*b = (*a) ^ (*b);
		*a = (*a) ^ (*b);
	}
}

int Partition(int *arr,int si,int ei)
{
	if(si > ei)
		return si-1;

	int pivot = arr[ei];

	int i=si;
	int j=si;

	for( ; j<=ei-1 ; j++)
	{
		if(arr[j] <= pivot)
		{
			Swap(&arr[i],&arr[j]);
			i++;
		}
	}
	Swap(&arr[i],&arr[ei]);
	return i;
}

int randomPartition(int arr[],int si,int ei)
{
	int n = ei-si+1;
	int random = rand()%n;
	Swap(&arr[si+random],&arr[ei]);
	return Partition(arr,si,ei);
}

void QuickSort(int *arr,int si,int ei)
{
	if(si < ei)
	{
		int pivot = randomPartition(arr,si,ei);
		QuickSort(arr,si,pivot-1);
		QuickSort(arr,pivot,ei);
	}
}

int main()
{
	int arr[] = {4, 3, 5, 2, 1, 3, 2, 3};
	int n = sizeof(arr)/sizeof(arr[0]);

	printArray(arr,n);
	QuickSort(arr,0,n-1);
	printArray(arr,n);

	cin.get();
	cin.get();
	return 0;
}