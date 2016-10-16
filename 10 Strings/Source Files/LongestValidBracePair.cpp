#include<iostream>
#include<stack>
using namespace std;

char getMatch(char x)
{
	return (x=='(' ? ')' : '(') ;
}

int LongestValidBracePair(char *str)
{
	int tempcount=0;
	int longestcount=0;
	bool isContinuous = false;
	stack<char> S;

	while(*str)
	{
		if(*str=='(')
		{
			S.push(*str);
			str++;
			continue;
		}
		else if(*str==')')
		{
			while(!S.empty() && S.top()!=getMatch(*str))
			{
				S.pop();
			}
			if(!S.empty())
			{
				if(S.top()==getMatch(*str))
					tempcount++;
				S.pop();
			}
		}
		str++;
	}
	return 2*tempcount;
}

int main()
{
	char str[] = "((()";

	cout<<"The lenght of longest valid brace pair is : "<<LongestValidBracePair(str);
	cin.get();
	cin.get();
	return 0;
}