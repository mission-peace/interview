#include<iostream>
using namespace std;

void printSequence(int *arr,int N)
{
	for(int i=0 ; i<=N-1 ; i++)
	{
		cout<<arr[i]<<"\n";
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

void mergeArrays(int **job,int seq[],int l,int m,int r)
{
	int n1 = m-l+1;
	int n2 = r-m;

	int **jobA = new int*[n1];
	for(int i=0; i<=n1-1 ; i++)
		jobA[i] = new int[2];

	int **jobB = new int*[n2];
	for(int i=0 ;i<=n2-1;i++)
		jobB[i] = new int[2];

	int *seqA = new int[n1];
	int *seqB = new int[n2];

	for(int a=0 ; a<=n1-1 ; a++)
	{
		jobA[a][0] = job[a+l][0];
		jobA[a][1] = job[a+l][1];

		seqA[a]=seq[a+l];
	}

	for(int a=0 ; a<=n2-1 ;a++)
	{
		jobB[a][0] = job[a+m+1][0];
		jobB[a][1] = job[a+m+1][1];

		seqB[a]=seq[a+m+1];
	}

	int i=0,j=0,k=l;
	bool firstjobfirst = true;
	while(i<=n1-1 && j<=n2-1)
	{
		firstjobfirst = Compare2Jobs(jobA[i][0],jobA[i][1],jobB[j][0],jobB[j][1]);

		if(firstjobfirst)
		{
			job[k][0] =jobA[i][0];
			job[k][1] =jobA[i][1];

			seq[k++] = seqA[i++];
		}
		else
		{
			job[k][0] =jobB[j][0];
			job[k][1] =jobB[j][1];

			seq[k++] = seqB[j++];
		}
	}

	while(i<=n1-1)
	{
			job[k][0] =jobA[i][0];
			job[k][1] =jobA[i][1];

			seq[k++] = seqA[i++];
	}

	while(j<=n2-1)
	{
			job[k][0] =jobB[j][0];
			job[k][1] =jobB[j][1];

			seq[k++] = seqB[j++];
	}


}

void MergeSort(int **job,int seq[],int left,int right)
{
	int mid;

	if(left < right)
	{
		mid = ((right+left-1)/2);
		MergeSort(job,seq,left,mid);
		MergeSort(job,seq,mid+1,right);
		mergeArrays(job,seq,left,mid,right);
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

	MergeSort(jobarr,seqarr,0,N-1);
	printSequence(seqarr,N);

	cin.get();
	cin.get();
	return 0;
}