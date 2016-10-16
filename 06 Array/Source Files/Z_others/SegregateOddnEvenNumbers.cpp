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
	int Hi=n-1;

	while(Lo <= Hi)
	{
		if(arr[Lo]&1)
			Swap(&arr[Lo],&arr[Hi--]);
		else
			Lo++;
	}
}

int main()
{
	int arr[] = {12, 34, 45, 9, 8, 90, 3};
	int n = sizeof(arr)/sizeof(arr[0]);

	printArray(arr,n);
	DutchNationalFlag(arr,n);
	printArray(arr,n);

	cin.get();
	return 0;
}