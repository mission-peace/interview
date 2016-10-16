#include<iostream>
using namespace std;

int *DP;
int Min(int a,int b)
{
	if(a <= b)
		return a;
	else
		return b;
}

int minto1(int i)
{
	DP[1] = 0;

	for(int n=2 ; n<=i ; n++)
	{

	DP[n] = 1 + DP[n-1];

	if(n%2==0) DP[n] = Min(DP[n],1+DP[n/2]);

	if(n%3==0) DP[n] = Min(DP[n],1+DP[n/3]);
	
	}

	return DP[i];

}



void main()
{
	cout<<"Enter the no. : \n";
	int i;
	cin>>i;
	
	DP = new int[i+1];

	for(int n=i ; n>=0 ; n--)
	{
		DP[n] = -1;
	}

	cout<<"Minimum steps to 1 is : "<<minto1(i)<<endl;

	for(int n=i ; n>=0 ; n--)
	{
		cout<<n<<" -> "<<DP[n]<<endl;
	}


	cin.get();
	cin.get();
}