#include<iostream>
using namespace std;


static inline bool isAlphaNumeric(char c)
{
	return isalnum(c);
}


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

	if(*head!=NULL)
		temp->next = *head;

	*head = temp;
	return *head;
}

void printLL(struct node *head)
{
	if(head==NULL)
	{
		cout<<"\n The LL is empty\n";
		return;
	}

	cout<<endl;
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

int sizeofLL(struct node *head)
{
	if(head==NULL)
		return 0;
	else
		return 1 + sizeofLL(head->next);
}

struct node *findLLMedian(struct node *head)
{
	struct node *slow = head;

	if(slow==NULL)
		return NULL;

	struct node *fast = slow->next;

	while(slow && fast!=NULL && fast->next!=NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

struct node *getTail(struct node *head)
{
	if(head==NULL || head->next==NULL)
		return head;

	while(head->next!=NULL)
		head= head->next;

	return head;
}

struct node *getPivotbyPartition(struct node *head,struct node *end,struct node **refnewHead,struct node **refnewEnd)
{
	struct node *pivot = end;

	struct node *prev = NULL;
	struct node *cur = head;
	struct node *tail = pivot;

	while(cur && cur!=pivot)
	{
		if(cur->data < pivot->data)
		{
			if((*refnewHead)==NULL)	
				(*refnewHead) = cur;
			prev = cur;
			cur = cur->next;
		}
		else
		{
           if (prev)
                prev->next = cur->next;
            struct node *tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
		}
	}

	if((*refnewHead)==NULL)
		(*refnewHead) = pivot;

	(*refnewEnd) = tail;

	return pivot;
}

struct node *QuickSort(struct node **refHead,struct node *end)
{
	struct node *head = *refHead;
	if(head==NULL || head->next==NULL)
		return head;

	struct node *newhead = NULL;
	struct node *newend = NULL;
	struct node *pivot = getPivotbyPartition(head,end,&newhead,&newend);

	if(pivot!=newhead)
	{
		struct node *pivprev = newhead;
		while(pivprev->next!=pivot)
			pivprev = pivprev->next;
		pivprev->next = NULL;

		newhead = QuickSort(&newhead,pivprev);
		getTail(newhead)->next = pivot;
	}

	pivot->next = QuickSort(&pivot->next,newend);

	*refHead = newhead;
	return *refHead;
}


void main()
{

	int num[] = {10,4,3,6,4,2,7,5};

	struct node *LL1 = NULL;
	for(int i=(sizeof(num)/sizeof(num[0]))-1 ; i>=0 ; i--)
		Push(&LL1,num[i]);

	printLL(LL1);
	QuickSort(&LL1,getTail(LL1));
	printLL(LL1);



	/*
	cout<<endl<<isAlphaNumeric('a');
	cout<<endl<<isAlphaNumeric('Z');
	cout<<endl<<isAlphaNumeric('0');
	cout<<endl<<isAlphaNumeric('9');
	cout<<endl<<isAlphaNumeric('*');
	cout<<endl<<isAlphaNumeric('(');
	cout<<endl<<isAlphaNumeric('-');
	cout<<endl<<isAlphaNumeric('\n');

	cout<<endl<<isalnum('a');
	cout<<endl<<isalnum('Z');
	cout<<endl<<isalnum('0');
	cout<<endl<<isalnum('9');
	cout<<endl<<isalnum('*');
	cout<<endl<<isalnum('(');
	cout<<endl<<isalnum('-');
	cout<<endl<<isalnum('\r');
	*/
	cin.get();
	cin.get();
}