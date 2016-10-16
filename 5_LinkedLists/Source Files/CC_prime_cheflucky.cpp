#include<iostream>
#include<math.h>
using namespace std;
 
bool isChefLucky(int N)
{
 	if(N%2==0)
		return false;
	if( (N-1)%6 != 0 && (N+1)%6 !=0)
		return false;
 
	float limit = sqrt(float(N));
	for(int i=2 ; i<= limit ; i++)
	{
	  if(N%i==0)
  		return false;
	}
 
	return true;
}
 
int main()
{
	int N;
	cin>>N;
 
	int x;
	while(N--)
	{
		cin>>x;
		isChefLucky(x) ? cout<<"LUCKY NUMBER\n" : cout<<"Sorry\n" ;
	} 
cin.get();
cin.get();
return 0;
}