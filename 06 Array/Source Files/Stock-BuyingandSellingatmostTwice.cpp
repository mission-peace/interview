/*
In this Stock Problem, the array denotes the
prices of the stock for a 'single day'
and we can make at the maximum 2 transacts!

Hence, 
MaxProfit = max( profit[0..i] + profit[i...n-1])
*/

#include<iostream>
using namespace std;

int MaxProfit2Transactions(int arr[],int n)
{
	int *profit = new int[n]();

	int rightmax = arr[n-1];
	for(int j=n-2 ; j>=0 ; j--)
	{
		rightmax = max(rightmax,arr[j]);
		profit[j] = max(profit[j+1],rightmax - arr[j]);
	}

	int leftmin = arr[0];
	for(int i=1 ; i<=n-1 ; i++)
	{
		leftmin = min(leftmin,arr[i]);
		profit[i] = max(profit[i-1],profit[i]+arr[i]-leftmin);
	}

	return profit[n-1];
}

int main()
{
	int arr[] = {2, 30, 15, 10, 8, 25, 80};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout<<MaxProfit2Transactions(arr,n);

	cin.get();
	cin.get();
	return 0;
}