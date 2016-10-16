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

struct node *getAddress(struct node *head,int a)
{

	while(head != NULL)
	{
		if(head->data == a)
			return head;
		head = head->next;
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


void MedianofLL_method1(struct node *slow)
{
	if(!slow)
	{
		cout<<"The LL is empty";
		return;
	}	
	struct node *fast=slow;

	while(fast!=NULL && fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	cout<<"\nThe Median of LL using method 1 : "<<slow->data<<endl;
}

void MedianofLL_method2(struct node *slow)
{
	if(!slow)
	{
		cout<<"The LL is empty";
		return;
	}	
	struct node *fast=slow->next;

	while(fast!=NULL && fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	cout<<"\nThe Median of LL using method 2 : "<<slow->data<<endl;
}



void main()
{
	int num1[]={1,2,3,4,5};

	struct node *LL1=NULL;	
	for(int i=sizeof(num1)/sizeof(num1[0])-1; i>=0 ; i--)
		Push(&LL1,num1[i]);

	int num2[]={1,2,3,4,5,6};

	struct node *LL2=NULL;	
	for(int i=sizeof(num2)/sizeof(num2[0])-1; i>=0 ; i--)
		Push(&LL2,num2[i]);

	printLL(LL1);
	MedianofLL_method1(LL1);
	MedianofLL_method2(LL1);

	printLL(LL2);
	MedianofLL_method1(LL2);
	MedianofLL_method2(LL2);

	cin.get();
}