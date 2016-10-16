#include<iostream>
using namespace std;

struct HashMapProps
{
	int Range;
	int offset;
};

struct HashMapProps getHashMapDetails(int *arr,int n)
{
	int minval = +99999;
	int maxval = -99999;

	for(int i=0 ; i<=n-1 ; i++)
	{
		minval = min(minval,arr[i]);
		maxval = max(maxval,arr[i]);
	}

	struct HashMapProps temp;
	temp.Range = maxval-minval;
	temp.offset = -minval;
	return temp;
}

void findPairofgivenSum(int *arr,int n,int sum)
{
	struct HashMapProps temp = getHashMapDetails(arr,n);

	int *hashmap = new int[temp.Range]();
	int offset = temp.offset;
	int nosumflag = 0;

	for(int i=0 ; i<=n-1 ; i++)
	{
		if(hashmap[sum-arr[i]+offset]==1)
		{
			cout<<arr[i]<<" + "<<sum-arr[i]<<" = "<<sum<<endl; //&hashmap[sum-arr[i]+offset]-hashmap-offset
			nosumflag = 1;
		}
		hashmap[arr[i]+offset] = 1;
	}

	if(!nosumflag)
		cout<<"Sorry! There are no pairs in the array which can sum to "<<sum;
}

int main()
{
	int arr[] = {20,26,-2,22,4,25,28,-1,0};
	int n = sizeof(arr)/sizeof(arr[0]);
	int sum = 24;

	findPairofgivenSum(arr,n,sum);

	cin.get();
	cin.get();
	return 0;
}