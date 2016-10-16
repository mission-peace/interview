#include<iostream>
#include<stack>
using namespace std;

bool isChar(char x)
{
	return (x>='a' && x<='z') || (x>='A' && x<='Z');
}

int Precedof(char x)
{
	switch(x)
	{
		case '+' :
		case '-' :
			return 1;
		case '*' :
		case '/' :
			return 2;
		case '^' :
			return 3;
		default :
			return -1;
	}
}

void Infix2Postfix(char *arr)
{
	stack<char > S;

	cout<<"The Postfix expression is : ";
	for(int i=0 ; i<=strlen(arr)-1 ; i++)
	{
		if(isChar(arr[i]))
		{
			cout<<arr[i];
			continue;
		}
		else
		{
			if(arr[i]=='(')
			{
				S.push(arr[i]);
				continue;
			}
			else if(arr[i]==')')
			{
				while(!S.empty() && S.top()!='(')
				{
					cout<<S.top();
					S.pop();
				}
				S.pop();
			}
			else
			{

				while(!S.empty() && Precedof(arr[i]) <= Precedof(S.top()))
				{
					cout<<S.top();
					S.pop();
				}
				S.push(arr[i]);
			}

		}
	}

	while(!S.empty())
	{
		cout<<S.top();
		S.pop();
	}

}

int main()
{
	char *arr = "a+b*(c^d-e)^(f+g*h)-i";
	int n = strlen(arr);

	cout<<"The  Infix  expression is : "<<arr<<endl;
	Infix2Postfix(arr);

	cin.get();
	cin.get();
	return 0;
}