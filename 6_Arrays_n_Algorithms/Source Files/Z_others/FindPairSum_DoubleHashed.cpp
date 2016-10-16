#include<iostream>
using namespace std;

void findPairSum(int arr[],int Bmap[],int n,int key)
{

	int temp = 0;

	for(int i=0 ; i<=n-1 ; i++)
	{
		temp = key - arr[i];

		if(Bmap[i]==1 && temp>=0)
			cout<<"The pair is : "<<arr[i]<<" "<<;
	}
}



int main()
{
	int arr[] = {0,1,4,6,10,45};

	int n = sizeof(arr)/sizeof(arr[0]);
	int *Bmap = new int[n]();
	int key = 16;

	findPairSum(arr,Bmap,n,key);

	cin.get();
	return 0;
}