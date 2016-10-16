#include<iostream>
#include<iomanip>
#define N 8
using namespace std;

void printArray(int board[][N])
{
	cout<<"\nThe Chess Board is :\n";
	for(int i=0 ; i<=N-1 ; i++)
	{
		for(int j=0 ; j<=N-1 ; j++)
		{
			cout<<setw(2)<<board[i][j]<<"  ";
		}
		cout<<endl;
	}
}

bool isSafe(int board[][N],int x,int y)
{
	return (x>=0 && x<=N-1 && y>=0 && y<=N-1 && board[x][y]==0) ;
}

bool SolveKnightsTour(int board[][N],int nextx[N],int nexty[N],int moveindex,int curx,int cury)
{
	if(moveindex==N*N)
		return true;
	else
	{
		for(int i=0 ; i<=8-1 ; i++)	// 8 = No. of possible moves for a Horse(Knight), since we used N to denote no. of rows n cols, lets not use N-1
		{
			if(isSafe(board,curx+nextx[i],cury+nexty[i]))
			{
				board[curx+nextx[i]][cury+nexty[i]] = moveindex;

				if( SolveKnightsTour(board,nextx,nexty,moveindex+1,curx+nextx[i],cury+nexty[i]) ) 
					return true;
				else
				{
					board[curx+nextx[i]][cury+nexty[i]] = 0;
					//return false;
				}
			}
		}
	}
	return false;

}

int main()
{
	int board[N][N];

	for(int i=0 ; i<=N-1 ; i++)
		for(int j=0 ; j<=N-1 ; j++)
			board[i][j] = 0;

	board[0][0] = 1;

	int nextx[8] = {-2,-2,-1,1,2,2,1,-1};
	int nexty[8] = {-1,1,2,2,1,-1,-2,-2};

	if(SolveKnightsTour(board,nextx,nexty,2,0,0))
		printArray(board);
	else
		cout<<"\n No Knight's Tour exists for this Chess Board\n";

	cin.get();
	cin.get();
	return 0;


}
