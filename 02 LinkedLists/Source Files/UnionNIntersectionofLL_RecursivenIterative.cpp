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
}

struct node *UnionofLLs(struct node *LL1,struct node *LL2)
{
	if(LL1==NULL)
		return LL2;
	if(LL2==NULL)
		return LL1;

	struct node *LL3 = NULL;
	if(LL1->data==LL2->data)
	{
		Push(&LL3,LL1->data);
		LL3->next = UnionofLLs(LL1->next,LL2->next);
	}
	else if(LL1->data < LL2->data)
	{
		Push(&LL3,LL1->data);
		LL3->next = UnionofLLs(LL1->next,LL2);
	}
	else
	{
		Push(&LL3,LL2->data);
		LL3->next = UnionofLLs(LL1,LL2->next);
	}

	return LL3;

}

struct node *UnionofLLs_Iter(struct node *LL1,struct node *LL2)
{
	if(LL1==NULL)
		return LL2;
	if(LL2==NULL)
		return LL1;

	struct node *LL5 = NULL;
	struct node **refLL5 = &LL5;
	struct node *remainsofLL =NULL;

	while(LL1 && LL2)
	{
		if(LL1->data==LL2->data)
		{
			Push(refLL5,LL1->data);
			refLL5 = &((*refLL5)->next);
			LL1 = LL1->next;
			LL2 = LL2->next;
		}
		else if(LL1->data < LL2->data)
		{
			Push(refLL5,LL1->data);
			refLL5 = &((*refLL5)->next);
			LL1 = LL1->next;
		}
		else
		{
			Push(refLL5,LL2->data);
			refLL5 = &((*refLL5)->next);
			LL2 = LL2->next;
		}
	}

	if(LL1==NULL)
		remainsofLL = LL2;

	if(LL2==NULL)
		remainsofLL = LL1;

	while(remainsofLL!=NULL)
	{
		Push(refLL5,remainsofLL->data);
		refLL5 = &((*refLL5)->next);
		remainsofLL = remainsofLL->next;
	}
	return LL5;
}

struct node *IntersectofLLs_Iter(struct node *LL1,struct node *LL2)
{
	if(LL1==NULL || LL2==NULL)
		return NULL;

	struct node *LL4 = NULL;
	struct node **refLL4 = &LL4;

	while(LL1 && LL2)
	{
		if(LL1->data==LL2->data)
		{
			Push(refLL4,LL1->data);
			refLL4 = &((*refLL4)->next);

			LL1 = LL1->next;
			LL2 = LL2->next;
		}
		else if(LL1->data < LL2->data)
			LL1 = LL1->next;
		else
			LL2 = LL2->next;

	}
	return LL4;
}

struct node *IntersectofLLs(struct node *LL1,struct node *LL2)
{
	if(LL1==NULL || LL2==NULL)
		return NULL;

	struct node *LL4 = NULL;
	if(LL1->data==LL2->data)
	{
		Push(&LL4,LL1->data);
		LL4->next = IntersectofLLs(LL1->next,LL2->next);
		return LL4;
	}
	else if(LL1->data < LL2->data)
		IntersectofLLs(LL1->next,LL2);
	else
		IntersectofLLs(LL1,LL2->next);
	
}


void main()
{
	int num1[]= {7,10,6,13,4,3,14,1,15};

	struct node *LL1 = NULL;
	for(int i=(sizeof(num1)/sizeof(num1[0]))-1 ; i>=0 ; i--)
		Push(&LL1,num1[i]);

	int num2[]= {2,17,16,12,4,10,13,6};

	struct node *LL2 = NULL;
	for(int i=(sizeof(num2)/sizeof(num2[0]))-1 ; i>=0 ; i--)
		Push(&LL2,num2[i]);


	cout<<"\nInitially the LLs are...";
	printLL(LL1);
	printLL(LL2);

	MergeSort(&LL1);
	MergeSort(&LL2);

	cout<<"\nAfter MergeSort the LLs are...";
	printLL(LL1);
	printLL(LL2);

	struct node *UnionLL1 = UnionofLLs(LL1,LL2);
	cout<<"\nThe Union of LLs is (Recursion) ...";
	printLL(UnionLL1);

	struct node *UnionLL2 = UnionofLLs_Iter(LL1,LL2);
	cout<<"\nThe Union of LLs is (Iteration)...";
	printLL(UnionLL2);

	struct node *IntersectionLL1 = IntersectofLLs(LL1,LL2);
	cout<<"\nThe Intersection of LLs is (Recursion)...";
	printLL(IntersectionLL1);

	struct node *IntersectionLL2 = IntersectofLLs_Iter(LL1,LL2);
	cout<<"\nThe Intersection of LLs is (Iteration)...";
	printLL(IntersectionLL2);


	cin.get();
}