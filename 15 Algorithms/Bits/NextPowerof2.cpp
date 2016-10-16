#include<iostream>
using namespace std;

void Nextpowof2(unsigned int x)
{
	unsigned int res = 1;

	while(res < x)
		res= res<<1;

	cout<<"Next power of 2 for "<<x<<" is "<<res;
}

int main()
{
	unsigned int x = 0;
	cin>>x;

	Nextpowof2(x);

	cin.get();
	cin.get();
	return 0;
}