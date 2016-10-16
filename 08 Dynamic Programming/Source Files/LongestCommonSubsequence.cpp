#include<iostream>
using namespace std;

int LCS(char *A,char *B,int n,int m)
{
	int **LCS = new int*[m]();

	for(int i=0 ; i<=m-1 ; i++)
		LCS[i] = new int[n]();


	for(int i=n-1 ; i>=0 ; i--)
	{
		for(int j=m-1 ; j>=0 ; j--)
		{
			if(i==n-1 || j==m-1)
				LCS[i][j] = 0;
			else if(A[i]==B[j])
				LCS[i][j] = 1+LCS[i+1][j+1];
			else
				LCS[i][j] = max(LCS[i][j+1],LCS[i+1][j]);
		}
	}

	for(int i=0 ; i<=m-1 ; i++)
	{
		if(i==0)
			{ cout<<"  "; for(int k=0 ; k<=n-1 ; cout<<A[k]<<" ",k++); cout<<endl; }
		for(int j=0 ; j<=n-1 ; j++)
		{
			if(j==0)
				{  cout<<B[i]; cout<<" ";}
			cout<<LCS[i][j]<<" ";
		}
		cout<<endl;
	}

	int res = LCS[0][0];

	//for(int i=m ; i>=0 ; i--)
		//delete [] LCS[i];
	delete []LCS;

	return res;
}

int LCW(char *A,char *B,int n,int m)
{
	int **LCW = new int*[m]();

	for(int i=0 ; i<=m-1 ; i++)
		LCW[i] = new int[n]();

	int maxlen = -1;

	for(int i=n-1 ; i>=0 ; i--)
	{
		for(int j=m-1 ; j>=0 ; j--)
		{
			if(A[i]==B[j])
				LCW[i][j] = 1 + LCW[i+1][j+1];

			maxlen = max(maxlen,LCW[i][j]);
		}
	}


	for(int i=0 ; i<=m-1 ; i++)
	{
		if(i==0)
			{ cout<<"  "; for(int k=0 ; k<=n-1 ; cout<<A[k]<<" ",k++); cout<<endl; }
		cout<<B[i]; cout<<" ";

		for(int j=0 ; j<=n-1; j++)
		{
			cout<<LCW[i][j]<<" ";
		}
		cout<<endl;
	}

	delete []LCW;
	return maxlen;
}

int LPS(char *E,int n)
{
	int **LPS = new int*[n]();

	for(int i=0 ; i<=n-1 ; i++)
		LPS[i] = new int[n]();

	for(int i=n-1 ; i>=0 ; i--)
	{
		for(int j=n-1 ; j>= 0 ; j--)
		{
			if(i==n-1 || j==n-1)
				LPS[i][j] = 0;
			else if(E[i]==E[j])
			{
			}
		}
	}
	return LPS[n][n];
}

int main()
{

	char A[] = "AGGTAB";
	char B[] = "GXTXAYB";

	cout<<"\n\nThe length of Longest Subsequence : "<<LCS(A,B,strlen(A)+1,strlen(B)+1);
	cout<<endl<<endl;

	char C[] = "Geeksd";
	char D[] = "aGeekgsdfs";
	
	cout<<"\n\nThe length of Longest SubWord : "<<LCW(C,D,strlen(C)+1,strlen(D)+1);
	cout<<endl<<endl;


	char E[] = "Geeks for Geeks";	
	cout<<"\n\nThe length of Longest Palindrome Subsequence is  : "<<LPS(E,strlen(E)+1);
	cout<<endl<<endl;

	cin.get();
	cin.get();
	return 0;
}