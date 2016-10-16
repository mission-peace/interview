/*
Take 3 LLs, sort LL2 in ascending and LL3 in descending.
Pick one element from LL1 and one element from LL2 and LL3.
If sum mathces, return;
Else if sum is  lesser, look for a bigger  number, so increment LL2
Else if sum is greater, look for a smaller number, so increment LL3
*/

#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

struct node *CreateNode(int a)
{
	struct node *temp=new struct node();

	temp->data=a;
	temp->next=NULL;
	return temp;
}

struct node *Push(struct node **refHead,int num)
{
	struct node *temp = CreateNode(num);

	if(*refHead!=NULL)
		temp->next = *refHead;

	*refHead = temp;
	return *refHead;
}

void printLL(struct node *head)
{
	if(head==NULL)
	{
		cout<<"\nThe LL is empty\n";
		return;
	}

	cout<<endl;
	while(head)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
}

struct node *MedianofLL(struct node *slow)
{
	if(slow==NULL || slow->next==NULL)
		return slow;
	struct node *fast = slow->next;

	while(slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

void SplitLLintoHalves(struct node *head,struct node **refhalf1,struct node **refhalf2)
{
	if(head==NULL || head->next==NULL)
	{
		*refhalf1 = head;
		*refhalf2 = NULL;
		return;
	}

	struct node *middle = MedianofLL(head);
	*refhalf2 = middle->next;
	middle->next = NULL;
	*refhalf1 = head;
}

struct node *mergeSortedLLs(struct node *LL1,struct node *LL2,bool ascend)
{
	if(LL1==NULL)
		return LL2;
	if(LL2==NULL)
		return LL1;

	struct node *mergedLL = NULL;
	if(ascend)
	{
		if(LL1->data < LL2->data)
		{
			mergedLL = LL1;
			mergedLL->next = mergeSortedLLs(LL1->next,LL2,ascend);
		}
		else
		{
			mergedLL = LL2;
			mergedLL->next = mergeSortedLLs(LL1,LL2->next,ascend);
		}
	}
	else
	{
		if(LL1->data > LL2->data)
		{
			mergedLL = LL1;
			mergedLL->next = mergeSortedLLs(LL1->next,LL2,ascend);
		}
		else
		{
			mergedLL = LL2;
			mergedLL->next = mergeSortedLLs(LL1,LL2->next,ascend);
		}

	}
	return mergedLL;
}

struct node *MergeSort(struct node **refHead,bool ascend=true)
{
	struct node *head = *refHead;

	if(head==NULL || head->next==NULL)
		return head;

	struct node *half1 = NULL;
	struct node *half2 = NULL;

	SplitLLintoHalves(head,&half1,&half2);
	MergeSort(&half1,ascend);
	MergeSort(&half2,ascend);
	*refHead = mergeSortedLLs(half1,half2,ascend);

}

void findTriplet(struct node *LL1,struct node *LL2,struct node *LL3,int findnum)
{
	if(LL1==NULL && LL2==NULL && LL3==NULL)
	{
		cout<<"\n All are empty.. No Triplet!";
		return;
	}
	bool tripletfound = false;
	struct node *head2 = LL2;
	struct node *head3 = LL3;

	while(LL1!=NULL)
	{
		while(LL2!=NULL && LL3!=NULL)
		{
			int sum = LL1->data + LL2->data + LL3->data;
			if(sum==findnum)
			{
				cout<<"\nYes..Triplet found! "<<LL1->data<<" + "<<LL2->data<<" + "<<LL3->data<<" = "<<findnum;
				tripletfound = true;
				break;
			}
			else if(sum < findnum)
			{
				LL2 = LL2->next;
			}
			else
			{
				LL3 = LL3->next;
			}
		}
		LL1 = LL1->next;
		LL2= head2;
		LL3= head3;		
	}
	if(!tripletfound)
		cout<<"\nSorry.. No Triplet found!";
}


void main()
{
	struct node *LL1=NULL;

	int num1[] = {29,15,12,22,18,25};
	for(int i=(sizeof(num1)/sizeof(num1[0]))-1 ; i>=0 ; i--)
		Push(&LL1,num1[i]);

	struct node *LL2=NULL;

	int num2[] = {42,50,43,54,58,40,55};
	for(int i=(sizeof(num2)/sizeof(num2[0]))-1 ; i>=0 ; i--)
		Push(&LL2,num2[i]);

	struct node *LL3=NULL;

	int num3[] = {69,78,64,75};
	for(int i=(sizeof(num3)/sizeof(num3[0]))-1 ; i>=0 ; i--)
		Push(&LL3,num3[i]);

	cout<<"\nInitially...";
	printLL(LL1);
	printLL(LL2);
	printLL(LL3);

	MergeSort(&LL2);
	MergeSort(&LL3,false);

	cout<<"\n\nLL2 sorted in ascending, LL3 sorted in descending..";
	printLL(LL1);
	printLL(LL2);
	printLL(LL3);

	cout<<"\n\nAre there triplet?";
	findTriplet(LL1,LL2,LL3,2);

	cin.get();
}
