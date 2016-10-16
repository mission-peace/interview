#include<iostream>
#include<stack>
using namespace std;

void SortedInsert(stack<int> &S,int x,bool ascen=true)
{
	if(!ascen && (S.empty() || x > S.top()) )
		S.push(x);
	else if(ascen && (S.empty() || x < S.top()))
		S.push(x);
	else
	{
		int temp = S.top();
		S.pop();
		SortedInsert(S,x,ascen);
		S.push(temp);
	}

}

void StackSort(stack<int> &S,bool ascen=true)
{
	if(!S.empty())
	{	
		int x = S.top();
		S.pop();		
		StackSort(S,ascen);
		SortedInsert(S,x,ascen);
	}
}

void main()
{
	int arr[5] = {1,2,4,3,5};

	stack<int> S;

	for(int i=4 ; i>=0 ; i--)
		S.push(arr[i]);

	while(!S.empty())
	{
		cout<<S.top()<<" ";
		S.pop();
	}

	for(int i=4 ; i>=0 ; i--)
		S.push(arr[i]);

	StackSort(S,false);
	cout<<endl<<"The sorted stack is (descending) : ";
	while(!S.empty())
	{
		cout<<S.top()<<" ";
		S.pop();
	}

	for(int i=4 ; i>=0 ; i--)
		S.push(arr[i]);

	StackSort(S,true);
	cout<<endl<<"The sorted stack is (ascending) : ";
	while(!S.empty())
	{
		cout<<S.top()<<" ";
		S.pop();
	}
	
	cin.get();
	cin.get();
}