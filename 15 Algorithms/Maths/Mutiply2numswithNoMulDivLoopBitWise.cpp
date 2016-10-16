#include<iostream>
using namespace std;

long multiply(long a,long b)
{
	return b==1 ? a : a+multiply(a,b-1) ;
}

long pow(long a,long b)
{
	return b ? multiply(a,pow(a,b-1)) : 1 ;
}

int main()
{
	long a = 5;
	long b = 6;

	cout<<a<<" * "<<b<<" = "<<multiply(a,b);
	cout<<endl;
	cout<<a<<" ^ "<<b<<"= "<<pow(a,b);

	cin.get();
	return 0;
}