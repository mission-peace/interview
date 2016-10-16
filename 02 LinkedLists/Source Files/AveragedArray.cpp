/*	TimeCom		= n  
	SpaceCom	= 1  (int sum)
*/

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

void main()
{
	int arr[] = { 12,8,67,98,34,56,23,60,96};
	float *avr = new float[sizeof(arr)/sizeof(arr[0])];
	int sum=0;

	for(int i=0 ; i <= (sizeof(arr)/sizeof(arr[0])-1) ; i++ )
	{
		sum +=arr[i];
		avr[i]=((float)sum/(i+1));
	}

	printArray(arr,sizeof(arr)/sizeof(arr[0]));
	printArray(avr,sizeof(arr)/sizeof(arr[0]));

	getch();
}