#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

void printLL(struct node *head)
{
	cout<<endl;
	while(head != NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

struct node *CreateNode(int num)
{
	struct node *temp = new struct node();
	temp->data = num;
	temp->next = NULL;
	return temp;
}

struct node *Push(struct node **head, int a)
{
	struct node *temp = CreateNode(a);
	
	if(*head != NULL)
	{
		temp->next = *head;
		*head = temp;
	}
	else
		*head = temp;

	return *head;
}

void ReverseLL(struct node **headref)
{
	if(*headref==NULL)
		return;

	struct node *first=*headref;
	struct node *rest=first->next;

	if(rest==NULL)
		return;

	ReverseLL(&rest);
	first->next->next = first;
	first->next = NULL;

	*headref = rest;

}


void main()
{
	int num[]={1,2,3,4,5,6};

	struct node *LL=NULL;		
	for(int i=sizeof(num)/sizeof(num[0])-1; i>=0 ; i--)
		Push(&LL,num[i]);

	printLL(LL);
	ReverseLL(&LL);
	printLL(LL);

	cin.get();
}