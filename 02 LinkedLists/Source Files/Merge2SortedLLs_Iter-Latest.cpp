#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

struct node *newNode(int  a)
{
	struct node *temp = new struct node();
	temp->data = a;
	temp->next = NULL;
	return temp;
}

void createLL(struct node **refHead,int x)
{
	struct node *temp = newNode(x);
	if(*refHead!=NULL)
		temp->next = *refHead;
	*refHead = temp;
}

void printLL(struct node *head)
{
	if(head==NULL)
		cout<<"LL is empty\n";
	cout<<endl;
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

void moveNodes(struct node **refLL3,struct node **refSource)
{
	struct node *temp = *refSource;
	*refSource = (*refSource)->next;
	temp->next = *refLL3;
	*refLL3 = temp;	
	// now we have moved the tail node to the last node, still pending is moving it to NULL node
	// this is done by refLL3 = &(*refLL3)->next; in the calling code

}

struct node *MergeLLsITER(struct node *LL1,struct node *LL2)
{
	struct node *LL3 = NULL;
	struct node **refLL3 = &LL3;

	while(1)
	{
		if(LL1==NULL)
		{
			*refLL3 = LL2;
			break;
		}
		if(LL2==NULL)
		{
			*refLL3 = LL1;
			break;
		}

		if(LL1->data <= LL2->data)
			moveNodes(refLL3,&LL1);
		else if(LL2->data < LL1->data)
			moveNodes(refLL3,&LL2);
		refLL3 = &((*refLL3)->next);
	}
	return LL3;

}

int main()
{
	int arr1[] = {5,7,10,14,16};
	int n1 = sizeof(arr1)/sizeof(arr1[0]);
	struct node *LL1=NULL;
	for(int i=n1-1 ; i>=0 ; i--)
		createLL(&LL1,arr1[i]);

	int arr2[] = {5,6,11,12};
	int n2 = sizeof(arr2)/sizeof(arr2[0]);
	struct node *LL2 = NULL;
	for(int i=n2-1 ; i>=0 ; i--)
		createLL(&LL2,arr2[i]);

	printLL(LL1);
	printLL(LL2);

	struct node *LL3 = MergeLLsITER(LL1,LL2);
	printLL(LL3);	// LL1 and LL2 are same as LL3 at this point! They are not empty

	cin.get();
	cin.get();
	return 0;
}

