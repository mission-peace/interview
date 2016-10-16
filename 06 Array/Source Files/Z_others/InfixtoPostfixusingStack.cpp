#include<iostream>
#include<stack>
using namespace std;

char poEXP[100];

int precedence(char c)
{
	switch(c)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '^':
		return 3;
	}
	return -1;
}

bool isOperand(char x)
{
	return ((x>= 'a' && x<='z') || (x>='A' && x<='Z'));
}

void InfixtoPostfix(char *exp)
{
	stack<char> S;
	int i=0;
	int k=-1;
	for( ; exp[i] ; i++)
	{
		if(isOperand(exp[i]))
		{
			cout<<exp[i];
			poEXP[++k] = exp[i];
			continue;
		}

		else if(exp[i]=='(')
			S.push(exp[i]);
		else if(exp[i]==')')
		{
			while(S.top()!='(')
			{
				//if(S.top()!='(' && S.top()!=')')
				cout<<S.top();
				poEXP[++k] = S.top();
				S.pop();
				if(S.empty())
					break;
			}
			if(!S.empty() && S.top()=='(')
				S.pop();
		}

		else
		{
			while(!S.empty() && precedence(exp[i]) <= precedence(S.top()))
			{
				//if(S.top()!='(' && S.top()!=')')
				cout<<S.top();
				poEXP[++k] = S.top();
				S.pop();
				if(S.empty())
					break;
			}
			S.push(exp[i]);
		}

	}

	while(!S.empty())
	{
		//if(S.top()!='(' && S.top()!=')')
		cout<<S.top();
		poEXP[++k] = S.top();
		S.pop();

	}

	poEXP[++k] = '\0';
}

bool isDigit(char c)
{
	return (c>='0' && c<='9');
}

void evaluatePostExp()
{
	char *EXP = "231*+9-";

	stack<int> S;
	int i=0;

	for( ; EXP[i] ; i++)
	{
		if(isDigit(EXP[i]))
			S.push(EXP[i]-'0');
		else
		{
			int val1 = S.top();
			S.pop();
			int val2 = S.top();
			S.pop();

			switch(EXP[i])
			{
			case '+' :
				S.push(val1+val2);
				break;

			case '-' :
				S.push(val2-val1);
				break;

			case '*' :
				S.push(val1*val2);
				break;

			case '/' :
				S.push(val2/val1);
				break;

			}


		}
	}

	cout<<"\n\nThe Postfix expression evaluation result is  : "<<S.top();

}

int main()
{
	char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
	InfixtoPostfix(exp);
	evaluatePostExp();
	cin.get();
	return 0;
}