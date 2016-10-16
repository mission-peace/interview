#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

struct node *newNode(int a)
{
	struct node *temp = new struct node();

	temp->data = a;
	temp->next = temp;
	return temp;
}

void createRingLL(struct node **refEnd,int x)
{
	struct node *temp = newNode(x);

	if(*refEnd!=NULL)
	{
		struct node *start = (*refEnd)->next;
		(*refEnd)->next = temp;
		temp->next = start;
	}
		*refEnd = temp;
}

void printRingLL(struct node *tail)
{
	if(tail==NULL)
	{
		cout<<"\nCircular LL is empty\n";
		return;
	}

	struct node *ring = tail->next;
	cout<<ring->data<<" ";

	while(ring!=tail)
	{
		ring = ring->next;
		cout<<ring->data<<" ";
	}
}

int getRingSize(struct node *tail)
{
	if(tail==NULL)
	{
		cout<<"\nCircular LL is empty\n";
		return -1;
	}

	struct node *ring = tail->next;
	int count = 1;

	while(ring!=tail)
	{
		ring = ring->next;
		count++;
	}
	return count;
}

void printLL(struct node *head)
{
	if(head==NULL)
		return ;

	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
}


void rotateRingLL(struct node **refEnd,int k,bool clockwise=true)
{
	struct node *ringLL = *refEnd;

	if(ringLL==NULL)
		return;

	int n = getRingSize(ringLL);

	k = k%n;
	if(clockwise)
		k = n-k;

	int count = 0;
	struct node *ringend = ringLL;

	while(count < k)
	{
		ringend = ringend->next;
		count++;
	}
	*refEnd = ringend->next;
	ringend->next = NULL;

}

int main()
{
	int arr[] = {1,2,3,4,5,6,7};
	int n = sizeof(arr)/sizeof(arr[0]);

	struct node *ringLL = NULL;

	for(int i=0 ; i<=n-1 ; i++)
		createRingLL(&ringLL,arr[i]);

	printRingLL(ringLL);
	int k = 52;
	rotateRingLL(&ringLL,k,false);
	cout<<"\nAfter rotating "<<k<<" times : "<<endl;
	printLL(ringLL);
	cin.get();
	cin.get();
	return 0;

}