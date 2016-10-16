#include<iostream>
#define ROW 4
#define COL 4
using namespace std;

void printMatrix(int mat[][COL],int r=ROW,int c=COL)
{
	cout<<endl; //<<"Printing Standard wise Matrix : \n";
	for(int i=0 ; i<=r-1 ; i++)
	{
		for(int j=0 ; j<=c-1 ; j++)
			cout<<mat[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;

}

void rotateMatrixinRing(int mat[][COL])
{
	int sr = 0;
	int sc = 0;
	int er = ROW-1;
	int ec = COL-1;

	int prev;
	int cur;
	int i;

	while(sr<=er && sc<=ec)
	{
		if(sr+1<=er && sc+1<=ec)
			prev = mat[sr+1][sc];
		else
			break;

		for(i=sc ; i<=ec ; i++)
		{
			cur = mat[sr][i];
			mat[sr][i] = prev;
			prev = cur;
		}
		sr++;

		for(i=sr ; i<=er ; i++)
		{
			cur = mat[i][ec];
			mat[i][ec] = prev;
			prev = cur;
		}
		ec--;


		for(i=ec ; i>= sc ; i--)
		{
			cur = mat[er][i];
			mat[er][i] = prev;
			prev = cur;
		}
		er--;

		for(i=er ; i>=sr ; i--)
		{
			cur = mat[i][sc];
			mat[i][sc] = prev;
			prev = cur;
		}
		sc++;
	}

	printMatrix(mat);
}


int main()
{
	int mat[][COL]		= {	{34,36,31,39},
							{12,19,13,17},
							{28,24,26,23},
							{43,48,42,46} };
	printMatrix(mat);
	rotateMatrixinRing(mat);
	

	cin.get();
	cin.get();
	return 0;
}