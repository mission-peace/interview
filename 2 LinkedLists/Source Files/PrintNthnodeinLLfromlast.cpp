#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

void printLL(struct node *head,bool printindex = false,int index=0)
{
	int indexcount=0;

	cout<<endl;
	if(head != NULL)
	{
		while(head != NULL)
		{
			if(!printindex)
				cout<<head->data<<" ";

			else
			{
				if(indexcount==index)
				{
					cout<<"The data present at index "<<index<<" is  : "<<head->data;
					break;
				}
				indexcount++;
			}
			head = head->next;
		}

		if(printindex && indexcount != index)
			cout<<"\nThe LL doesn't support the index you have mentioned!\n";

	}
	else
		cout<<"The LL is empty!";
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

	if(*head == NULL)
		*head = temp;
	else
	{
		temp->next = *head;
		*head = temp;
	}
	return *head;
}

int sizeofLL(struct node *head)
{
	if(head == NULL)
		return 0;
	else
		return 1 + sizeofLL(head->next);
}

void findNthfromEnd(struct node *head,int x)
{
	int distance=0;
	struct node *temp=head;

	while(head!=NULL)
	{
		if(distance == x)
			temp=temp->next;
		else		
			distance++;
		head = head->next;
	}
	if(temp != NULL)
		cout<<"\nThe node at index "<<x<<" from the END of LL is : "<<temp->data<<"  distance = "<<distance<<endl;
	else
		cout<<endl<<x<<" is invalid distance from the last node for this LL!"<<"  distance = "<<distance<<endl;
}

void main()
{
	int num[] = {4,5,7,8,2,3,6};

	struct node *LL = NULL;
	for(int i=(sizeof(num)/sizeof(num[0]))-1 ; i>=0 ; i--)
		Push(&LL,num[i]);
	printLL(LL);

	for(int i=(sizeof(num)/sizeof(num[0]))-1 ; i>=0 ; i--)
		findNthfromEnd(LL,i);
	findNthfromEnd(LL,sizeofLL(LL));
	findNthfromEnd(LL,100);
	findNthfromEnd(LL,-45);
	cin.get();
	cin.get();
}