#include<iostream>
using namespace std;

int _lis(int *arr,int n,int *maxlis)
{
	if(n==1)
		return 1;

	int lisendhere=1,templis = 1;
	for(int i=1 ; i<=n-1 ; i++)
	{
		templis = _lis(arr,i,maxlis);
		if(arr[i-1] < arr[n-1])
		 lisendhere = max(1+templis,lisendhere);
	}
	if(lisendhere > *maxlis)
		*maxlis = lisendhere;
	return lisendhere;
}

int lis(int *arr,int n)
{
	int maxlis = 0;
	_lis(arr,n,&maxlis);
	return maxlis;
}

int lis_DP(int *arr,int n)
{
	int maxlis = 0;
	/*
	int *dp = new int[n]();
	for(int i=0 ; i<=n-1 ; i++)
		dp[i] = 1;
	int maxlis = -1;
	for(int i=1 ; i<=n ; i++)
	{
		for(int j=0 ; j<=i-1 ; j++)
		{
			if(arr[j] < arr[i])
			{
				dp[i] = max(dp[i],1+dp[j]);
				maxlis = max(maxlis,dp[i]);
			}
		}
	}
	*/

	// Look at the beautiful explanation under msis!
	int *dp = new int[n+1]();
	for(int i=1 ; i<=n ; i++)
		dp[i] = 1;
	
	for(int i=2 ; i<=n ; i++)
	{
		for(int j=0 ; j<=i-2 ; j++)
		{
			if(arr[j] < arr[i-1])
			{
				dp[i] = max(dp[i],1+dp[j+1]);
				maxlis = max(maxlis,dp[i]);
			}
		}
	}

	return maxlis;

}

int msis(int *arr,int n)
{
	int *msis = new int[n+1];
	for(int i=1 ; i<=n ; i++)
		msis[i] = arr[i-1];

	// Start from msis[2] since msis[1] = arr[1]
	// if we fix msis[x] as say 3,i.e, arr[2], then travel 0 and 1, Thus, iter from 2->n
	// j is basically an index to iter the arr! Thus, iter from 0->i-2 (one index less than final idex, i-1)
	// if arr[j] is < arr[i-1] , i-1 => final index, then add ele[n-1] with the j corresponding in msis
	// since j was initially designed for indexing array, now we use j to index msis, we are adding extra 1
	// note that we have msis[n+1] eleements msis[i] => msis ending at i!
	int maxmsis = 0;
	for(int i=2 ; i<=n ; i++)
	{
		for(int j=0 ; j<=i-2 ; j++)
		{
			if(arr[j] < arr[i-1])
			{
				msis[i] = max(msis[i],msis[j+1]+arr[i-1]);
				maxmsis = max(maxmsis,msis[i]);
			}
		}
	}
	return maxmsis;
}

int main()
{
	int arr[] = {10,20,13,6,23,7,30,32};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout<<lis(arr,n)<<endl;
	cout<<lis_DP(arr,n)<<endl;
	cout<<msis(arr,n)<<endl;

	cin.get();
	return 0;
}