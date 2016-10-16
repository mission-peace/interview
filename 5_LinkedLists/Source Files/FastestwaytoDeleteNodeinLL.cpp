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
	while(head !=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

struct node *CreateNode(int x)
{
	struct node *temp = new struct node();
	temp->data = x;
	temp->next = NULL;
	return temp;
}

struct node *Push(struct node **head,int x)
{
	struct node *temp = CreateNode(x);

	if(*head != NULL)
		temp->next = *head;

	*head = temp;
	return temp;
}

void deleteLLData(struct node *head,int numtodel)
{
	struct node *temp;
	while(head != NULL)
	{		
		if(head->data == numtodel)
		{
			if(head->next != NULL)
			{
				temp = head->next;
				head->data = temp->data;
				head->next = temp->next;
				temp->next = NULL;
			}
			else
			{
				temp->next=NULL;
				temp=head;
			}

			delete temp;
			return;
		}
		temp = head;
		head = head->next;
	}
	cout<<"\nWe reached end of LL, the number you chose is not in LL!\n";
}

void main()
{
	int num[] = {3,8,4,6,7,1};

	struct node *LL=NULL;
	for(int i=(sizeof(num)/sizeof(num[0]))-1 ; i>=0 ; i--)
		Push(&LL,num[i]);

	printLL(LL);
	
	int numtodelete = 0;
	cout<<"\nMention the number from the above list to delete!\n";
	cin>>numtodelete;

	deleteLLData(LL,numtodelete);
	printLL(LL);

	cin.get();
	cin.get();
	
}