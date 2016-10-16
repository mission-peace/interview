#include<iostream>
using namespace std;

struct node
{
	struct node *next;
	int data;
};

void printLL(struct node *head)
{
	cout<<endl;
	while(head != NULL)
	{
		cout<<head->data<<" ";
		head= head->next;
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

struct node *CreateNode(int x)
{
	struct node *temp = new struct node();
	temp->data = x;
	temp->next = NULL;
	return temp;
}

struct node *InsertatBegin(struct node **head, int num)
{
	struct node *temp;

	if(*head == NULL)
	{
		temp = CreateNode(num);
		*head = temp;
	}

	else
	{
		temp = CreateNode(num);
		temp->next = *head;
		*head = temp;
	}
	return temp;
}

struct node *AddLists(struct node *LL1, struct node *LL2)
{
	struct node *sumLL=NULL,*temp,*prev=NULL;
	int sum=0,c=0;

	while(LL1 != NULL || LL2 != NULL)
	{
		sum = (c ? c : 0) + (LL1 ? LL1->data : 0 ) + (LL2 ? LL2->data : 0 );
		c = (sum >= 10 ? 1 : 0);
		temp = CreateNode(sum%10);

		if(prev == NULL)
			sumLL = temp;
		else
			prev->next = temp;
		prev = temp;

		if(LL1)
			LL1 = LL1->next;
		if(LL2)
			LL2 = LL2->next;
	}

	if(c)
	{
		temp = CreateNode(c);
		prev->next = temp;
		prev = temp;
	}

	return sumLL;
}

void main()
{
	cout << "In this Linked List Addition, the HEAD of Linked List is the LSB!";

	int num1[] = {6,8,9,0};
	int num2[] = {0,8,9};

	struct node *LL1head = NULL;

	// number is 6890 and LSB is head
	for(int i=0 ; i<=(sizeof(num1)/sizeof(num1[0]))-1 ; i++)
		InsertatBegin(&LL1head,num1[i]);


	struct node *LL2head = NULL;

	// number is 089 and LSB is head
	for(int i=0 ; i<=(sizeof(num2)/sizeof(num2[0]))-1 ; i++)
		InsertatBegin(&LL2head,num2[i]);
	
	printLL(LL1head);
	printLL(LL2head);

	/*
	cout<<endl;
	cout<<"Size of LL1 = "<<sizeofLL(LL1head);
	cout<<"Size of LL2 = "<<sizeofLL(LL2head);
	cout<<endl; */

	printLL(AddLists(LL1head,LL2head));
	cin.get();
}

