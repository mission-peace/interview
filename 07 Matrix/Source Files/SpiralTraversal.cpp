#include<iostream>
#define ROW 3
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

void SpiralTraversal(int mat[][COL])
{
	int sr = 0;
	int sc = 0;
	int er = ROW-1;
	int ec = COL-1;
	int i = 0;

	while(sr<=er && sc<=ec)
	{
		// Print Last Col
		for(i=sr ; i<=er ; i++)
			cout<<mat[i][ec]<<" ";
		ec--;

		// Print Last Row
		if(sr < er)
		{
			for(i=ec ; i>=sc ; i--)
				cout<<mat[er][i]<<" ";
			er--;
		}

		// Print First Col
		if(sc < ec)
		{
			for(i=er ; i>=sr ; i--)
				cout<<mat[i][sc]<<" ";
			sc++;
		}

		// Print First Row
		for(i=sc ; i<=ec ; i++)
			cout<<mat[sr][i]<<" ";
		sr++;
	}
}


int main()
{
	int mat[][COL]		= {	{34,36,31,39},
							{12,19,13,17},
							{28,24,26,23}	};
	
	printMatrix(mat);
	SpiralTraversal(mat);
	

	cin.get();
	cin.get();
	return 0;
}