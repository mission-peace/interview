#include<iostream>
using namespace std;

void printArray(int **arr,int rowL,int colL)
{
	//cout<<"\n";
	for(int i=0 ; i<=rowL-1 ;i++)
	{
		for(int j=0 ; j<=colL-1 ; j++)
			cout<<arr[i][j];
		cout<<"\n";
	}
	//cout<<"\n";
}

void printSequence(int *arr,int N)
{
	for(int i=0 ; i<=N-1 ; i++)
	{
		cout<<arr[i]+1<<"\n";
		//if(i!=N-1)
		//	cout<<" -> ";
	}
}

bool Compare2Jobs(int a,int b,int c,int d)
{
	if(b*c >= a*d)
		return true;
	else
		return false;
}

void Swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void SwapRow(int **a,int **b)
{
	int temp;

	for(int i=0 ; i<=1 ;i++)
	{
		temp = a[0][i];
		a[0][i] = b[0][i];
		b[0][i] = temp;
	}
}

void ShoeMakersSequence(int **job,int seq[],int N)
{
	bool isjoblast = false;
	int order=0;

	seq[order++] = 0;
	for(int i=1 ; i<= N-1 ; i++)
	{
		isjoblast = Compare2Jobs(job[i-1][0],job[i-1][1],job[i][0],job[i][1]);

		if(isjoblast)
			seq[order++] = i;

		else
		{
			seq[order++] = i;
			
			for(int j=order-1 ; j>=1 ; j--)
			{
				isjoblast = Compare2Jobs(job[j-1][0],job[j-1][1],job[j][0],job[j][1]);

				if(isjoblast)
				{
					break;
				}
				else
				{
					Swap(&seq[j],&seq[j-1]);
					SwapRow(&job[j-1],&job[j]);
				}
			}

		}
	}
}


int main()
{
	//cout<<"Enter the no. of Jobs : ";
	int N;
	cin>>N;

	int **jobarr = new int*[N];
	for(int i=0 ; i<=N-1 ; i++)
		jobarr[i] = new int[2];

	//cout<<"Enter the Days to complete and Fine per delayed day : \n";
	for(int i=0 ; i<=N-1; i++ )
	{
		for(int j=0 ; j<=1 ; j++)
		{
			cin>>jobarr[i][j];
		}
	}
	//printArray(jobarr,N,2);
	
	int *seqarr = new int[N];

	for(int i=0 ; i<=N-1 ;i++)
		seqarr[i]=i+1;
	ShoeMakersSequence(jobarr,seqarr,N);
	printSequence(seqarr,N);

	cin.get();
	cin.get();
	return 0;
}