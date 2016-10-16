#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

struct node *CreateNode(int x)
{
	struct node *temp = new struct node();
	temp->data = x;
	temp->next = NULL;
	return temp;
}

struct node *Push(struct node **head,int num)
{
	struct node *temp = CreateNode(num);
	
	if(! (*head)==NULL)
	{
		temp->next = *head;
		*head = temp;
	}
	else
		*head = temp;

	return *head;
}

void printLL(struct node *head)
{
	if(head==NULL)
	{
		cout<<"\n EMPTY LL!\n";
		return;
	}
	cout<<endl;
	while(head != NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

struct node *AlternateLLSplit(struct node *head1,struct node **head2)
{
	if(head1==NULL)
		return NULL;

	struct node *delnode = head1->next;

	if(delnode==NULL)
		return NULL;

	head1->next = delnode->next;

	Push(head2,delnode->data);
	head2 = &((*head2)->next);

	delete delnode;
	AlternateLLSplit(head1->next,head2);
}

void main()
{
	int num[]={1,2,1,2};

	struct node *LL1 = NULL;
	for(int i=(sizeof(num)/sizeof(num[0]))-1 ; i>=0 ; i--)
		Push(&LL1,num[i]);

	struct node *LL2 = NULL;
	struct node **lastref = &LL2;

	printLL(LL1);
	AlternateLLSplit(LL1,lastref);
	printLL(LL1);
	printLL(LL2);

	cin.get();
}