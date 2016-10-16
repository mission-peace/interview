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

void StackSortInsertion(stack<int> &S,int temp)
{
	if(S.empty() || temp < S.top())
		S.push(temp);
	else
	{
		int temp2 = S.top();
		S.pop();
		StackSortInsertion(S,temp);
		S.push(temp2);
	}
}

void StackSort(stack<int> &S)
{
	if(S.empty())
		return;

	int temp = S.top();
	S.pop();
	StackSort(S);
	StackSortInsertion(S,temp);
}


int main()
{
	int arr[] = {5,2,4,3,1};
	int n = sizeof(arr)/sizeof(arr[0]);

	stack<int> S;
	for(int i=n-1 ; i>=0 ; i--)
		S.push(arr[i]);

	StackSort(S);
	printStack(S);

	cin.get();
	cin.get();
	return 0;
}