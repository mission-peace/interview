#include<iostream>
using namespace std;

struct Pair
{
	int min;
	int max;
};

void printArray(int arr[],int n)
{
	cout<<endl;
	for(int i=0 ; i<=n-1 ; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

struct Pair *MinnMaxinArray(int arr[],int n)
{
	struct Pair *extremes= new struct Pair();

	extremes->min = arr[0];
	extremes->max = arr[0];

	for(int i=1 ; i<=n-1 ; i++)
	{
		extremes->min = min(extremes->min,arr[i]);
		extremes->max = max(extremes->max,arr[i]);
	}
	return extremes;
}



int main()
{
	int arr[] = {10,3,5,6,2};
	int n = sizeof(arr)/sizeof(arr[0]);

	printArray(arr,n);
	struct Pair *temp = MinnMaxinArray(arr,n); 
	cout<<"Minimum is : "<<temp->min<<endl;
	cout<<"Maximum is : "<<temp->max<<endl;

	cin.get();
	return 0;
}