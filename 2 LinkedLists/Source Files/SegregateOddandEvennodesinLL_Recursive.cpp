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

void SwapData(int *a,int *b)
{
	if(a==NULL||b==NULL)
		return;
	int temp = *a;
	*a = *b;
	*b = temp;
}

struct node *SegregateOddnEven(struct node **refHead)
{
	struct node *head = *refHead;
	if(head==NULL || head->next==NULL)
		return head;

	struct node *Odd = NULL;
	struct node **refOdd = &Odd;

	struct node *Even = NULL;
	struct node **refEven = &Even;

	if(head->data%2!=0)
	{
		Push(refOdd,head->data);
		refOdd = &(*refOdd)->next;
		Odd->next = SegregateOddnEven(&head->next);
		return Odd;
	}
	else
	{
		Push(refEven,head->data);
		refEven = &(*refEven)->next;
		Even->next = SegregateOddnEven(&head->next);
		return Even;
	}
	Odd->next = Even;
	return Odd;
}


void main()
{
	struct node *LL = NULL;

	int num[] = {16,15,23,28,24,13,19,25,18,29,20}; // 
	for(int i=(sizeof(num)/sizeof(num[0])-1) ; i>=0 ; i--)
		Push(&LL,num[i]);

	printLL(LL);
	struct node *temp = SegregateOddnEven(&LL);
	printLL(temp);

	cin.get();
}