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



void main()
{
	int arr[7] = {13,6,23,15,8,12,3};
	int len = sizeof(arr)/sizeof(arr[0]);

	for(int i=0 ; i<=len-1 ; i++)
		cout<<arr[i]<<" ";

	for(int i=0 ; i<=len-1 ; i++)
	{
		for(int j=i+1 ; j<=len-1 ; j++)
		{
			if(arr[i] > arr[j])
				Swap(&arr[i],&arr[j]);	
		}
	}

	cout<<endl<<"Sorted Array : ";
	for(int i=0 ; i<=len-1 ; i++)
		cout<<arr[i]<<" ";

	cin.get();
}