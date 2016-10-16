#include<iostream>
using namespace std;

int *memo;
int Min(int a,int b)
{
	if(a <= b)
		return a;
	else
		return b;
}

int minto1(int i)
{
	if(i==1)
		return 0;

	if(memo[i] != -1)
		return memo[i];

	int r = 1+ minto1(i-1);

	if(i%2 ==0)
	{
		r = Min(r,1+minto1(i/2));
	}
	if(i%3 ==0)
	{
		r = Min(r,1+minto1(i/3));
	}

	memo[i]=r;

	return r;

}

void main()
{
	cout<<"Enter the no. : \n";
	int i;
	cin>>i;
	
	memo = new int[i+1];

	for(int n=i ; n>=0 ; n--)
	{
		memo[n] = -1;
	}

	cout<<"Minimum steps to 1 is : "<<minto1(i)<<endl;

	for(int n=i+1 ; n>=0 ; n--)
	{
		cout<<n<<" -> "<<memo[n]<<endl;
	}

	cin.get();
	cin.get();
}