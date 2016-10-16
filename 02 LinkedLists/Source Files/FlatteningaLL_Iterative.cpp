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
	if(LL1==NULL || LL2==NULL)
		return NULL;
	
	struct node *newLL = NULL;
	struct node **mergedLL = &newLL;
	struct node *attach = NULL;

	while(1)
	{
		if(LL1==NULL)
		{
			while(LL2!=NULL)
			{
				attach = LL2;
				LL2=LL2->down;

				attach->down = NULL;				
				*mergedLL = attach;
				mergedLL = &((*mergedLL)->down);
			}
			break;
		}
		if(LL2==NULL)
		{
			while(LL1!=NULL)
			{
				attach = LL1;
				LL1=LL1->down;

				attach->down = NULL;				
				*mergedLL = attach;
				mergedLL = &((*mergedLL)->down);
			}
			break;
		}

		if(LL1->data < LL2->data)
		{
			attach = LL1;
			LL1 = LL1->down;
		}
		else
		{
			attach = LL2;
			LL2 = LL2->down;
		}
		attach->down = NULL;
		*mergedLL = attach;
		mergedLL = &((*mergedLL)->down);
	}
	return newLL;
}


void FlattenLL(struct node **refHead)
{
	if(*refHead==NULL || (*refHead)->right==NULL)
		return;

	struct node *LL1 = *refHead;
	struct node *LL2 = (*refHead)->right;
	struct node *rest = (*refHead)->right->right;

	while(LL2!=NULL)
	{
		LL1->right = NULL;
		LL2->right = NULL;
		*refHead = MergeLLs(LL1,LL2);
		(*refHead)->right = rest;

		LL1 = *refHead;
		LL2 = (*refHead)->right;
		if(LL2!=NULL)
			rest = LL2->right;
		else
			rest = NULL;
	}

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

