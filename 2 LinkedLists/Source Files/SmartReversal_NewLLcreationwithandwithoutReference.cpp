#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

void printLL(struct node *head)
{
	if (head==NULL)
		return;
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

void smartReverseLL(struct node **headref,struct node **newLL)
{
	
	if(*headref==NULL)
		return;
	
	Push(newLL,(*headref)->data);
	smartReverseLL(&(*headref)->next,newLL);
	return;
}


void main()
{
	int num[]={1,2,3,4,5,6};

	struct node *LL=NULL;		
	for(int i=sizeof(num)/sizeof(num[0])-1; i>=0 ; i--)
		Push(&LL,num[i]);
	struct node *newLL=NULL;
	printLL(LL);
	smartReverseLL(&LL,&newLL);
	printLL(newLL);

	cin.get();
}