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
	if(a!=b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}
}

void SegregateEvenOdd(int arr[],int n)
{
	int i=0,j=n-1;

	while(i<=j)
	{
		if((arr[i])%2==0)
			i++;
		else
		{
			Swap(&arr[i],&arr[j]);
			j--;
		}
	}
}

int main()
{
	int arr[] = {12, 34, 45, 9, 8, 90, 3};
	int n = sizeof(arr)/sizeof(arr[0]);

	SegregateEvenOdd(arr,n);
	printArray(arr,n);

	cin.get();
	cin.get();
	return 0;
}