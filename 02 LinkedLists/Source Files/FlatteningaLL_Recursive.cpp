#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *down;
	struct node *right;
};

struct node *CreateNode(int a)
{
	struct node *temp = new struct node();

	temp->data = a;
	temp->down = NULL;
	temp->right = NULL;
	return temp;
}

struct node *Push(struct node **refHead,int num)
{
	struct node *temp = CreateNode(num);

	temp->down = *refHead;
	temp->right = NULL;
	*refHead = temp;

	return *refHead;
}

void printLLacross(struct node *head)
{
	if(head==NULL)
	{
		cout<<"\nThe LL is empty!\n";
		return;
	}

	cout<<endl;
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head = head->right;
	}
	cout<<endl;
}


void printLLdown(struct node *head)
{
	if(head==NULL)
	{
		cout<<"\nThe LL is empty!\n";
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

struct node *MergeLLs(struct node *LL1,struct node *LL2)
{
	if(LL1==NULL)
		return LL2;
	if(LL2==NULL)
		return LL1;
	
	struct node *mergedLL = NULL;
	if(LL1->data < LL2->data)
	{
		mergedLL = LL1;
		mergedLL->down = MergeLLs(LL1->down,LL2);
	}
	else
	{
		mergedLL = LL2;
		mergedLL->down = MergeLLs(LL1,LL2->down);
	}
	return mergedLL;
}

struct node *_flattenLL(struct node **refHead)
{
	if(*refHead==NULL || (*refHead)->right==NULL)
		return *refHead;
	return MergeLLs(*refHead,_flattenLL(&(*refHead)->right));
}

void FlattenLL(struct node **refHead)
{
	*refHead = _flattenLL(refHead);
}

void main()
{
	struct node *LL = NULL;

	int num1[] = {6,14,16,18,19};
	for(int i=(sizeof(num1)/sizeof(num1[0]))-1; i>=0 ; i--)
		Push(&LL,num1[i]);

	int num2[] = {20,25,33};
	for(int i=(sizeof(num2)/sizeof(num2[0]))-1; i>=0 ; i--)
		Push(&LL->right,num2[i]);

	int num3[] = {40,47};
	for(int i=(sizeof(num3)/sizeof(num3[0]))-1; i>=0 ; i--)
		Push(&LL->right->right,num3[i]);

	int num4[] = {50,53,58,69};
	for(int i=(sizeof(num4)/sizeof(num4[0]))-1; i>=0 ; i--)
		Push(&LL->right->right->right,num4[i]);

	printLLacross(LL);
	cout<<"\nThe LLs listed down\n";
	printLLdown(LL);
	printLLdown(LL->right);
	printLLdown(LL->right->right);
	printLLdown(LL->right->right->right);

	FlattenLL(&LL);
	cout<<"\nFlattenned LL :\n";
	printLLacross(LL);
	printLLdown(LL);

	cin.get();
}

