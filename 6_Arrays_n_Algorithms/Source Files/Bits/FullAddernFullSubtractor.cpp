#include<iostream>
using namespace std;

int FullAdder(int a,int b)
{

	while(b)
	{
		int carry = a&b;

		a = a^b;
		b = carry<<1;
	}
	return a;
}

int FullSubtractor(int a,int b)
{
	while(b)
	{
		int borrow = (~a)&b;

		a = a^b;
		b = borrow<<1;
	}
	return a;
}

int main()
{

	int a=15;
	int b=18;

	cout<<a<<" + "<<b<<" = " <<FullAdder(a,b)<<endl;
	cout<<a<<" - "<<b<<" = " <<FullSubtractor(a,b)<<endl;

	cin.get();
	return 0;
}