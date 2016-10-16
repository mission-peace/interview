#include<iostream>
using namespace std;

void SieveofEratosthenes(int n)
{
	int *primes = new int[n+1]();
	
	for(int i=1 ;i<=n ; i++)
	{
		if(i&1)
			primes[i] = 1;
	}
	primes[1] = 0;
	primes[2] = 1;

	for(int i=3 ; i*i<=n ; i++)
	{
		for(int j=2 ; i*j<=n ; j++)
			primes[i*j] = 0;
	}

	for(int i=1; i<=n ; i++)
	{
		if(primes[i]==1)
			cout<<i<<"\t";
	}
}

int main()
{
	int n = 100;

	SieveofEratosthenes(n);

	cin.get();
	return 0;
}

