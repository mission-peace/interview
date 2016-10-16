#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *down;
	struct node *next;
};

struct node *CreateNode(int a)
{
	struct node *temp = new struct node();

	temp->data = a;
	temp->down = NULL;
	temp->next = NULL;
	return temp;
}

struct node *Push(struct node **refHead, int num)
{
	struct node *temp = CreateNode(num);

	temp->next = NULL;
	temp->down = *refHead;

	*refHead = temp;
	return *refHead;
}

void printLL(struct node *head)
{
	if(head==NULL)
	{
		 cout<<"\n The LL is empty!\n";
		 return;
	}

	cout<<endl;
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head = head->down;
	}
	cout<<endl;
}

void printLLAcross(struct node *head)
{
	if(head==NULL)
	{
		 cout<<"\n The LL is empty!\n";
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

struct node *MergeLLs(struct node *LL1,struct node *LL2)
{
	if(LL1==NULL)
		return LL2;
	if(LL2==NULL)
		return LL1;
	
	struct node *merged = NULL;
	if(LL1->data < LL2->data)
	{
		merged = LL1;
		merged->down = MergeLLs(LL1->down,LL2);
	}
	else
	{
		merged = LL2;
		merged->down = MergeLLs(LL1,LL2->down);
	}
	return merged;
}

struct node *_flattenLL(struct node **refHead)
{
	if(*refHead==NULL || (*refHead)->next==NULL)
		return *refHead;
	return MergeLLs(*refHead,_flattenLL(&(*refHead)->next));
}

void FlattenLL(struct node **refHead)
{
	*refHead = _flattenLL(refHead);
}

void main()
{
	struct node *LL=NULL;

	int num1[] = {5,7,8,30};
	for(int i=(sizeof(num1)/sizeof(num1[0]))-1 ; i>=0 ; i--)
		Push(&LL,num1[i]);

	int num2[] = {10,20};
	for(int i=(sizeof(num2)/sizeof(num2[0]))-1 ; i>=0 ; i--)
		Push(&(LL->next),num2[i]);

	int num3[] = {19,22,50};
	for(int i=(sizeof(num3)/sizeof(num3[0]))-1 ; i>=0 ; i--)
		Push(&(LL->next->next),num3[i]);

	int num4[] = {28,35,40,45};
	for(int i=(sizeof(num4)/sizeof(num4[0]))-1 ; i>=0 ; i--)
		Push(&(LL->next->next->next),num4[i]);


	printLLAcross(LL);
	cout<<"\n Each Down LLs\n";
	printLL(LL);
	printLL(LL->next);
	printLL(LL->next->next);
	printLL(LL->next->next->next);
	
	FlattenLL(&LL);
	cout<<"\n After Flattenning :\n";
	//printLLAcross(LL);
	printLL(LL);

	cin.get();

}