#include<iostream>
using namespace std;

void main()
{
	int i=10;
	int n=100;

	int count = 0;

	while(i<=n)
	{
		count++;
		i = i+1;
		n= n-1;
		cout<<"\nThe counter is : "<<count;
	}
	count++;

	cout<<"\nFinally the counter is : "<<count;
	cin.get();
}