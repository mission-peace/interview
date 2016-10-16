#include<iostream>
using namespace std;

void Swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[],int l,int r)
{
	int pivot = r;
	int i=l,j=l;

	for( ; j<=r-1 ; j++)
	{
		if(arr[j] < arr[pivot])
		{
			Swap(&arr[i],&arr[j]);
			i++;
		}
	}
	Swap(&arr[i],&arr[pivot]);
	return i;
}


int randomPartition(int arr[],int l,int r)
{
	int n = r-l+1;
	int random = rand()%n;
	Swap(&arr[l+random],&arr[r]);
	return partition(arr,l,r);
}

int kthSmallestnum(int arr[],int l,int r,int k)
{
	if(k-1 <= r-l)
	{
		int pivot = randomPartition(arr,l,r);

		if(pivot-l == k-1)
			return arr[pivot];

		if(k-1 < pivot-l)
			return kthSmallestnum(arr,l,pivot-1,k);

		return kthSmallestnum(arr,pivot+1,r,k-1-(pivot-l));
	}
	else
		return -99999;
}

int main()
{
	int arr[] = {5,9,6,12,17,14,18,4,6,13};
	int n = sizeof(arr)/sizeof(arr[0]);

	for(int k=1 ; k<=n ; k++)
		cout<<"\nk = "<<k<<", kth Smallest Number is : "<<kthSmallestnum(arr,0,n-1,k)<<endl;

	cin.get();
	cin.get();
	return 0;
}