#include<iostream>
using namespace std;

void Swap(int *a,int *b)
{
	int temp = *a;
	*a=*b;
	*b = temp;

}

void SelectionSort(int arr[],int cur,int next,int e)
{
	if(next>e)
		return;

	if(arr[cur] > arr[next])
		Swap(&arr[cur],&arr[next]);
	SelectionSort(arr,cur,next+1,e);

	SelectionSort(arr,cur+1,next+1,e);
}

void printArray(int arr[],int len)
{
	cout<<endl;
	for(int i=0 ; i<=len-1 ; i++)
		cout<<arr[i]<<" ";
}

void main()
{
	int arr[] = {13}; //{13,6,23,15,8,12,3};
	int len = sizeof(arr)/sizeof(arr[0]);

	printArray(arr,len);
	SelectionSort(arr,0,1,len-1);
	printArray(arr,len);

	cin.get();
}