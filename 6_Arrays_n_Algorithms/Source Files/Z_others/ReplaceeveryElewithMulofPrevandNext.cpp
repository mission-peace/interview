#include<iostream>
using namespace std;

void printArray(int arr[],int n)
{
	cout<<endl;
	for(int i=0 ; i<=n-1 ; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

void replaceElewithMulofPrevnNext(int arr[],int n)
{
	if(n<=1)
		return;

	int prev = arr[0];

	arr[0] = arr[0]*arr[1];
	for(int i=1 ; i<=n-2 ; i++)
	{
		int cur = arr[i];
		arr[i] = prev*arr[i+1];
		prev = cur;
	}
	arr[n-1] = prev*arr[n-1];
}
int main()
{
	int arr[] = {2,3,4,5,6};
	int n = sizeof(arr)/sizeof(arr[0]);

	replaceElewithMulofPrevnNext(arr,n);
	printArray(arr,n);

	cin.get();
	cin.get();
	return 0;
}