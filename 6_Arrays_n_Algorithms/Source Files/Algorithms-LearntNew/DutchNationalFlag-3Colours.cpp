#include<iostream>
using namespace std;

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

void DutchNationalFlag(int arr[],int n)
{
	int Lo=0;
	int Mi=0;
	int Hi=n-1;

	while(Mi<=Hi)
	{
		if(arr[Mi]==0)
		{
			if(arr[Lo]!=arr[Mi])
				Swap(&arr[Mi],&arr[Lo]);
			Lo++;
			Mi++;
		}
		else if(arr[Mi]==1)
		{
			Mi++;
		}
		else if(arr[Mi]==2)
		{
			if(arr[Mi]!=arr[Hi])
				Swap(&arr[Mi],&arr[Hi]);
			Hi--;
		}
	}
}

int main()
{
	int arr[] = {2,2,1,0,1,1,0,2,2,0,0,2,1,0,1};
	int n = sizeof(arr)/sizeof(arr[0]);

	printArray(arr,n);
	DutchNationalFlag(arr,n);
	printArray(arr,n);

	cin.get();
	return 0;
}