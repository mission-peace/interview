#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *arbit;
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

void printArbitLL(struct node *head)
{
	cout<<endl;
	while(head != NULL)
	{
		cout<<head->data<<" ";
		head=head->arbit;
	}
	cout<<endl;
}

struct node *CreateNode(int num)
{
	struct node *temp = new struct node();
	temp->data = num;
	temp->arbit = NULL;
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


struct node *MedianofLL(struct node *slow)
{
	if(slow==NULL)
		return NULL;

	struct node *fast = slow->arbit;

	while(slow && fast && fast->arbit)
	{
		slow = slow->arbit;
		fast = fast->arbit->arbit;
	}
	return slow;

}

void SplitLLintoHalves(struct node *head,struct node **refHalf1,struct node **refHalf2)
{
	if(head==NULL || head->arbit==NULL)
	{
		*refHalf1 = head;
		*refHalf2 = NULL;
		return;
	}

	*refHalf1 = head;
	struct node *middle = MedianofLL(head);
	*refHalf2 = middle->arbit;
	middle->arbit = NULL;

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
		mergedLL->arbit = mergeSortedLLs(LL1->arbit,LL2);
	}
	else
	{
		mergedLL = LL2;
		mergedLL->arbit = mergeSortedLLs(LL1,LL2->arbit);
	}
	return mergedLL;
}

struct node *MergeSort(struct node **refHead)
{
	struct node *head = *refHead;
	if(head==NULL || head->arbit==NULL)
		return head;

	struct node *half1 = NULL;
	struct node *half2 = NULL;

	SplitLLintoHalves(head,&half1,&half2);
	MergeSort(&half1);
	MergeSort(&half2);
	*refHead = mergeSortedLLs(half1,half2);

	return *refHead;
}

void fillArbitPointers(struct node **refHead)
{
	struct node *temp = *refHead;

	if(temp==NULL)
		return;

	while(temp!=NULL)
	{
		temp->arbit = temp->next;
		temp = temp->next;
	}

	cout<<"\nAfter filling the Arbitrary Pointer : ";
	printArbitLL(*refHead);

	MergeSort(refHead);

}

void main()
{
	int num[]={38,42,24,78,33,21,63,15};

	struct node *LL=NULL;
	for(int i=sizeof(num)/sizeof(num[0])-1; i>=0 ; i--)
		Push(&LL,num[i]);

	cout<<"\nInitially the LL is and the LL of Arbitrary POinters: ";
	printLL(LL);
	printArbitLL(LL);	

	fillArbitPointers(&LL);
	cout<<"\nAfter Arbitrary Pointers point to next higher value : ";
	printArbitLL(LL);

	cin.get();
}