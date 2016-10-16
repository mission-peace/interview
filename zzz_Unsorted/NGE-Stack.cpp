#include<iostream>
#include<stack>
using namespace std;

void findNGEs(int arr[],int n)
{
	stack<int> S;
	S.push(arr[0]);

	for(int i=1 ; i<=n-1 ; i++)
	{
		while( !S.empty() && arr[i] > S.top())
		{
			cout<<"\n The NGE of "<<S.top()<<" is : "<<arr[i]<<endl;
			S.pop();
		}
		S.push(arr[i]);
	}

	while(!S.empty())
	{
		cout<<"\n There is no NGE for "<<S.top()<<" and hence : -1"<<endl;
		S.pop();
	}
}

int main()
{
	int arr[] = {11, 13, 21, 3};
	int n = sizeof(arr)/sizeof(arr[0]);

	findNGEs(arr,n);

	cin.get();
	cin.get();
	return 0;
}