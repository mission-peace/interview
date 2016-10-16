#include<iostream>
using namespace std;


int swapcount = 0;
void printArray(int arr[],int n)
{
	cout<<endl;
	for(int i=0 ; i<=n-1 ; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

void Swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int Partition(int arr[],int si,int ei)
{
	int pivot = arr[ei];
	int j = si;

	for(int i=si ; i<=ei-1 ; i++)
	{
		if(arr[i] <= pivot)
		{
			//cout<<"\nSwapping "<<arr[i]<<" and "<<arr[j];
			Swap(&arr[j++],&arr[i]);
			swapcount++;
		}
	}
	//cout<<"\nSwapping "<<arr[j]<<" and "<<arr[ei];
	Swap(&arr[j],&arr[ei]);
	swapcount++;
	return pivot;
}

void QuickSort(int arr[],int si,int ei)
{
	if(si < ei)
	{
		int pivot = Partition(arr,si,ei);
		QuickSort(arr,si,pivot-1);
		QuickSort(arr,pivot+1,ei);
	}
}

int main()
{
	int arr[] = {3,6,1,8,4,9,1,2,6};
	int n = sizeof(arr)/sizeof(arr[0]);

	printArray(arr,n);
	QuickSort(arr,0,n-1);
	printArray(arr,n);
	cout<<"\nThe total no. of swaps made = "<<swapcount;
	cin.get();
	return 0;
}