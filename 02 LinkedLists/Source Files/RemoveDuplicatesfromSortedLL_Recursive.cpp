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

struct node *Push(struct node **head,int num)
{
	struct node *temp = CreateNode(num);
	
	if(temp!=NULL)
		temp->next = *head;

	*head = temp;
	return *head;
}

void printLL(struct node *temp)
{
	if(temp==NULL)
	{
		cout<<"\nThe LL is empty!\n";
		return;
	}

	cout<<endl;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

struct node *RemoveDuplicatesfromSortedLL(struct node *temp)
{
	struct node *head = temp;
	if(head==NULL)
		return NULL;

	if(head->next!=NULL)
	{
		struct node *delnode = head->next;

		if(head->data != delnode->data)
			RemoveDuplicatesfromSortedLL(head->next);
		else
		{
			if(delnode->next!=NULL)
			{
				head->next = delnode->next;
				delete delnode;
			}
			else
				head->next = NULL;
			RemoveDuplicatesfromSortedLL(head);
		}	
		
	}
	return head;
}

void main()
{
	int num[]={1,2,3,4,5};

	struct node *LL1 = NULL;
	for(int i=(sizeof(num)/sizeof(num[0]))-1 ; i>=0 ; i--)
		Push(&LL1,num[i]);

	printLL(LL1);
	RemoveDuplicatesfromSortedLL(LL1);
	printLL(LL1);


	cin.get();
}