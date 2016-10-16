#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;

template<class DATATYPE> void printArray(DATATYPE *a,int len)
{
	cout<<endl;
	for( int i=0 ; i <= len - 1 ; i++ )
		cout<<a[i]<<" ";
}


void swap(int *c,int *d)
{
	int temp = *c;
	*c=*d;
	*d=temp;
	return;
}

int Partition(int x[],int s,int e)
{
	int i=s, pivot=x[e];

	for(int j=s ; j <= e-1 ; j++ )
	{
		if (x[j] <= pivot)
		{
			swap(&x[i],&x[j]);
			i++;
		}
	}
	
	swap(&x[i],&x[e]);  // Place the pivot element at the appropriate place
	return i;			// return the pivot's index
}

void QuickSort(int arr[],int si,int ei)
{
	int pi;

	if(si < ei)
	{
		pi = Partition(arr,si,ei);
		QuickSort(arr,si,pi-1);
		QuickSort(arr,pi+1,ei);
	}
}

void main()
{
	int a[10] = {-6,9,10,-13,-11,8,17,-13,10,-13};
	int sumtofind = 2;

	int si = 0;
	int ei = (sizeof(a)/sizeof(a[0])) - 1;
	QuickSort(a,si,ei);

	printArray(a,ei+1);
	getch();

}