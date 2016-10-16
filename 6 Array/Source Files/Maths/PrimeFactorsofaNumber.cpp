#include<iostream>
using namespace std;

void printPrimeFactors(int N)
{
	int num = N;
	for(int i=2 ; i*i <= N ; i++)
	{
		if(num>0 && num%i==0)
		{
			while(1)
			{
				if(num%i==0)
					num=num/i;
				else 
					break;
				cout<<i<<" ";
			}
		}

	}
	if(num>=2)
		cout<<num;
}

int main()
{
	int num = 11;

	printPrimeFactors(num);

	cin.get();
	cin.get();
	return 0;
}