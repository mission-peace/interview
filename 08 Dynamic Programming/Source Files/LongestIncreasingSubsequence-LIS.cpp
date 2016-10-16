#include<iostream>
using namespace std;

int LIS(int *arr,int n)
{
	int *lis = new int[n]();

	for(int i=0 ; i<=n-1 ; i++)
		lis[i] = 1;

	int res = lis[0];

	for(int i=1 ; i<=n-1 ; i++)
	{
		for(int j=0 ; j<i ; j++)
		{
			if(arr[j] < arr[i])
				lis[i] = max(lis[i],lis[j]+1);
		}
		res = max(res,lis[i]);
	}

	return res;

}

int MSIS(int *arr, int n)
{
	int *msis = new int[n];
	int res = arr[0];

	for(int i=0 ; i<=n-1 ; i++)
		msis[i] = arr[i];

	for(int i=1 ; i<=n-1 ; i++)
	{
		for(int j=0 ; j<i ; j++)
		{
			if(arr[j] < arr[i])
				msis[i] = max(msis[i],msis[j]+arr[i]);
		}
		res = max(res,msis[i]);
	}

	return res;
}

int LBiS(int *arr,int n)
{
	int *lis = new int[n];
	int *dis = new int[n];
	int res = -1;

	for(int i=0 ; i<=n-1 ; i++)
	{
		lis[i] = 1;
		dis[i] = 1;
	}

	for(int i=1 ; i<=n-1 ; i++)
	{
		for(int j=0 ; j<i ; j++)
		{
			if(arr[j] < arr[i])
				lis[i] = max(lis[i],lis[j]+1);
		}
	}

	for(int i=n-2 ; i>=0 ; i--)
	{
		for(int j=n-1 ; j>i ; j--)
		{
			if(arr[i] > arr[j])
				dis[i] = max(dis[i],dis[j]+1);
		}
		res = max(res,dis[i]+lis[i]-1);
	}
	res = max(res,dis[n-1]+lis[n-1]-1);

	return res;
}

int main()
{
	int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5,
              13, 3, 11, 7, 15};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout<<"The Longest Increasing Subsequence is : "<<LIS(arr,n);
	cout<<"\n\n";
	cout<<"The Maximum Sum Increasing Subsequence is "<<MSIS(arr,n);
	cout<<"\n\n";
	cout<<"The Longest Bitonic Subsequence is "<<LBiS(arr,n);


	cin.get();
	cin.get();
	return 0;
}