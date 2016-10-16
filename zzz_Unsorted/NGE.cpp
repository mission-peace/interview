#include<iostream>
#include<stack>
using namespace std;

void NGE(int arr[],int n)
{
	stack<int> S;
	S.push(arr[n-1]);
	cout<<S.top()<<" has NGE : -1 "<<endl;

	for(int i=n-2 ; i>=0 ; i--)
	{
		while(!S.empty() && arr[i] > S.top())
			S.pop();
		cout<<arr[i]<<" has NGE : "<<S.top()<<endl;
		S.push(arr[i]);
	}

	/*
	while(!S.empty())
	{
		cout<<S.top()<<" has NGE : -1 "<<endl;
		S.pop();
	} */
}

int main()
{
	int arr[] = {3,2,1,25};
	int n = sizeof(arr)/sizeof(arr[0]);

	stack<int> S;
	for(int i=n-1 ; i>=0 ; i--)
		S.push(arr[i]);

	NGE(arr,n);

	cin.get();
	cin.get();
	return 0;

}