
#include<iostream>
using namespace std;

void Swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int SeggregatePosNeg(int *arr, int n)
{
	int i,k;

	for(i=0,k=n-1 ; i<k ; )
	{
		if(arr[i] > 0)
			i++;
		else
		{
			Swap(&arr[i],&arr[k]);
			k--;
		}

	}

	return i;
}

int FindSmallestMissing(int *arr, int n)
{
	int end = SeggregatePosNeg(arr,n);

	int missing = -1;

	for(int i=0 ; i<=end-1 ; i++)
	{
		if(abs(arr[i]-1) < end && arr[abs(arr[i])-1] > 0)
			arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
	}

	int i;
	for(i=0 ; i<=end-1 ; i++)
	{
		if(arr[i] > 0)
		{
			return i+1;
		}
	}
	
	if(missing==-1)
		return i+1;

}

int main()
{
	int arr[] = {2, 3, 7, 6, 8, -1, -10, 15};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout<<"The Smallest missing number is : "<<FindSmallestMissing(arr,n);
	cin.get();
	cin.get();
	return 0;
}
