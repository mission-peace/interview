#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

struct node *CreateNode(int a)
{
	struct node *temp = new struct node();
	temp->data = a;
	temp->next = NULL;
	return temp;
}

struct node *Push(struct node **head, int num)
{
	struct node *temp = CreateNode(num);

	if(*head!=NULL)
		temp->next = *head;

	*head = temp;
	return *head;
}

void printLL(struct node *head)
{
	if(head==NULL)
	{
		cout<<"\n The LL is empty\n";
		return;
	}

	cout<<endl;
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

void DeleteAlternateNodes(struct node **header)
{
	struct node *head = *header;

	bool headchange = true;
	struct node *newLLhead = *header;

	

	if(head==NULL)
		return;

	struct node *curdelnode;
	while(head!=NULL)
	{
		curdelnode = head;
		(head) = curdelnode->next;

		if(!headchange)
		{
			if(head!=NULL)
			{
				newLLhead->next = head;			
				newLLhead = newLLhead->next;
			}
			else
				newLLhead->next = NULL;
		}

		curdelnode->next=NULL;
		delete curdelnode;

		if(headchange)
		{
			*header = head;
			newLLhead = head;
			headchange = false;
		}

		curdelnode = head;
		if(head!=NULL && (head)->next!=NULL)
			head = (head)->next;
		else
			head = NULL;

	}


}

void main()
{
	int num[]={1,2,3,4,5};

	struct node *LL=NULL;
	for(int i=(sizeof(num)/sizeof(num[0]))-1 ; i>=0 ; i--)
		Push(&LL,num[i]);

	printLL(LL);
	DeleteAlternateNodes(&LL);
	printLL(LL);

	cin.get();
}