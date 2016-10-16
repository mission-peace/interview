#include<iostream>
using namespace std;

bool isSubsetSum(int *set,int n,int sum)
{
	if(sum==0)
		return true;
	if(n==0 && sum!=0)
		return false;

	if(set[n-1] > sum)
		isSubsetSum(set,n-1,sum);
	else
		return isSubsetSum(set,n-1,sum)||isSubsetSum(set,n-1,sum-set[n-1]);
}

bool isSubsetSum_DP(int *arr,int n,int sum)
{
	bool **dpTable = new bool*[n+1]();
	for(int i=0 ; i<=n ; i++)
		dpTable[i] = new bool[sum+1]();

	for(int i=1 ; i<=sum ; i++)
		dpTable[0][i] = false;
	for(int i=0 ; i<=n-1 ; i++)
		dpTable[i][0] = true;

	for(int i=1 ; i<=sum ; i++)
	{
		for(int j=1 ; j<=n ; j++)
		{
			if(arr[j-1] <= i)
				dpTable[i][j] = dpTable[i][j] || dpTable[i-arr[j-1]][j-1];
			else
				dpTable[i][j] = dpTable[i][j-1];
		}
	}

	return dpTable[n][sum];
}

int main()
{
	int set[] = {3, 34, 4, 12, 5, 2};
	int sum = 1;
	int n = sizeof(set)/sizeof(set[0]);
	if (isSubsetSum(set, n, sum) == true)
		printf("Found a subset with given sum");
	else
		printf("No subset with given sum");
	printf("\n");
	if (isSubsetSum_DP(set, n, sum) == true)
		printf("Found a subset with given sum");
	else
		printf("No subset with given sum");
	cin.get();
	cin.get();
	return 0;

}