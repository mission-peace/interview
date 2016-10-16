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

struct node *delAltNodesRecur(struct node *head)
{
	if(head == NULL)
		return NULL;
	
	struct node *delnode = head->next;

	if(delnode!=NULL)
		head->next = delnode->next;
	else
		return NULL;

	delete delnode;
	delAltNodesRecur(head->next);
}

void main()
{
	int num[]={1,2,3,4,5,6,7};

	struct node *LL1 = NULL;
	for(int i=(sizeof(num)/sizeof(num[0]))-1 ; i>=0 ; i--)
		Push(&LL1,num[i]);

	printLL(LL1);
	delAltNodesRecur(LL1);
	printLL(LL1);

	cin.get();
}