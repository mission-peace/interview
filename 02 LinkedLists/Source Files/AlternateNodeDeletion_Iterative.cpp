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
int sizeofLL(struct node *head)
{
	if(head == NULL)
		return 0;
	else
		return 1 + sizeofLL(head->next);
}

struct node *getAddress(struct node *head, int searchnum)
{
	if(head == NULL)
		return NULL;

	while(head!=NULL)
	{
		if(head->data == searchnum)
			return head;

		head=head->next;
	}
	cout<<"\nThe number you mentioned is not present in LL!\n";
}

struct node *deleteAlternateNodes(struct node *temp)
{
	if(temp == NULL)
		return NULL;
	if(temp->next == NULL)
		return temp;

	struct node *head	 = temp;
	struct node *delnode = temp->next;

	while(delnode!=NULL && head!=NULL)
	{
		head->next = delnode->next;
		delete delnode;
		head = head->next;
		if(head!=NULL)
			delnode = head->next;
	}
	//return head;
}



void main()
{
	int num[]={1,2};

	struct node *LL1 = NULL;
	for(int i=(sizeof(num)/sizeof(num[0]))-1 ; i>=0 ; i--)
		Push(&LL1,num[i]);

	printLL(LL1);
	deleteAlternateNodes(LL1);
	printLL(LL1);

	cin.get();
}