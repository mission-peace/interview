#include<iostream>
using namespace std;

int RussianPeasant(int num1,int num2)
{
	int res = 0;

	//	 a*2 * b/2 = ab
	//	if a is odd, then  a*2 * (b-1)/2 + a
	//	We see that instead of b-1 we can directly do b>>1 coz 7/2 and 6/2 are same if datatype is int
	//	The trick is to accumulate a while making b smaller and smaller till it reaches 1
	//	If it reaches 1, then whatever is in a is the result because it becomes bigger and bigger

	while(num2!=0)
	{
		if(num2&1)
			res = res + num1;

		num1= num1<<1;
		num2=num2>>1;
	}
	return res;
}

int main()
{
	int num1 = 17;
	int num2 = 32;
	cout<<RussianPeasant(num1,num2);

	cin.get();
	cin.get();
	return 0;
}