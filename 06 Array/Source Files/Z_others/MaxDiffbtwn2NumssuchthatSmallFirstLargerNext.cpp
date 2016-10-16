#include<iostream>
using namespace std;

void printArray(int arr[],int n)
{
	cout<<endl;
	for(int i=0 ; i<=n-1 ; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}


void MaxDiffsuchThatSmallFirstBigNext(int arr[],int n)
{
	int max_diff = 99999;
	int smallest_sofar = arr[0];

	for(int i=1 ; i<=n-1 ; i++)
	{
		if(smallest_sofar < arr[i])
			max_diff = min(max_diff,smallest_sofar-arr[i]);
		smallest_sofar= min(smallest_sofar,arr[i]);
	}

	cout<<"Maximum difference of "<<max_diff*-1<<endl;

}

int main()
{
	int arr[] = {9,7,9,5, 6, 3, 2,9};
	int n = sizeof(arr)/sizeof(arr[0]);

	printArray(arr,n);
	MaxDiffsuchThatSmallFirstBigNext(arr,n);

	cin.get();
	return 0;
}