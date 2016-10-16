#include<iostream>
using namespace std;

void main()
{
	int arr[7] = {100,30,32,34,36,39,40};
	int n=7;

	int i = 0, j = 0;
    for(; i < n; ++i)
	{
        while(j < n && arr[i] < arr[j])
		{
            j++;
			cout<<"\nInside while loop, j is : "<<j;
		}
		cout<<"\n Inside for loop, i is : "<<i;
	}

	cout<<"\n\n Finally i and j are : "<<i<<"   "<<j;

	cin.get();
}