#include<iostream>
using namespace std;

void multiply(int F[2][2],int M[2][2])
{
	int x = F[0][0]*M[0][0] + F[0][1]*M[1][0];
	int y = F[0][0]*M[0][1] + F[0][1]*M[1][1];
	int z = F[1][0]*M[0][0] + F[1][1]*M[1][0];
	int a = F[1][0]*M[0][1] + F[1][1]*M[1][1];

	F[0][0] = x;
	F[0][1] = y;
	F[1][0] = z;
	F[1][1] = a;
}

void pow(int F[2][2],int n)
{
	if(n==0 || n==1)
		return;
	else
	{
		pow(F,n/2);

		if(n&1==0)
			multiply(F,F);
		else
		{
			int M[2][2] = {{1,1},{1,0}};
			multiply(F,F);
			multiply(F,M);
		}
		
	}
}


int fib(int a)
{
	int F[2][2] = {{1,1},{1,0}};
	pow(F,a-1);
	return F[0][0];
}

int main()
{
	int a=0;
	cin>>a;
	cout<<endl<<fib(a);

	cin.get();
	cin.get();
	return 0;
}