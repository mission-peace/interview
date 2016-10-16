#include<iostream>
using namespace std;

int HornetEvaluation(int arr[],int n,int x)
{
    int res = arr[0];
    
    for(int i=1 ; i<=n-1 ; i++)
        res = res*x+arr[i];
        
    return res;
}

int main()
{
	int arr[] = {2, -6, 2, -1};
	int n = sizeof(arr)/sizeof(arr[0]);
	int x = 3;
	
	cout<<HornetEvaluation(arr,n,x);

	cin.get();
	cin.get();
	return 0;
}