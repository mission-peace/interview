#include<iostream>
using namespace std;

int getSum(int arr[],int n)
{
	int sum=0;
	for(int i=0 ; i<=n-1 ; i++)
		sum += arr[i];
	return sum;
}

int PartitionSum(int arr[],int total,int i,int calcsum)
{
	if(i==0)
		return abs(total-2*calcsum);
	return min(PartitionSum(arr,total,i-1,calcsum+arr[i-1]),PartitionSum(arr,total,i-1,calcsum));
}

int PartitionSum(int arr[],int n)
{
	int total = getSum(arr,n);

	bool **PS = new bool*[n+1]();
	for(int i=0 ; i<=n ; i++)
		PS[i] = new bool[total+1];

	for(int k=0 ; k<=total ; k++)
		PS[0][k] = 0;
	for(int k=0 ; k<=n ; k++)
		PS[k][0] = 1;

	for(int i=1 ; i<=n ; i++)
	{
		for(int j=1 ; j<=total ; j++)
		{
			PS[i][j] = PS[i-1][j];

			if(arr[i-1] <= j)
				PS[i][j] |= PS[i-1][j-arr[i-1]];
		}
	}

	int mindiff = 0;
	for(int k=total/2 ; k>=0 ; k--)
	{
		if(PS[n][k]==1)
		{
			mindiff = total - 2*k;
			break;
		}
	}
	return mindiff;
}


int main()
{
	int arr[] = {4, 6, 9, 5};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout<<"\n The Minimum Difference between subsets is (RECURSION) : "<<PartitionSum(arr,getSum(arr,n),n,0)<<endl;
	cout<<"\n The Minimum Difference between subsets is (TABULATION) : "<<PartitionSum(arr,n)<<endl;
	
	cin.get();
	cin.get();
	return 0;
}