#include<iostream>
#include<time.h>
using namespace std;

void printArray(int *arr,int n)
{
	cout<<endl;
	for(int i=0 ; i<=n-1 ; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

void Swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void shuffleArray(int *arr,int n)
{
	srand(time(NULL));

	for(int i=n-1 ; i>=0 ; i--)
	{
		int randomindex = rand()%52;
		Swap(&arr[randomindex],&arr[i]);
	}
}

int main()
{
	int n = 52;
	int *arr = new int[52];

	for(int i=0 ; i<=51 ; i++)
		arr[i] = i+1;

	printArray(arr,n);
	shuffleArray(arr,n);
	printArray(arr,n);

	cin.get();
	cin.get();
	return 0;
}