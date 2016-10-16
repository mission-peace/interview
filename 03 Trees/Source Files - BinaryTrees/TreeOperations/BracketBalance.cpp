#include<iostream>
using namespace std;

struct node
{
	char data;
	struct node *next;
};

struct node *newNode(char a)
{
	struct node *temp = new struct node();

	temp->data = a;
	temp->next = NULL;
	return temp;
}

void push(struct node **S,char a)
{
	struct node *temp = newNode(a);

	if(*S!=NULL)
		temp->next = *S;

	*S = temp;
}

void pop(struct node **S)
{
	if(*S==NULL)
	{
		cout<<"Can't Pop. Empty Stack"<<endl;
		return;
	}

	struct node *delnode = *S;

	if((*S)->next==NULL)
	{
		delnode->next = NULL;
		delete(delnode);
		*S = NULL;
	}
	else
	{
		*S= delnode->next;
		delnode->next = NULL;
		delete(delnode);
	}
}

char top(struct node *S)
{
	if(S!=NULL)
		return S->data;
	else
	{
		cout<<"Can't Top..Empty Stack"<<endl;
		return '\0';
	}
}

bool isEmpty(struct node *S)
{
	if(S==NULL)
		return true;
	else
		return false;
}

bool checkBracketBalance(char exp[],int n)
{
	if(n<=0)
		return false;

	struct node *S=NULL;

	for(int i=0 ; i<=n-1 ; i++)
	{
		char temp;
		if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{' || exp[i]=='<')
			push(&S,exp[i]);
		else if(exp[i]==')' || exp[i]==']' || exp[i]=='}' || exp[i]=='>')
		{
			temp = top(S);
			pop(&S);

			if(	(temp=='(' && exp[i]==')') || 
				(temp=='[' && exp[i]==']') ||
				(temp=='{' && exp[i]=='}') ||
				(temp=='<' && exp[i]=='>') ) 
				temp = exp[i];
			else
				return false;

		}

	}

	if(!isEmpty(S))
		return false;

	return true;
}

int main()
{
	char exp[100] = "[()]{}{[()()]<>}";
	int n = 16;

	if(checkBracketBalance(exp,n))
		cout<<"Expression is Bracket Balanced! "<<endl;
	else
		cout<<"Sorry.. Unbalanced...! "<<endl;

	cin.get();
	return 0;
}