#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

struct node *createNode(int a)
{
	struct node *temp = new struct node();
	temp->data = a;
	temp->next = NULL;
	return temp;
}

class Queue
{
	int queuesize;
	struct node *front;
	struct node *rear;

public:
	Queue();
	int getQueueSize();
	void enQueue(int data);
	int deQueue();
	int getFront();
	void printQueue();
};

Queue::Queue()
{
	struct node *Queue = NULL;
	this->queuesize = 0;
	this->front = NULL;
	this->rear = NULL;
}

void Queue::enQueue(int data)
{
	struct node *temp = createNode(data);
	if(this->front==NULL)
	{
		this->front = temp;
		this->rear = front;
	}
	else
	{
		this->rear->next = temp;
		this->rear = temp;
	}
	this->queuesize++;
}

void Queue::printQueue()
{
	cout<<endl;
	struct node *start = this->front;
	if(start==NULL)
		cout<<"\nQueue is empty\n";
	while(start!=NULL)
	{
		cout<<start->data<<" ";
		start = start->next;
	}
	cout<<endl;
}



int main()
{
	Queue Q;
	Q.enQueue(1);
	Q.enQueue(2);
	Q.enQueue(3);
	Q.printQueue();


	cin.get();
	cin.get();
	return 0;
}

