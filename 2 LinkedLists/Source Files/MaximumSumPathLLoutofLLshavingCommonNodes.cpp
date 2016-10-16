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

struct node *MedianofLL(struct node *slow)
{
	if(slow==NULL || slow->next==NULL)
		return slow;

	struct node *fast = slow->next;
	while(slow && fast && fast->next)
	{
		slow= slow->next;
		fast=fast->next->next;
	}
	return slow;
}

void SplitLLintoHalves(struct node *head,struct node **refhead1,struct node **refhead2)
{
	if(head==NULL || head->next==NULL)
	{
		*refhead1 = head;
		*refhead2 = NULL;
		return;
	}

	struct node *middle = MedianofLL(head);
	*refhead2 = middle->next;
	middle->next=NULL;
	*refhead1 = head;
}

struct node *mergeSortedLLs(struct node *LL1,struct node *LL2)
{
	if(LL1==NULL)
		return LL2;
	if(LL2==NULL)
		return LL1;

	struct node *mergedLL = NULL;

	if(LL1->data < LL2->data)
	{
		mergedLL = LL1;
		mergedLL->next = mergeSortedLLs(LL1->next,LL2);
	}
	else
	{
		mergedLL = LL2;
		mergedLL->next = mergeSortedLLs(LL1,LL2->next);
	}
	return mergedLL;
}

struct node *MergeSort(struct node **refHead)
{
	struct node *head = *refHead;
	if(head==NULL || head->next==NULL)
		return head;

	struct node *half1=NULL;
	struct node *half2=NULL;

	SplitLLintoHalves(head,&half1,&half2);
	MergeSort(&half1);
	MergeSort(&half2);
	*refHead = mergeSortedLLs(half1,half2);

	return *refHead;
}

struct node *MaximumSumPathLL(struct node *LL1,struct node *LL2)
{
	if(LL1==NULL || LL2==NULL)
		return NULL;

	struct node *MaxSumLL = NULL;
	struct node **refMaxSumLL = &MaxSumLL;

	// Keeps track of the starting point after each Common Node
	struct node *populate1 = LL1;
	struct node *populate2 = LL2;

	// Sums for every node change, during Base Cases, increments for existing LL when other become empty
	int sum1 = 0;
	int sum2 = 0;

	while(1)
	{
		if(LL1->data==LL2->data)
		{
			if(sum1 > sum2)
			{
				while(populate1!=LL1->next)
				{
					Push(refMaxSumLL,populate1->data);
					refMaxSumLL = &(*refMaxSumLL)->next;
					populate1 = populate1->next;
				}
			}
			else
			{
				while(populate2!=LL2->next)
				{
					Push(refMaxSumLL,populate2->data);
					refMaxSumLL = &(*refMaxSumLL)->next;
					populate2 = populate2->next;
				}
			}
			LL1 = LL1->next;
			LL2 = LL2->next;
			populate1=LL1;
			populate2=LL2;
			sum1 = 0;
			sum2 = 0;
		}
		else if (LL1->data < LL2->data)
		{
			sum1 = sum1 + LL1->data;
			LL1 = LL1->next;	
		}
		else
		{
			sum2 = sum2 + LL2->data;
			LL2 = LL2->next;
		}

		if(LL1==NULL && LL2==NULL)
			return MaxSumLL;

		if(LL1==NULL || LL2==NULL)
		{
			if(LL2==NULL)
				sum1 += populate1->data;
			if(LL1==NULL)
				sum2 += populate2->data;
			break;
		}
	}

	struct node *remainsofLL = NULL;
	if(sum1 > sum2)
		remainsofLL = populate1;
	else
		remainsofLL = populate2;

	while(remainsofLL!=NULL)
	{
		Push(refMaxSumLL,remainsofLL->data);
		refMaxSumLL = &(*refMaxSumLL)->next;
		remainsofLL = remainsofLL->next;
	}

	return MaxSumLL;
}


void main()
{
	int num1[]= {1,3,30,90,120,240,250,271};

	struct node *LL1 = NULL;
	for(int i=(sizeof(num1)/sizeof(num1[0]))-1 ; i>=0 ; i--)
		Push(&LL1,num1[i]);

	int num2[]= {0,3,12,32,90,125,240,511};

	struct node *LL2 = NULL;
	for(int i=(sizeof(num2)/sizeof(num2[0]))-1 ; i>=0 ; i--)
		Push(&LL2,num2[i]);


	cout<<"\nInitially the LLs are...";
	printLL(LL1);
	printLL(LL2);

	struct node *MaxSumLL = MaximumSumPathLL(LL1,LL2);
	cout<<"\nThe Maximum Path LL from the above LLs is ...";
	printLL(MaxSumLL);

	cin.get();
}