#include<iostream>
using namespace std;

template<class T>void printArray(T *arr,int len)
{
	cout<<endl;
	for(int i=0;i<=len-1;i++)
		cout<<" "<<arr[i];
	cout<<endl;
}

void swap(int *p,int *q)
{
	int temp=*p;
	*p=*q;
	*q=temp;
}

int Partition(int *x,int s, int e,int *inverts)
{
	int i=s, pivot = x[e];
	cout<<"\n The pivot is : "<<pivot;

	for(int j=s ; j<=e-1 ; j++)
	{
		if(x[j] <= pivot)
		{
			swap(&x[i++],&x[j]);
			(*inverts)++;
		}
	}
	if(x[i] > x[e])
		(*inverts)++;
	swap(&x[i],&x[e]);
	return i;

}

void QuickSort(int *arr,int si,int ei,int *inverts)
{
	int pi=0;

	if(ei > si)
	{
		pi = Partition(arr,si,ei,inverts);
		QuickSort(arr,si,pi-1,inverts);
		QuickSort(arr,pi+1,ei,inverts);
	}
}


void main()
{
	int a[11]={11,3,8,6,1,7,10,4,9,2,5};
	int inversions = 0;
	QuickSort(a,0,(sizeof(a)/sizeof(a[0]))-1,&inversions);	
	printArray(a,(sizeof(a)/sizeof(a[0])));
	cout<<"\n The no. of inversions are : "<<inversions<<endl;

	cin.get();
}