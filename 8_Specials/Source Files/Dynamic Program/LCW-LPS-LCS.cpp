#include<iostream>
#include<iomanip>
using namespace std;

int LCW(char *u,char *v)
{
	int m = strlen(u)+1;
	int n = strlen(v)+1;

	int **LCW = new int*[m]();
	for(int i=0 ; i<= m-1 ; i++)
		LCW[i] = new int[n]();

	for(int j=n-2 ; j>=0 ; j--)
	{
		for(int i=m-2 ; i>=0 ; i--)
		{
			if(v[j]==u[i])
				LCW[i][j] = 1  + LCW[i+1][j+1];
			else if(v[j]!=u[i])
				LCW[i][j] = LCW[i+1][j+1];
		}
	}

	int maxvar = 0;
	int x=0,y=0;

	for(int i=0 ; i<=m-1 ; i++)
	{
		for(int j=0 ; j<=n-1 ; j++)
		{
			cout<<setw(2)<<LCW[i][j]<<" ";
			if(LCW[i][j] > maxvar)
			{
				maxvar = LCW[i][j];
				x = i;
				y = j;
			}
		}
		cout<<endl;
	}

	cout<<"\n The Length of Longest Common Word is : "<<maxvar<<endl;
	cout<<"\n It occurs from "<<x<<" in 1st string\n";
	cout<<"\n It occurs from "<<y<<" in 2nd string\n";
	
	for(int i=0 ; i<=n-1 ; i++)
		delete[] LCW[i];
	delete[] LCW;
	return maxvar;
}



void LPS(char *x)
{
	int n = strlen(x)+1;
	char *y = new char[n];
	strcpy(y,x);
	strrev(y);
	y[n-1] = '\0';
	cout<<"The Longest Palindromic SubWord is of lenght : "<<LCW(x,y);
}

int LCS(char *u,char *v)
{
	int m = strlen(u)+1;
	int n = strlen(v)+1;

	int **LCS = new int*[m]();
	for(int i=0 ; i<= m-1 ; i++)
		LCS[i] = new int[n]();

	for(int j=n-2 ; j>=0 ; j--)
	{
		for(int i=m-2 ; i>=0 ; i--)
		{
			if(v[j]==u[i])
				LCS[i][j] = 1  + LCS[i+1][j+1];
			else if(v[j]!=u[i])
				LCS[i][j] = max(LCS[i][j+1],LCS[i+1][j]);
		}
	}
	int maxvar = 0;
	int x=0,y=0;

	for(int i=0 ; i<=m-1 ; i++)
	{
		for(int j=0 ; j<=n-1 ; j++)
		{
			cout<<setw(2)<<LCS[i][j]<<" ";
			if(LCS[i][j] > maxvar)
			{
				maxvar = LCS[i][j];
				x = i;
				y = j;
			}
		}
		cout<<endl;
	}
	cout<<"\n The Length of Longest Common Word is : "<<maxvar<<endl;
	cout<<"\n It occurs from "<<x<<" in 1st string\n";
	cout<<"\n It occurs from "<<y<<" in 2nd string\n";
	
	for(int i=0 ; i<=n-1 ; i++)
		delete[] LCS[i];
	delete[] LCS;
	return maxvar;

}

void isRotatedPalin(char *u)
{
	int n = strlen(u);
	char *temp = new char[n+n+1];
	strcpy(temp,u);
	strcat(temp,u);
	temp[2*n] = '\0';
	LPS(temp);
}
int main()
{
	char *str = "geeksmaforgeeks";
	char *word = "malforgeryjail";
	char *palind = "gomalayalamgo";
	char *rotatedstr = "rrada";

	cout<<"\nMention your Option! \n1. LCW \n2. LPS \n3. LCS \n4.Find if a rotated string is Palindrome\n";
	int a;
	cin>>a;
	switch(a)
	{
	case 1 :
		LCW(str,word);
		break;
	case 2 : 
		LPS(palind);
		break;
	case 3 :
		LCS(str,word);
		break;
	case 4 :
		isRotatedPalin(rotatedstr);
		break;
	case 0:
		cout<<"\nOption not there\n";
	}


	cin.get();
	cin.get();
	return 0;
}