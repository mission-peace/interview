#include<iostream>
#include<climits>
using namespace std;

void swap(int *a,int *b)
{
	int temp = *a;
	*a=*b;
	*b=temp;
}

class MinHeap
{
	int *harr;
	int capacity;
	int curheapsize;

public :
	MinHeap(int capacity);

	// get the INDEX of parent, left child and right child at index i (index-index)
	int parent(int i)		{return (i-1)/2 ; }
	int left(int i)	{return (i*2)+1 ; }
	int right(int i)	{return (i*2)+2 ; }

	int getMin() {return harr[0]; }		// (NIL-value)
	void insertkey(int key);			// (value-NIL)
	void deletekey(int i);				// (index-NIL)
	void minHeapify(int i);				// (index-NIL)
	void updatevalue(int i,int key);	// (index,value-NIL)
	int deletemin();

	bool IsHeapEmpty();
	int getHeapsize();
	void printHeap();

};

MinHeap::MinHeap(int maxsize)
{
	this->capacity = maxsize;
	harr = new int[this->capacity];
	curheapsize = 0;
}

void MinHeap::insertkey(int key)
{

	if(curheapsize==this->capacity)
	{
		cout<<"Can't insert key - overflow!\n";
		return;
	}

	curheapsize++;
	int i = curheapsize-1;
	harr[i] = key;

	while( i!=0 && harr[parent(i)] > harr[i])
	{
		swap(&harr[parent(i)],&harr[i]);
		i = parent(i);
	}

}

void MinHeap::updatevalue(int i,int value)
{
	harr[i] = value;

	while(i!=0 && harr[parent(i)] > harr[i])
	{
		swap(&harr[i],&harr[parent(i)]);
		i = parent(i);
	}
}

void MinHeap::minHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;

	if(l<curheapsize && harr[i] > harr[l])
		smallest = l;
	if(r<curheapsize && harr[smallest] > harr[r])
		smallest = r;
	if(smallest != i)
	{
		swap(&harr[smallest],&harr[i]);
		minHeapify(smallest);
	}
}

int MinHeap::deletemin()
{
	int root = harr[0];
	harr[0] = harr[curheapsize-1];
	curheapsize--;
	minHeapify(0);

	return root;

}

void MinHeap::deletekey(int i)
{
	updatevalue(i, INT_MIN);
	deletemin();
}

void MinHeap::printHeap()
{
	cout<<"Printing Heap : "<<endl;
	for(int i=0 ; i<=curheapsize-1 ; ++i)
		cout<<harr[i]<<" ";
}

bool MinHeap::IsHeapEmpty()
{
	return curheapsize==0 ; 
}

int MinHeap::getHeapsize()
{
	return curheapsize;
}


void main()
{

	MinHeap h(13);

	for(int i=12 ; i>=1 ; --i)
		h.insertkey(i);

	h.printHeap();
	
	// TESTING - deletemin()

	cout<<"\n\nHeap Sort : "<<endl;

	while(!h.IsHeapEmpty())
	{
		cout<<h.deletemin()<<" ";
	}

	// TESTING - deletekey()

	for(int i=12 ; i>=1 ; --i)
		h.insertkey(i);

	for(int i=11 ; i>=2 ; i-=2)
		h.deletekey(i);

	cout<<"\n\nHeap Sort : "<<endl;

	while(!h.IsHeapEmpty())
	{
		cout<<h.deletemin()<<" ";
	}

	// TESTING - updatevalue()


	cin.get();
	cin.get();

}