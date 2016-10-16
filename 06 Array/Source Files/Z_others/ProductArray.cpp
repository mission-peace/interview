#include<iostream>
using namespace std;

void printArray(int arr[],int n)
{
	cout<<endl;
	for(int i=0 ; i<=n-1 ; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

void productArray(int arr[],int n)
{
	int temp = 1;

	int *prod = new int[n];

	memset(prod,1,sizeof prod);

	prod[0] = temp;
	for(int i=1 ; i<=n-1 ; prod[i++] = temp)
		temp *= arr[i-1];
		
	temp = 1;
	for(int i=n-2 ; i>=0 ; prod[i--] *= temp)
		temp *= arr[i+1];

	printArray(prod,n);
}

int main()
{
	int arr[] = {10,3,5,6,2};
	int n = sizeof(arr)/sizeof(arr[0]);

	printArray(arr,n);
	productArray(arr,n);
	



	cin.get();
	return 0;
}