#include<iostream>
using namespace std;

int combination(int n,int m)
{
	if(n<=1 || m<=1)
		return 0;
	else if((n==0 && m==0) || (n==1 && m==0) || (n==1 && m==1))
		return 1;

	return combination(n-1,m-1) + combination(n-1,m) ;

}
void main()
{
	cout<<"Enter n and m to calculate nCm : \n";
	int n, m;
	cin>>n;
	cin>>m;

	cout<<combination(n,m);

	cin.get();
	cin.get();
}