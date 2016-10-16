#include<iostream>
#include<conio.h>

using namespace std;


void swap(int arr[],int i,int j)
{
	int temp;

	temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}

void main()
{
	int nums[]={0,-3,0,0,-2,-1,-9,0,-23,0,-120,0,0};

	int i=(sizeof(nums)/sizeof(nums[0]))-1;
	int j=i;
	for( ; i >= 0 ; i--)
	{
		if(nums[i] != 0)
			nums[j--]=nums[i];
	}

	while(j>=0)
		nums[j--]=0;

	for(int k=0 ; k <= (sizeof(nums)/sizeof(nums[0]))-1 ; k++)
		cout<<nums[k]<<" ";
	//cout<<endl<<"SWAPS: "<<swapcounter;

	getch();
}