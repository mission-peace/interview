#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void arrayprint(int arr[], int arrlen)
{
	cout<<endl;
	for(int i=0; i<= arrlen - 1 ; i++ )
		cout<<arr[i]<<" ";
}

void main()
{
	int arr[] = {2,6,10,8,9,4,13,3};

	for(int j=1 ; j <= (sizeof(arr)/sizeof(arr[0])) - 1 ; j++)
	{
		for(int i=j-1 ; i>=0 ; i--)
		{
			if (arr[i] > arr[j])
			{
				swap(&arr[i],&arr[j]);
				j--;
			}
			else
				break;
		}
	}
	arrayprint(arr,(sizeof(arr)/sizeof(arr[0])));
	cout<<endl;
	for(int i=0; i<= (sizeof(arr)/sizeof(arr[0])) - 1 ; i++ )
		cout<<arr[i]<<" ";

	getch();
}