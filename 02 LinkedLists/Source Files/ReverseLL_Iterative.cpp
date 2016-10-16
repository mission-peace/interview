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

void printReverseLL(struct node *head)
{
	if(head == NULL)
		return;
	else
	{
		printReverseLL(head->next);
		cout<<head->data<<" ";
	}
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

void ReverseLL(struct node **head)
{
	struct node *prev = NULL;
	struct node *cur = *head;
	struct node *upnext;
	
	if(*head == NULL)
	{
		cout<<"\nTHe LL is empty!\n";
		return;
	}

	while(cur != NULL)
	{
		upnext = cur->next;
		cur->next = prev;
		prev = cur;
		cur = upnext;
	}
	*head = prev;

}


void main()
{
	int num[]={1,2,3,4};

	struct node *LL=NULL;	
	
	for(int i=sizeof(num)/sizeof(num[0])-1; i>=0 ; i--)
		Push(&LL,num[i]);
	
	printLL(LL);
	cout<<endl;
	printReverseLL(LL);
	cout<<endl;

	ReverseLL(&LL);
	printLL(LL);
	cout<<endl;
	printReverseLL(LL);
	cout<<endl;

	cin.get();
}