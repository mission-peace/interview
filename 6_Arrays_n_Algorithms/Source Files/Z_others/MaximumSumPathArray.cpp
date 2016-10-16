#include<iostream>
using namespace std;

int MaximumSumPath(int arr1[],int m,int arr2[],int n)
{
	int i=0,j=0;
	int cur1 = arr1[i],cur2 = arr2[j];
	int prev = 0;

	while(i<=m-1 && j<=n-1)
	{
		if(arr1[i] < arr2[j])
		{
			i++;
			if(i<=m-1)
				cur1 += arr1[i];
		}
		else if (arr2[j] < arr1[i])
		{
			j++;
			if(j<=n-1)
				cur2 += arr2[j];
		}
		else
		{
			prev = max(prev+cur1,prev+cur2);
			i++; j++;
			if(i<=m-1)
				cur1 = arr1[i];
			if(j<=n-1)
				cur2 = arr2[j];
		}
	}

	while(j<=n-1)
	{
		j++;
		if(j<=n-1)
			cur2 +=arr2[j];
	}
	while(i<=m-1)
	{
		i++;
		if(i<=m-1)
		cur1 +=arr1[i];
	}

	prev = max(prev+cur1,prev+cur2);
	return prev;
}

int main()
{
	int arr1[] = {2, 3, 7, 10, 12};
	int m = sizeof(arr1)/sizeof(arr1[0]);

	int arr2[] = {1, 5, 7, 8};
	int n = sizeof(arr2)/sizeof(arr2[0]);

	cout<<MaximumSumPath(arr1,m,arr2,n);


	cin.get();
	cin.get();
	return 0;
}