#include<iostream>
#define N 9
using namespace std;

int getFreeBox(int board[][N],int *row,int *col)
{
	for(int i=0 ; i<= N-1 ; i++)
	{
		for(int j=0 ; j<= N-1 ; j++)
		{
			if(board[i][j]==0)
			{
				*row = i;
				*col = j;
				return 0;
			}
		}
	}
	return -1;
}

bool isRowSafe(int board[][N],int row,int num)
{
	for(int i=0 ; i<=N-1 ; i++)
	{
		if(board[row][i]==num)
			return false;
	}
	return true;
}

bool isColSafe(int board[][N],int col,int num)
{
	for(int i=0 ; i<=N-1 ; i++)
	{
		if(board[i][col]==num)
			return false;
	}
	return true;
}

bool isGridSafe(int board[][N],int row,int col,int num)
{
	for(int i=0 ; i<=3-1 ; i++)
	{
		for(int j=0 ; j<=3-1 ; j++)
		{
			if(board[i+row][j+col]==num)
				return false;
		}
	}
	return true;
}

bool isSafe(int board[][N],int row,int col,int num)
{
	return (isRowSafe(board,row,num) && isColSafe(board,col,num) && isGridSafe(board,row-row%3,col-col%3,num));
}

void printBoard(int board[][N])
{
	cout<<endl<<"The SUDOKO is now : \n"<<endl;

	for(int i=0 ; i<=N-1 ; i++)
	{
		cout<<"  ";
		for(int j=0 ; j<=N-1 ; j++)
		{
			cout<<board[i][j]<<" ";
			if(j+1==3 || j+1==6)
				cout<<" ";
		}
		if(i+1==3 || i+1==6)
			cout<<endl;
		cout<<endl;
	}
	cout<<endl;
}

bool solveSudoko(int board[][N])
{
	int row,col;
	if(getFreeBox(board,&row,&col)==-1)
		return true;
	else
	{
		for(int i=1 ; i<=9 ; i++)
		{
			//getFreeBox(board,row,col);
			int num = i;
			if(isSafe(board,row,col,num))
			{
				board[row][col] = num;

				if(solveSudoko(board))
					return true;
				else
					board[row][col] = 0;
			}
		}
	}
	return false;
}

int main()
{
	// WORLD's HARDEST SUDOKO 

	int board[N][N] = 
	{
		{8,0,0,0,0,0,0,0,0},
		{0,0,3,6,0,0,0,0,0},
		{0,7,0,0,9,0,2,0,0},

		{0,5,0,0,0,7,0,0,0},
		{0,0,0,0,4,5,7,0,0},
		{0,0,0,1,0,0,0,3,0},

		{0,0,1,0,0,0,0,6,8},
		{0,0,8,5,0,0,0,1,0},
		{0,9,0,0,0,0,4,0,0},
	};


	/* Rated - VERY DIFFICULT in 7sudoko.com

	int board[N][N] = 
	{
		{0,5,0,3,0,9,0,0,0},
		{1,0,0,0,0,0,9,0,5},
		{0,0,7,0,8,0,0,0,6},

		{0,2,0,0,0,0,0,4,0},
		{0,0,0,6,7,2,0,0,0},
		{0,3,0,0,0,0,0,2,0},

		{4,0,0,0,5,0,7,0,0},
		{9,0,8,0,0,0,0,0,2},
		{0,0,0,2,0,1,0,6,0},
	};
	*/
	if(solveSudoko(board))
		printBoard(board);
	else
		cout<<"\n Sorry.. No solution exists!"<<endl;

	cin.get();
	cin.get();
	return 0;
}