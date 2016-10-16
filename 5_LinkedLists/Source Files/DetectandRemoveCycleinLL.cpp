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

void RemoveLoop(struct node *loopnode,struct node *head)
{
	struct node *ptr1 = loopnode;
	struct node *ptr2 = loopnode;

	// Step 1 : Calculate the Length of the Loop
	unsigned int looplen = 1;
	while(ptr2->next!=ptr1)
	{
		looplen++;
		ptr2 = ptr2->next;
	}

	// Step 2 : Offset the pointer2 by LoopLength
	ptr1 = head;
	ptr2 = head;
	while(looplen--)
		ptr2=ptr2->next;

	// Step 3 : Maintain a pointer which tracks the previous node visited by pointer 2
	//				and Move pointer1 and pointer2 at same pace so that they meet at starting point of the Loop
	struct node *loopend = NULL;
	while(ptr1!=ptr2)
	{
		ptr1 = ptr1->next;
		loopend = ptr2;
		ptr2 = ptr2->next;
	}
	cout<<"\nThe starting point of Loop is : "<<ptr2->data;

	// Step 4 : Make the 'next' of previous node (end node) to NULL, thereby removing the loop
	loopend->next = NULL;

}

int DetectLoop(struct node *head)
{
	if(head==NULL || head->next==NULL)
		return 0;
	
	struct node *slow=head;
	struct node *fast=head;

	while(slow!=NULL && fast!=NULL && fast->next!=NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if(slow==fast)
		{
			cout<<"\nLoop node is : "<<slow->data;
			RemoveLoop(slow,head);
			return 1;
		}
	}
	return 0;
}


void main()
{
	int num[]={1,2,3,4,5,6,7,8,9};

	struct node *LL=NULL;
	for(int i=sizeof(num)/sizeof(num[0])-1; i>=0 ; i--)
		Push(&LL,num[i]);

	cout<<"\nInitially the LL is : ";
	printLL(LL);

	for(int i=1 ; i<=sizeof(num)/sizeof(num[0])-1 ; i++)
	{
		(getAddress(LL,9))->next = getAddress(LL,num[i]);
		DetectLoop(LL) ? cout<<"\nAfter removing Loop, the LL is : ":cout<<"\nNo Loop in the LL\n";
		printLL(LL);
	}

	// Test the No loop condition!
	DetectLoop(LL) ? cout<<"\nAfter removing Loop, the LL is : ":cout<<"\nNo Loop in the LL!";
	printLL(LL);

	cin.get();
}