#include<iostream>
using namespace std;

void printLEADERS(int arr[],int n)
{
	int curmax = arr[n-1];
	cout<<"LEADER found : "<<arr[n-1]<<endl;

	for(int i=n-2 ; i>=0 ; curmax = max(curmax,arr[i--]))
		if(arr[i] > curmax)
			cout<<"LEADER found : "<<arr[i]<<endl;
}


int main()
{
	int arr[] = {16, 17, 4, 3, 5, 2};
	int n = sizeof(arr)/sizeof(arr[0]);

	printLEADERS(arr,n);

	cin.get();
	return 0;
}