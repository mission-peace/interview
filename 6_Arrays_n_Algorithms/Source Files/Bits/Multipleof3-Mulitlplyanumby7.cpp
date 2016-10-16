#include<iostream>
using namespace std;

bool ismultipleof3(int n)
{
	int oddbits = 0;
	int evnbits = 0;

	for(int i=0 ; n ; i++)
	{
		if(i&1==0)
			evnbits += n&1;
		if(i&1==1)
			oddbits += n&1;
		n = n>>1;
	}

	int diff = abs(oddbits-evnbits);

	return diff==0 || diff%3==0 ;
}

int Multiplyby7(int x)
{
	return ((x<<3) - x);
}

int main()
{
	int a = 69;
	int b = 73;

	cout<<a<<" x 7 = "<<Multiplyby7(a)<<endl;
	cout<<b<<" x 7 = "<<Multiplyby7(b)<<endl;

	ismultipleof3(a) ? cout<<a<<" is a multiple of 3\n" : cout<<a<<" is NOT a multiple of 3\n";
	ismultipleof3(b) ? cout<<b<<" is a multiple of 3\n" : cout<<b<<" is NOT a multiple of 3\n";



	cin.get();
	return 0;
}