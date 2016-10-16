#include<iostream>
#include<stack>
using namespace std;

void findNGE(int arr[],int n)
{
	stack<int > S;
	S.push(arr[0]);
	int top;
	for(int i=1 ; i<=n-1 ; i++)
	{
		if(!S.empty())
		{
			top = S.top();
			S.pop();
		}
		while(top < arr[i])
		{
			cout<<top<<" -> "<<arr[i]<<endl;

			if(S.empty())
				break;

			top = S.top();
			S.pop();
		}
		
		if(top > arr[i])
			S.push(top);
		S.push(arr[i]);
	}


}

int main()
{
	int arr[] = {13, 7, 6, 12, 15};
	int n = sizeof(arr)/sizeof(arr[0]);

	findNGE(arr,n);

	cin.get();
	return 0;
}