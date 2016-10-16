#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};


int sizeofLL(struct node *head)
{
	if(head == NULL)
		return 0;
	else
		return 1 + sizeofLL(head->next);
}

void printLL(struct node *head)
{
	cout<<endl;
	while(head !=NULL)
	{		
		cout<<head->data<<" ";
		head = head->next; 
	}
	cout<<endl;
}

node *CreateNode(int x)
{
	struct node *temp = new struct node();
	temp->data = x;
	temp->next = NULL;
	return temp;
}

node *Push(struct node **head,int num)
{
	struct node *temp = CreateNode(num);

	if(*head == NULL)
		*head = temp;

	else
	{
		temp->next = *head;
		*head = temp;
	}
	return temp;
}

void swapLLheads(struct node **head1,struct node **head2)
{
	struct node *temp=*head1;
	*head1=*head2;
	*head2=temp;
}

void addwithBigLL(struct node *LL1,struct node *cur,struct node **head,int *c)
{

	if( LL1 != cur)
	{
		addwithBigLL(LL1->next,cur,head,c);

		int sum = LL1->data + *c;
		*c = (sum>=10) ? 1:0;
		struct node *temp = Push(&LL1,sum%10);

		temp->next = *head;
		*head = temp;

	}
	
}


struct node *addSameSizeLL(struct node *LL1,struct node *LL2, int *c)
{
	if(LL1 == NULL && LL2 == NULL)
		return NULL;
	else
	{
		struct node *head = addSameSizeLL(LL1->next,LL2->next,c);

		int sum = LL1->data + LL2->data + *c;
		*c = (sum>=10) ? 1:0;
		head = Push(&head,sum%10);

		return head;
	}
}

struct node *addLL(struct node *LL1,struct node *LL2)
{
	int sum=0;
	int carry=0;
	struct node *temp,*head=NULL;

	if(sizeofLL(LL1)==sizeofLL(LL2))
		head = addSameSizeLL(LL1,LL2,&carry);
	else
	{
		int diff = abs(sizeofLL(LL1)-sizeofLL(LL2));		
		if(sizeofLL(LL1) < sizeof(LL2))
			swapLLheads(&LL1,&LL2);

		for(temp = LL1 ; diff-- ; temp = temp->next)
		{}

		head = addSameSizeLL(temp,LL2,&carry);
		addwithBigLL(LL1,temp,&head,&carry);
	}
	
	if(carry!=0)
	{
		temp = CreateNode(carry);
		temp->next =head;
		head =temp;
	}

	return head;
}



void main()
{
	int num1[] = {9,9,9,9,6};
	int num2[] = {9,9,9,9,9};

	struct node *numLL1 = NULL;
	for(int i=(sizeof(num1)/sizeof(num1[0]))-1; i >= 0  ; i--)
		Push(&numLL1,num1[i]);

	struct node *numLL2 = NULL;
	for(int i=(sizeof(num2)/sizeof(num2[0]))-1; i >= 0  ; i--)
		Push(&numLL2,num2[i]);

	printLL(numLL1);
	printLL(numLL2);

	printLL(addLL(numLL1,numLL2));

	cin.get();
}