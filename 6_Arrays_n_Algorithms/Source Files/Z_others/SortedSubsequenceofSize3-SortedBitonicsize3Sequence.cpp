#include<iostream>
using namespace std;

void findSubsequenceoflen3(int *arr,int n)
{
	int *small = new int[n];
	int *big = new int[n];
	
	small[0] = -1;
	big[n-1]= -1;

	int min_sofar = 0;
	for(int i=1 ; i<=n-1 ; i++)
	{
		if(arr[min_sofar] < arr[i])
			small[i] = min_sofar;
		else
		{
			small[i] = -1;
			min_sofar = i;
		}
	}
	int max_sofar =n-1;
	for(int i=n-2 ; i>=0 ; i--)
	{
		if(arr[i] < arr[max_sofar])  // change this to arr[i] > arr[min_sofar] and min_sofar must track the minimum element
			big[i] = max_sofar;
		else
		{
			big[i] = -1;
			max_sofar = i;
		}
	}

	int maxprod = -1;
	int maxprodi = -1;
	int i;
	for(i=0 ; i<=n-1 ; i++)
	{
		if(small[i]!=-1 && big[i]!=-1)
		{
			cout<<"The 3 numbers of sequence are : "<<arr[small[i]]<<" "<<arr[i]<<" "<<arr[big[i]]<<endl;

			if(maxprod < arr[small[i]]*arr[i]*arr[big[i]])
			{
				maxprod = max(maxprod,arr[small[i]]*arr[i]*arr[big[i]]);
				maxprodi = i;
			}
		}
	}

	cout<<"The 3 numbers of sequence are : "<<arr[small[maxprodi]]<<" * "<<arr[maxprodi]<<" * "<<arr[big[maxprodi]]<<" = "<<maxprod<<endl;

}

int main()
{
	int arr[] = {6, 7, 8, 1, 2, 3, 9, 10};
	int n = sizeof(arr)/sizeof(arr[0]);

	findSubsequenceoflen3(arr,n);

	cin.get();
	cin.get();
	return 0;
}