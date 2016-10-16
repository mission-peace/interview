#include<iostream>
#include<deque>
using namespace std;

void printDeque(deque<int> &DQ)
{
	cout<<endl;
	deque<int>::iterator i=DQ.begin();
	for( ; i!=DQ.end() ; i++)
		cout<<*i<<" ";
	cout<<endl;
}

void insertatBottom(deque<int> &DQ,int temp)
{
	if(DQ.empty())
		DQ.push_front(temp);
	else
	{
		int top = DQ.front();
		DQ.pop_front();

		insertatBottom(DQ,temp);
		DQ.push_front(top);
	}
}

void reverseStack(deque<int> &DQ)
{
	if(DQ.empty())
		return;
	else
	{
		int top = DQ.front();
		DQ.pop_front();
		reverseStack(DQ);

		insertatBottom(DQ,top);
	}
}

void sortedInsert(deque<int> &DQ,int item)
{
	if(DQ.empty() )
	{
		DQ.push_front(item);
	}
	else
	{
		if(item < DQ.front())
			DQ.push_front(item);
		else
		{
			int temp = DQ.front();
			DQ.pop_front();

			sortedInsert(DQ,item);
			DQ.push_front(temp);
		}
	}
}

void sortStack(deque<int> &DQ)
{
	if(DQ.empty())
		return;
	else
	{
		int top = DQ.front();
		DQ.pop_front();

		sortStack(DQ);
		sortedInsert(DQ,top);
	}
}

int main()
{
	int arr[]= {1,2,3,4,5};
	int n = sizeof(arr)/sizeof(arr[0]);

	deque<int> DQ;
	for(int i=0 ; i<=n-1 ; i++)
		DQ.push_front(arr[i]);

	cout<<"Before Reversal the Stack is : ";
	printDeque(DQ);
	reverseStack(DQ);
	cout<<"After Reversal the Stack is : ";
	printDeque(DQ);

	int arr1[] = {3,7,1,5,6,2,8};
	n = sizeof(arr1)/sizeof(arr1[0]);

	DQ.clear();

	for(int i=0 ; i<=n-1 ; i++)
		DQ.push_front(arr1[i]);

	cout<<"\nBefore sorting the Stack is : ";
	printDeque(DQ);
	sortStack(DQ);
	cout<<"\nAfter sorting the Stack is : ";
	printDeque(DQ);



	cin.get();
	return 0;
}