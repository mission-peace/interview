#include<iostream>
using namespace std;

void Swap(int *a,int *b)
{
	int temp = *a;
	*a=*b;
	*b = temp;

}

void printArray(int arr[],int len)
{
	cout<<endl;
	for(int i=0 ; i<=len-1 ; i++)
		cout<<arr[i]<<" ";
}

void mergeArray(int arr[],int s,int m,int e)
{
	int h1 = m-s+1;
	int h2 = e-m;

	int *half1 = new int[h1];
	int *half2 = new int[h2];

	for(int i=0 ; i<= h1-1 ; i++)
		half1[i] = arr[s+i];

	for(int i=0 ; i <= h2-1 ; i++ )
		half2[i] = arr[m+1+i];

	int i=0;
	int j=0;
	int k=s;
	for( ; i < h1 && j < h2 ; )
	{
		if(half1[i] <= half2[j])
			arr[k++] = half1[i++];
		else
			arr[k++] = half2[j++];
	}

	while(i < h1)
		arr[k++] = half1[i++];

	while(j < h2)
		arr[k++] = half2[j++];

}

int getSmallest(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}

void MergeSort(int arr[],int n)
{

	int cursize;
	int leftend;

	for(cursize=1 ; cursize<= n-1 ; cursize = 2*cursize)
	{
		for(leftend=0 ; leftend<n-1 ; leftend+=2*cursize)
		{
			int mid = leftend +cursize -1;
			int rightend = getSmallest(leftend+2*cursize-1,n-1);
			
			mergeArray(arr,leftend,mid,rightend);
		}
	}

}


void main()
{
	int arr[] = {13,6,23,15,8,12,3,28,2,16,15};
	int len = sizeof(arr)/sizeof(arr[0]);

	printArray(arr,len);
	MergeSort(arr,len);
	printArray(arr,len);


	cin.get();
}