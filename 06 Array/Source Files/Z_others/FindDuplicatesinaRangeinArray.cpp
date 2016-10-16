#include<iostream>
using namespace std;

void printDuplicates(int arr[],int n)
{
	for(int i=0 ; i<=n-1 ; i++)
	{
		if(arr[abs(arr[i])] >= 0)
			arr[abs(arr[i])] = -1*arr[abs(arr[i])] ; 
		else
			cout<<"One of the repeating elements is : "<<abs(arr[i])<<endl;
	}
}

int main()
{
	int arr[] = {1, 2, 3, 1, 3, 0, 2, 3,3,0};
	int n = sizeof(arr)/sizeof(arr[0]);
	printDuplicates(arr,n);

	cin.get();
	return 0;
}