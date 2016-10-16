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

void SortedInsert(stack<int> &S,int x)
{
	if(S.empty())
		S.push(x);
	else
	{
		int temp = S.top();
		S.pop();
		SortedInsert(S,x);
		S.push(temp);
	}

}

void reverseStack(stack<int> &S)
{
	if(!S.empty())
	{	
		int x = S.top();
		S.pop();		
		reverseStack(S);
		SortedInsert(S,x);
	}
}

void main()
{
	int arr[5] = {1,2,4,3,5};

	stack<int> S;

	for(int i=4 ; i>=0 ; i--)
		S.push(arr[i]);

	printStack(S);

	for(int i=4 ; i>=0 ; i--)
		S.push(arr[i]);

	reverseStack(S);
	cout<<endl<<"The stack is (reversed) : ";
	printStack(S);

	cin.get();
	cin.get();
}