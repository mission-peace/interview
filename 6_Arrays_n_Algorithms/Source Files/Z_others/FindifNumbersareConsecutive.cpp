#include<iostream>
using namespace std;

int XORtill(int n)
{
	if(n%4==0)
		return n;
	if(n%4==1)
		return 1;
	if(n%4==2)
		return n+1;
	if(n%4==3)
		return 0;
}

bool isConsecutive(int arr[],int n)
{
	int mini = arr[0];
	int maxi = arr[0];
	int arrXOR = arr[0];

	for(int i=1 ; i<=n-1 ; i++)
	{
		mini = min(mini,arr[i]);
		maxi = max(maxi,arr[i]);
		arrXOR ^=arr[i];
	}

	int minXOR = XORtill(mini-1);
	int maxXOR = XORtill(maxi);

	int expectedXOR = maxXOR-minXOR;
	int actualXOR = minXOR^arrXOR - minXOR;

	return abs(expectedXOR)==abs(actualXOR);
}



int main()
{
	int arr[] ={34, 23, 52, 12, 3};
	int n = sizeof(arr)/sizeof(arr[0]);

	isConsecutive(arr,n) ? cout<<"True! Numbers are consecutive!" : cout<<"False! Numbers are not consecutive" ;


	cin.get();
	return 0;
}
