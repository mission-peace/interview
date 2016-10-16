#include<iostream>
#define min(x,y) x<y ? x : y
#define max(x,y) x>y ? x : y
using namespace std;

struct subarr
{
	int si;
	int ei;
};

struct subarr getMaxLenSubarrtoSort(int arr[],int n)
{
	struct subarr res;

	int i=0,j=n-1;

	for(i=1 ; i<=n-1 ; i++)
	{
		if(arr[i-1]>arr[i])
			break;
	}
	if(i>=n-1)
	{
		res.si = -1;
		res.ei = -1;
		return res;
	}
	
	for(j=n-2 ; j>=i+1 ; j--)
	{
		if(arr[j] > arr[j+1])
			break;
	}
	j++;
	int mini=99999;
	int maxi=-1;

	for(int k=i ; k<=j ; k++)
	{
		mini = min(mini,arr[k]);
		maxi = max(maxi,arr[k]);
	}
	int x=i-1,y=j+1;

	if(mini>arr[x])
		res.si = i;
	else
	{
		for( ; x>=0 ; x--)
		{
			if(arr[x] < mini)
				break;
		}
		res.si = x+1;
	}

	if(maxi < arr[y])
		res.ei = j;
	else
	{
		for( ; y<=n-1 ; y++)
		{
			if(maxi < arr[y])
				break;
		}
		res.ei = y-1;
	}
	return res;


}

int main()
{
	int arr[] = {10,20,30,40,50};
	int n = sizeof(arr)/sizeof(arr[0]);

	struct subarr inst = getMaxLenSubarrtoSort(arr,n);
	cout<<"\n The sorting should begin at Sub-array index : "<<inst.si;
	cout<<"\n The sorting should end at Sub-array index : "<<inst.ei;

	cin.get();
	cin.get();
	return 0;
}