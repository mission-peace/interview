#include<iostream>
#include<stack>
using namespace std;

void Swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int Partition(int *arr,int si,int ei,int *invs)
{
	int pivot = ei;
	int i = si;

	for(int j = si ; j<=ei-1 ; j++)
	{
		if(arr[pivot] > arr[j])
		{
			Swap(&arr[i],&arr[j]);
			(*invs)++;
			i++;
		}
	}
	if(arr[i] > arr[pivot])
		(*invs)++;
	Swap(&arr[i],&arr[pivot]);
	return i;
}

int getRandomPivotnPartition(int *arr,int si,int ei,int *inverts)
{
	int  randompivot = rand()%(ei-si+1);
	Swap(&arr[si+randompivot],&arr[ei]);
	return Partition(arr,si,ei,inverts);
}

void QuickSort(int *arr,int si,int ei,int *inversions)
{
	/*
	if(si <= ei)
	{
		int pivot = getRandomPivotnPartition(arr,si,ei,inversions);

		QuickSort(arr,si,pivot-1,inversions);
		QuickSort(arr,pivot+1,ei,inversions);
	} */

	stack<int > S;
	S.push(si);
	S.push(ei);

	while(!S.empty())
	{
		int ei = S.top();
		S.pop();
		int si = S.top();
		S.pop();

		int pivot = getRandomPivotnPartition(arr,si,ei,inversions);

		if(pivot-1 > si)
		{
			S.push(si);
			S.push(pivot-1);
		}

		if(pivot+1 < ei)
		{
			S.push(pivot+1);
			S.push(ei);
		}

	}


}

void printArray(int *arr,int size)
{
	cout<<endl;

	for(int i=0 ; i<=size-1 ; i++)
		cout<<arr[i]<<" ";

	cout<<endl;
}

int main()
{
	int arr[] = {11,3,8,6,1,7,10,4,9,2,5};
	int n = sizeof(arr)/sizeof(arr[0]);

	printArray(arr,n);
	int inversions = 0;
	QuickSort(arr,0,n-1,&inversions);
	printArray(arr,n);
	cout<<"\n The no. of the Inversions in the array is : "<<inversions<<endl;

	cin.get();
	cin.get();
	return 0;
}
