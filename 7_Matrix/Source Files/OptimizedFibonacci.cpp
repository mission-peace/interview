#include<iostream>
using namespace std;


void multiply(int F[][2],int M[][2])
{

	int a = F[0][0]*M[0][0]+F[0][1]*M[1][0];
	int b = F[0][0]*M[0][1]+F[0][1]*M[1][1];
	int c = F[1][0]*M[0][0]+F[1][1]*M[1][0];
	int d = F[1][0]*M[0][1]+F[1][1]*M[1][1];

	F[0][0] = a;
	F[0][1] = b;
	F[1][0] = c;
	F[1][1] = d;
}

void pow(int Fib[][2],int n)
{
	if(n==0 || n==1)
		return;

	if(n%2==0)
	{
		pow(Fib,n/2);
		multiply(Fib,Fib);
	}
	else
	{
		pow(Fib,n/2);
		int M[][2] = {{1,1},
					  {1,0}};	
		multiply(Fib,Fib);
		multiply(Fib,M);
	}
}

int getFibo(int Fib[][2],int n)
{
	pow(Fib,n);
	return Fib[0][0];
}

int main()
{

	int N = 0;
	for(int i= 2 ; i<=12; i++)
	{
		int Fib[][2] = {{1,1},
					    {1,0}};
		cout<<i-2<<"th Fibonacci is : "<<getFibo(Fib,i-2)<<endl;
	}

	cin.get();
	cin.get();
	return 0;
}