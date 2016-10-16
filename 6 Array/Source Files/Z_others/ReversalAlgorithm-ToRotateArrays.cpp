#include<iostream>
using namespace std;

void printArray(int arr[],int n)
{
	cout<<endl;
	for(int i=0 ; i<=n-1 ; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

void Reverse(int arr[],int si,int ei,bool anticlock=true)
{
	while(si < ei)
	{
		if(anticlock)
		{
			int temp = arr[si];
			arr[si] =  arr[ei];
			arr[ei] = temp;
		}
		else
		{
			int temp = arr[ei];
			arr[ei] =  arr[si];
			arr[si] = temp;
		}
		si++;
		ei--;
	}
}

void RotateArray(int arr[],int n,int rotate,bool anticlock=true)
{
	rotate = rotate%n;
	Reverse(arr,0,rotate-1);
	Reverse(arr,rotate,n-1);
	Reverse(arr,0,n-1);
}

int main()
{
	int arr[] = {1,2,3,4,5,6,7};
	int n = sizeof(arr)/sizeof(arr[0]);

	int rotations = 2;

	printArray(arr,n);
	RotateArray(arr,n,rotations);
	printArray(arr,n);
	RotateArray(arr,n,n-(rotations%n));
	printArray(arr,n);


	cin.get();
	return 0;

}