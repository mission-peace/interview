#include<iostream>
using namespace std;

void Swap(int *a,int *b)
{
	if(a!=b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}
}

int segregatePosNeg(int arr[],int n)
{
	int i=0,j=n-1;

	while(i<j)
	{
		if(arr[i] < 0)
		{
			Swap(&arr[i],&arr[j]);
			j--;
		}
		else
			i++;
	}
	return j;
}

int getSmallestPositiveNum(int arr[],int n)
{
	int len = segregatePosNeg(arr,n);

	for(int i=0 ; i<=len-1 ; i++)
	{
		if(abs(arr[i])<len && arr[abs(arr[i])-1] > 0 )
			arr[abs(arr[i])-1] = arr[abs(arr[i])-1]*-1;
	}

	for(int i=0 ; i<=len ; i++)
	{
		if(arr[i] > 0)
			return i+1;
	}
	return len;

}



int main()
{
	int arr[] = {1, 1, 0, -1, -2};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout<<"The smallest +ve number missing is : "<<getSmallestPositiveNum(arr,n);


	cin.get();
	cin.get();
	return 0;
}