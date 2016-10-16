#include<iostream>
#include<stack>

using namespace std;

void calculateStockSpan(int arr[],int n)
{
	int *Span = new int[n];
	stack<int> S;
	S.push(0);
	Span[0] = 1;

	for(int i=1 ; i<= n-1 ; i++)
	{
		while(!S.empty() && arr[S.top()] <= arr[i])
			S.pop();

		Span[i] = (S.empty()) ? i+1 : i-S.top();

		S.push(i);
	}

	cout<<"The Stock Span for n days are : \n";
	for(int i=0 ; i<=n-1 ; i++)
		cout<<Span[i]<<" ";
}

int main()
{
	int arr[] = {100,80,60,70,60,75,85};
	int n = sizeof(arr)/sizeof(arr[0]);

	calculateStockSpan(arr,n);

	cin.get();
	return 0;
}