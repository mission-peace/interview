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

void reverseNodes(struct node **refLL3,struct node **refSource)
{
	struct node *temp = (*refSource)->next;
	(*refSource)->next = *refLL3;
	*refLL3 = *refSource;
	*refSource = temp;

}

struct node *ReverseMergeLLs(struct node *LL1,struct node *LL2)
{
	struct node *LL3 = NULL;
	while(LL1!=NULL && LL2!=NULL)
	{
		if(LL1->data <= LL2->data)
			reverseNodes(&LL3,&LL1);
		else if(LL1->data > LL2->data)
			reverseNodes(&LL3,&LL2);
	}

	while(LL1!=NULL)
		reverseNodes(&LL3,&LL1);
	while(LL2!=NULL)
		reverseNodes(&LL3,&LL2);
	return LL3;
}

void main()
{
	int num1[]={1,3,5,7};

	struct node *LL1 = NULL;
	for(int i=(sizeof(num1)/sizeof(num1[0]))-1 ; i>=0 ; i--)
		Push(&LL1,num1[i]);

	int num2[]={2,4,6,8,10};

	struct node *LL2 = NULL;
	for(int i=(sizeof(num2)/sizeof(num2[0]))-1 ; i>=0 ; i--)
		Push(&LL2,num2[i]);

	printLL(LL1);
	printLL(LL2);
	struct node *LL3 = ReverseMergeLLs(LL1,LL2);
	printLL(LL3);

	cin.get();
}