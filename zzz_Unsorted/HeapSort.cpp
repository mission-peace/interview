#include<iostream>
using namespace std;

class MinHeap
{
	int *heap;
	int cap;

public :

	int heapsize;
	MinHeap(int );
	
	int parent(int );
	int left(int );
	int right(int );
	int getHeapsize();
	int getMin();
	void Heapify(int );			//	T->B
	int extractMin();				//	T->B
	void insertKey(int );			//	B->T
	void deleteIndex(int );			//	B->T and T->B
	void decreaseKey(int ,int );	//	B->T
	void HeapSort();

};

MinHeap::MinHeap(int cap)
{
	this->cap = cap;
	this->heapsize = 0;
	heap = new int[this->cap];
}

int MinHeap::getHeapsize()
{
	return heapsize;
}

int MinHeap::parent(int i)
{	return (i-1)/2	;	}

int MinHeap::left(int i)
{	return 2*i+1	;	}

int MinHeap::right(int i)
{	return 2*i+2	;	}

int MinHeap::getMin()
{	return heap[0]	;	}

void Swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void MinHeap::Heapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;

	if(l<heapsize && heap[l] < heap[smallest])
		smallest = l;
	if(r<heapsize && heap[r] < heap[smallest])
		smallest = r;
	if(smallest!=i)
	{
		Swap(&heap[i],&heap[smallest]);
		Heapify(smallest);
	}
}

int MinHeap::extractMin()
{
	if(heapsize==0)
	{
		cout<<"\nHeap is empty";
		heapsize--;
		return 99999;
	}
	if(heapsize==1)
	{
		heapsize--;
		return heap[0];
	}

	int temp = heap[0];
	heap[0] = heap[heapsize-1];
	heapsize--;
	Heapify(0);
	return temp;

}

void MinHeap::insertKey(int key)
{
	if(heapsize==cap)
	{
		cout<<"Can't Insert! Heap is full"<<endl;
		return;
	}
	if(heapsize<=0)
	{
		heap[0] = key;
		heapsize=1;
		return;
	}
	heap[heapsize] = key;
	heapsize++;
	int i = heapsize-1;

	while(i!=0 && heap[parent(i)] > heap[i])
	{
		Swap(&heap[i],&heap[parent(i)]);
		i = parent(i);
	}
}

void MinHeap::decreaseKey(int i,int key)
{
	heap[i] = key;

	while(i!=0 && heap[parent(i)] > heap[i])
	{
		Swap(&heap[i],&heap[parent(i)]);
		i=parent(i);
	}
}

void MinHeap::deleteIndex(int i)
{
	decreaseKey(i,-99999);
	extractMin();
}

void MinHeap::HeapSort()
{
	int n = getHeapsize();
	while(getHeapsize()>0)
	{
		int temp = extractMin();
		heap[heapsize] = temp;
	}

	cout<<"\n HEAP SORT result : "<<endl;
	for(int i=0; i<=n-1 ; i++)
	{
		cout<<heap[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int arr[] = {2,6,3,8,1,7,4,5};
	int n = sizeof(arr)/sizeof(arr[0]);

	MinHeap h(n);

	for(int i=0 ; i<=n-1 ; i++)
		h.insertKey(arr[i]);

	cout<<"\nThe size of Heap is : "<< h.getHeapsize()<<endl;
	while(h.getHeapsize() >= 0)
	{
		cout<<"\nExtract the Minimum : "<<h.extractMin()<<endl;
		cout<<"The size of Heap is now : "<<h.getHeapsize()<<endl;
	}

	for(int i=0 ; i<=n-1 ; i++)
		h.insertKey(arr[i]);

	h.HeapSort();

	cin.get();
	cin.get();
	return 0;
}
