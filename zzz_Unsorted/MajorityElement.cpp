#include<iostream>
using namespace std;

void printMajority(int *arr,int size)
{
	int count = 1;
	int majele = arr[0];

	for(int i=0 ; i<=size-1 ; i++)
	{
		if(majele==arr[i])
		{
			count++;
			continue;
		}
		else
		{
			count--;

			if(count < 0)
			{
				count = 1;
				majele = arr[i];
			}
		}
	}

	count>1	? 
		cout<<"The majority element is : "<<majele	:
		cout<<"No element occurs >= n/2 , Hence no Majority Element exist";
}


int main()
{
	int arr[] = {5,2,2,3,5,6,5,2,5,3,7,3};
	int n = sizeof(arr)/sizeof(arr[0]);

	printMajority(arr,n);
	
	cin.get();
	cin.get();
	return 0;
}
