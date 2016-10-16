#include<iostream>
#include<stack>
using namespace std;

void printStack(stack<int> &S)
{
	while(!S.empty())
	{
		cout<<S.top()<<" ";
		S.pop();
	}
}

void InsertatBottom(stack<int> &S,int temp)
{
	if(S.empty())
		S.push(temp);
	else
	{
		int temp2 = S.top();
		S.pop();
		InsertatBottom(S,temp);
		S.push(temp2);
	}

}

void reverseStack(stack<int> &S)
{
	if(S.empty())
		return;
	
	int temp = S.top();
	S.pop();
	reverseStack(S);
	InsertatBottom(S,temp);
}

int main()
{
	int arr[] = {1,2,3,4,5};
	int n = sizeof(arr)/sizeof(arr[0]);

	stack<int> S;
	for(int i=n-1 ; i>=0 ; i--)
		S.push(arr[i]);

	reverseStack(S);
	printStack(S);

	cin.get();
	cin.get();
	return 0;

}