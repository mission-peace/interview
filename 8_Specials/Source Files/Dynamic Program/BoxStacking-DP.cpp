#include<iostream>
#include<algorithm>
using namespace std;

struct Box
{
	int H;
	int D;
	int W;
};

void rotateBoxnCopy(Box dump[],Box box,int boxi)
{
	boxi = 3*boxi;

	dump[boxi] = box;
	boxi++;

	dump[boxi].H = box.D;
	dump[boxi].D = box.W;
	dump[boxi].W = box.H;
	boxi++;

	dump[boxi].H = box.W;
	dump[boxi].D = box.H;
	dump[boxi].W = box.D;
}

int compare_fnObj(const void *box1,const void *box2)
{
	return (*(Box *)box2).W * (*(Box *)box2).D - (*(Box *)box1).W * (*(Box *)box1).D ;
}

void constructMaxHeightStack(Box dump[],int N)
{
	// maxHS => maximum height possible with ith box on top!
	int *maxHS = new int[N];

	for(int i=0 ; i<=N-1 ; i++)
		maxHS[i] = dump[i].H;

	for(int i=1 ; i<=N-1 ; i++)
	{
		// Ex., for i=3, 4th box, only 3 boxes at the bottom are possible! we check, which 4+1 / 4+2 / 4+3 generates maximum height!
		// We should also check 4+1+2 / 4+2+3 / 4+1+3 / 4+1+2+3. But we need not because we check for maximum 
		// using maxHS[j] instead of dump[j].H+dump[i].H

		for(int j=0 ; j<=i-1 ; j++)
		{
			// Ex., for i=3, Either keep only the 4th box on top or 0th box on top + 4th box's height
			if(dump[j].W > dump[i].W && dump[j].D > dump[i].D && maxHS[i] < maxHS[j]+dump[i].H)
				maxHS[i] = maxHS[j]+dump[i].H;  
		}
	}
	int maxHeightStack=-1;
	for(int i=0 ; i<=N-1 ; i++)
		maxHeightStack = max(maxHeightStack,maxHS[i]);
	cout<<"The Maximum Height Stack possible is : "<<maxHeightStack;
}


void StacktheBox(Box tin[],int n,bool rotationsallowed=true)
{
	int N;
	Box *dump;
	if(rotationsallowed)
	{
		N = 3*n;
		dump = new Box[N];

		for(int i=0 ; i<=n-1 ; i++)
			rotateBoxnCopy(dump,tin[i],i);
		
	}
	else
	{
		N = n;
		dump = new Box[N];

		for(int i=0 ; i<=n-1 ; i++)
			dump[i] = tin[i];

	}
	qsort(dump,N,sizeof(dump[0]),compare_fnObj);
	constructMaxHeightStack(dump,N);
}



int main()
{
	Box tin[] = {{4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32}};
	int n = sizeof(tin)/sizeof(tin[0]);

	cout<<"\nRotations allowed or not?\n1. Yes 2.No\n";
	bool rotationsallowed = true;
	int option;
	cin>>option;
	if(option==2)
		rotationsallowed=false;

	StacktheBox(tin,n,rotationsallowed);

	cin.get();
	cin.get();
	return 0;
}