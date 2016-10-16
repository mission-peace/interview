#include<iostream>
using namespace std;

void findMaxjminusi(int arr[],int n)
{
	int i=0;
	int j=n-1;
	int maxdiff = -1;

	while(i<=j)
	{
		if(arr[j] > arr[i] && j-i>=0)
			maxdiff = max(maxdiff,j-i);

		if(arr[j-1] >= arr[i])
			j--;
		else
			i++;
	}

	cout<<maxdiff<<endl;
}

int main()
{
	int arr[] = {6,2,3,4,5,5,7,5,5};
	int n = sizeof(arr)/sizeof(arr[0]);

	findMaxjminusi(arr,n);

	cin.get();
	return 0;
}