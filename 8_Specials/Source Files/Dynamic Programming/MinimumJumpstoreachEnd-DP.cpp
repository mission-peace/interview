/*
TIME = O(n^2)
SPACE = O(n)
*/

#include<iostream>
#define INT_MAX 999999
using namespace std;

int getMinimumJumps(int arr[],int memo[],int start,int end)
{
	// If Destination is same as Source! No need to jump! 
	// Just stay still! Not even 1 jump is needed
	if(start==end)
		return 0;
	if(arr[start]==0)
		return INT_MAX;
	if(memo[start])
		return memo[start];

	int minjumps = INT_MAX;
	// Check if start has enough strength (start+arr[start]) 
	// to reach i
	for(int i=start+1 ; i<=end && start+arr[start] >= i; i++)
	{
		int tempjump = getMinimumJumps(arr,memo,i,end);
		minjumps = min(minjumps,tempjump+1);
	}

	memo[start] = minjumps;
	return minjumps;
}

int getMinimumJumps(int arr[],int n)
{
	int *JUMPS = new int[n];
	// If Destination is same as Source! No need to jump! 
	// Just stay still! Not even 1 jump is needed
	JUMPS[0] = 0;
	for(int i=1 ; i<=n-1 ; i++)
		JUMPS[i] = INT_MAX;

	for(int i=1 ; i<=n-1 ; i++)
	{
		for(int j=0 ; j<=i-1 ; j++)
		{
			// Does j have strength (j+arr[j]) to reach i?
			if(arr[j] + j >= i)
				JUMPS[i] = min(JUMPS[i],JUMPS[j]+1);
		}
	}
	return JUMPS[n-1];
}

int main()
{
	int arr[] = {1, 3, 0, 2, -1, 2, 0, 7, 6, 8, 9};
	int n = sizeof(arr)/sizeof(arr[0]);

	int *memo = new int[n]();
	cout<<"\nMinimum jumps to reach end is (Memoization): "<<getMinimumJumps(arr,memo,0,n-1);
	cout<<"\nMinimum jumps to reach end is (Tabulation) : "<<getMinimumJumps(arr,n);
	cin.get();
	cin.get();
	return 0;
}