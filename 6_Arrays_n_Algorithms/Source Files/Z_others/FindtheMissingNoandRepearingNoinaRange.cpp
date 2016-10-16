#include<iostream>
#define abs(x) x<0 ? x*-1 : x
using namespace std;

void InvertedSignHash(int arr[],int n,int *x,int *y)
{
	int miss=0,repeat=0;

	for(int i=0 ; i<=n-1 ; i++)
	{
		if(arr[abs(arr[i])-1]>0 )
			arr[abs(arr[i])-1] = arr[abs(arr[i])-1]*-1;	
		else
			repeat = abs(arr[i]);
	}

	for(int i=0 ; i<=n-1 ; i++)
	{	
		if(arr[i] >= 1)
		{
			miss = i+1;
			break;
		}
	}

	*x = miss;
	*y = repeat;

}

void XORPunchOut(int arr[],int n,int *a,int *b)
{
	int tempa=0,tempb=0;
	*a = 0;
	*b = 0;

	int rangeXOR = 0;
	for(int i=1 ; i<=n ; i++)
		rangeXOR ^= i;
	int arrXOR = 0;
	for(int i=0 ; i<=n-1 ; i++)
		arrXOR ^=arr[i];

	int missnrepeatXOR = rangeXOR ^ arrXOR;
	int setbit = missnrepeatXOR & ~(missnrepeatXOR-1);

	for(int i=0 ; i<=n-1 ; i++)
	{
		if(arr[i]&setbit)
			tempa ^= arr[i];
		else
			tempb ^= arr[i];
	}

	for(int i=1 ; i<=n ; i++)
	{
		if(i&setbit)
			tempa ^= i;
		else
			tempb ^= i;
	}
	bool founda = false;
	bool foundb = false;

	for(int i=0 ; i<=n-1 ; i++)
	{
		if(arr[i]==tempa)
			founda = true;

		if(arr[i]==tempb)
			foundb = true;
	}

	if(founda)
	{
		*a = tempb;
		*b = tempa;
	}
	else
	{
		*a = tempa;
		*b = tempb;
	}


}



int main()
{
	int arr[] = {2,1,3,6,1,4};
	int n = sizeof(arr)/sizeof(arr[0]);
	int x=0,y=0;
	InvertedSignHash(arr,n,&x,&y);
	cout<<"\nUsing InvertedSign Hash Algorithm, missing = "<<x<<" , repeating = "<<y<<endl;

	int arrays[] = {2,1,3,6,1,4};
	int a=0,b=0;
	XORPunchOut(arrays,n,&a,&b);
	cout<<"\nUsing XOR Punch Out Algorithm, missing = "<<a<<" , repeating = "<<b<<endl;

	cin.get();
	cin.get();
	return 0;
}