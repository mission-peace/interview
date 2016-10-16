#include<iostream>
#include<stack>
using namespace std;

void NGE(int arr[],int n)
{
	stack<int> S;
	S.push(arr[0]);

	for(int i=1 ; i<=n-1 ; i++)
	{
		if(!S.empty() && arr[i] > S.top())
		{
			cout<<S.top()<<" -> "<<arr[i]<<endl;
			S.pop();
			S.push(arr[i]);
		}
		else
		{
			int top = S.top();
			S.pop();
			S.push(arr[i]);
			S.push(top);

		}

		
	}
	
	int top;
	while(!S.empty())
	{
		top = S.top();
		S.pop();

		if(!S.empty() && top > S.top())
		{
			cout<<S.top()<<" -> "<<top<<endl;
			S.pop();
			S.push(top);
		}

	}


}

int main()
{
	int arr[] = {12,15,11,8,5,16,10,13};
	int n = sizeof(arr)/sizeof(arr[0]);

	NGE(arr,n);

	cin.get();
	return 0;
}