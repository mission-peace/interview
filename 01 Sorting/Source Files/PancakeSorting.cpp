#include<iostream>
using namespace std;

void Swap(int *a,int *b)
{
	if(a!=b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}
}

void reverseArray(int arr[],int n)
{
	int i=0,j=n;
	while(i<j)
		Swap(&arr[i++],&arr[j--]);
	
}

int findMaxIndex(int arr[],int n)
{
	int maxnum = arr[0];
	int maxindex = 0;
	for(int i=1 ; i<=n-1 ; i++)
	{
		if(arr[i] > maxnum)
		{
			maxnum = arr[i];
			maxindex = i;
		}
	}
	return maxindex;
}

void PanCakeSorting(int arr[],int n)
{
	for(int cursize = n ; cursize>=1 ; cursize--)
	{
		int maxi = findMaxIndex(arr,cursize);
		if(maxi!=cursize-1)
		{
			reverseArray(arr,maxi);
			reverseArray(arr,cursize-1);
		}
	}
}

void printArray(int arr[],int n)
{
	cout<<endl;
	for(int i=0 ; i<=n-1 ; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int main()
{
	int arr[] = {23, 10, 20, 11, 12, 6, 7};
	int n = sizeof(arr)/sizeof(arr[0]);

	PanCakeSorting(arr,n);
	printArray(arr,n);

	cin.get();
	cin.get();
	return 0;
}