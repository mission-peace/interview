#include<iostream>
#include<stack>
using namespace std;

void printSpan(int stock[],int n)
{
	stack<int> S;
	int hi;

	S.push(0);
	cout<<"1"<<" ";	//	Span for the day 1 of Stock is always 1

	for(int i=1 ; i<=n-1 ; i++)
	{
		while(!S.empty() && stock[S.top()] <= stock[i])
			S.pop();

		S.empty() ? hi = -1 : hi = S.top();
		cout<<i-hi<<" ";

		S.push(i);
	}


}

int main()
{
	int stock[] = {10, 4, 5, 90, 120, 80};
	int n = sizeof(stock)/sizeof(stock[0]);

	printSpan(stock,n);

	cin.get();
	cin.get();
	return 0;
}