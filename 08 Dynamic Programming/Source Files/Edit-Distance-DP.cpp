#include<iostream>
using namespace std;

int EditDistance(char *str1,int m,char *str2,int n)
{
	if(m==0)
		return n;
	if(n==0)
		return m;
	if(str1[m-1]==str2[n-1])
		return EditDistance(str1,m-1,str2,n-1);
	else
		return 1+min(EditDistance(str1,m,str2,n-1),
			min(EditDistance(str1,m-1,str2,n),
				EditDistance(str1,m-1,str2,n-1)));

}

int EditDistance(char *str1,char *str2)
{
	int m = strlen(str1);
	int n = strlen(str2);
	int **ED = new int*[m+1]();
	for(int i=0 ; i<=m ; i++)
		ED[i] = new int[n+1];

	for(int i=0 ; i<=m ; i++)
	{
		for(int j=0 ; j<=n ; j++)
		{
			if(i==0)
				ED[i][j] = j;
			else if(j==0)
				ED[i][j] = i;
			else if(str1[i]==str2[j])
				ED[i][j] = ED[i-1][j-1];
			else
				ED[i][j] = 1 + min(ED[i][j-1],
							min(ED[i-1][j],ED[i-1][j-1]));
		}
	}
	int editdistance = ED[m][n];
	delete[] ED;
	return editdistance;
	
}

int main()
{
	char *str1 = "American Oxygen";
	char *str2 = "Austrian Cynogen";

	cout<<"\n\n using RECURSION! \n";
	cout<<"\n The total Edits to transform str1 to str2 is : "<<EditDistance(str1,strlen(str1),str2,strlen(str2));
	cout<<"\n The total Edits to transform str2 to str1 is : "<<EditDistance(str2,strlen(str2),str1,strlen(str1));

	cout<<"\n\n using TABULATION \n";
	cout<<"\n The total Edits to transform str1 to str2 is : "<<EditDistance(str1,str2);
	cout<<"\n The total Edits to transform str2 to str1 is : "<<EditDistance(str2,str1);

	cin.get();
	cin.get();
	return 0;
}