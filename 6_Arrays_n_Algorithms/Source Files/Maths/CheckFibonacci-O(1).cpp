// A number is a Fibonacci No. if 5n^2+4 or 5n^2-4 is a Perfect Square

#include<iostream>
using namespace std;

bool isPerfectSquare(int N)
{
	float x = N;
	float y = 1;
	float e = 0.0001;
	while(x-y > e)
	{
		x = (x+y)/2 ;
		y = N/x;
	}

	int tempN = x;
	tempN = tempN*tempN;
	return N==tempN;
}

bool checkFibo(int N)
{
	return isPerfectSquare(5*N*N+4) || isPerfectSquare(5*N*N-4);
}

int main()
{
	int N = ;

	bool isFibo = checkFibo(N);

	isFibo ? cout<<N<<" is a Fibonacci No." : cout<<"It is not a Fibonacci No.";

	cin.get();
	cin.get();
	return 0;
}