#include<iostream>
using namespace std;


void Find2eleofOddOccur(int *arr,int n)
{
	int xor1 = arr[0];

	for(int i=1 ; i<=n-1 ; i++)
		xor1 ^= arr[i];

	int LSB = xor1 & -xor1;

	int x=0,y=0;

	for(int i=0 ; i<=n-1 ; i++)
	{
		if(arr[i]&LSB)
			x ^=arr[i];
		else
			y ^=arr[i];
	}
	int i = 0;
	cout<<-i<<endl;
	cout<<"The elements having Odd Occrances are : "<<x<<" and "<<y<<endl;
}

int main()
{

	int arr[] = {12, 23, 34, 12, 12, 23, 12, 45};
	int n = sizeof(arr)/sizeof(arr[0]);

	Find2eleofOddOccur(arr,n);

	cin.get();
	cin.get();
	return 0;
}