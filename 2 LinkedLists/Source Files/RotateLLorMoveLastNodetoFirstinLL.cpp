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

void moveLasttoFirst(struct node **head,int rotate=0)
{
	if(*head == NULL)
	{
		cout<<"\nTHe LL is empty!\n";
		return;
	}
	else if((*head)->next == NULL)
		return;

	while(rotate--)
	{
		struct node *last;
		struct node *temp=*head;

		while(temp != NULL)
		{
			if(temp->next->next == NULL)
			{
				last = temp->next;
				temp->next = NULL;
				last->next = *head;
				*head = last;
			}		
			temp=temp->next;
		}
	}

}


void main()
{
	int num[]={1,2,3,4};

	struct node *LL=NULL;	
	
	for(int i=sizeof(num)/sizeof(num[0])-1; i>=0 ; i--)
		Push(&LL,num[i]);
	
	printLL(LL);
	moveLasttoFirst(&LL,100);
	printLL(LL);

	cin.get();
}