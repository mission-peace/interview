#include<iostream>
using namespace std;

bool ifMajority(int arr[],int n,int candidate)
{
	int count = 0;

	for(int i=0 ; i<=n-1 ; i++)
	{
		if(arr[i]==candidate)
			count++;
	}
	return count > (n/2) ; 
}

int findMajor(int arr[],int n)
{
	int majorindex = 0;
	int count = 1;

	for(int i=1 ; i<=n-1 ; i++)
	{
		if(arr[i]==arr[majorindex])
			count++;
		else 
			count--;
		if(count==0)
		{
			majorindex = i;
			count = 1;
		}
	}
	return majorindex;
}

void printMajority(int arr[],int n)
{
	int candidate = arr[findMajor(arr,n)];
	if(ifMajority(arr,n,candidate))
		cout<<"The Majority element is : "<<candidate;
	else
	{
		cout<<"Sorry No majority! "<<endl;
	}
}



int main()
{
	int arr[] = {2, 2, 3, 5, 2, 2, 6};
	int n = sizeof(arr)/sizeof(arr[0]);

	printMajority(arr,n);

	cin.get();
	return 0;
}