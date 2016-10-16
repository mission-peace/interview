#include<iostream>
using namespace std;

struct node
{
	int x;
	int y;
	struct node *next;
};

struct node *CreateNode(int a,int b)
{
	struct node *temp=new struct node();

	temp->x=a;
	temp->y=b;
	temp->next=NULL;
	return temp;
}

struct node *Push(struct node **refHead,int a,int b)
{
	struct node *temp = CreateNode(a,b);

	if(*refHead!=NULL)
		temp->next = *refHead;

	*refHead = temp;
	return *refHead;
}

void printLL(struct node *head)
{
	if(head==NULL)
	{
		cout<<"\nThe LL is empty\n";
		return;
	}
	cout<<endl;
	while(head)
	{
		cout<<"{"<<head->x<<","<<head->y<<"}"<<" ";
		head=head->next;
	}
}

bool xtravel(struct node *head)
{
	if(head==NULL || head->next==NULL)
		return false;

	bool xtravel = false;
	if(head->y == head->next->y)
		xtravel = true;
	else
		xtravel = false;

	return xtravel;
}

struct node *RemoveMiddlePoints(struct node *head)
{
	if(head==NULL || head->next==NULL || head->next->next == NULL)
		return head;

	struct node *temp = head;
	struct node *delnode = NULL;
	while(temp!=NULL)
	{
		if(xtravel(temp))
		{
			int ycor = head->y;
			while(head->next  && head->next->next->y==ycor)
			{
				if(head->next!=NULL)
					delnode = head->next;
				else
					break;
				if(delnode->next!=NULL)
					head->next = delnode->next;
				else
					head->next=NULL;

				delnode->next=NULL;
				delete delnode;

				if(head->next->next == NULL)
					break;
			}

		}
		else
		{
			int xcor = head->x;
			while(head->next && head->next->next->x==xcor)
			{
				if(head->next!=NULL)
					delnode = head->next;
				else
					break;
				if(delnode->next!=NULL)
					head->next = delnode->next;
				else
					head->next=NULL;

				delnode->next=NULL;
				delete delnode;

				if(head->next->next == NULL)
					break;
			}
		}
		temp = head->next;
		head = temp;
	}
}


void main()
{
	struct node *LL=NULL;

	int num[] = { -12,0, -9,0,  -6,0,  -3,0,  -1,0,  -1,-4,  -1,-6,  5,-6,  6,-6 };
	for(int i=(sizeof(num)/sizeof(num[0]))-1 ; i>=0 ; i-=2)
		Push(&LL,num[i-1],num[i]);

	cout<<"\nInitially...";
	printLL(LL);

	RemoveMiddlePoints(LL);
	cout<<"\n\nAfter removing Middle points...";
	printLL(LL);

	cin.get();
}
