#include<iostream>
#define N 4
using namespace std;

void printArray(bool **Board)
{
	cout<<endl;

	for(int i=0 ; i<=N-1 ; i++)
	{
		cout<<endl<<" ";
		for(int j=0 ; j<=N-1 ; j++)
			cout<<"  "<<Board[i][j]<<"  ";
	}
	cout<<endl;
}

bool isQueenSafe(bool **Board,int row,int col)
{
	for(int i=col ; i>=0 ; i--)					// Check if queens cut in the same row, include the current position too
		if(Board[row][i])
			return false;

	for(int i=row,j=col ; i>=0 && j>=0 ; i--,j--)	// Check if queens cut diagonally up, include the current position too
		if(Board[i][j])
			return false;

	for(int i=row,j=col ; i<=N-1 && j>=0 ; i++,j--)	// Check if queens cut diagonally down, include the current position too
		if(Board[i][j])
			return false;

	return true;

}


bool SolveNQueen(bool **Board,int col,bool *firsttime)
{
	if(col < N)
	{
		for(int i=0 ; i<=N-1 ; i++)
		{
			if(isQueenSafe(Board,i,col))
			{
				Board[i][col] = 1;

				if(SolveNQueen(Board,col+1,firsttime))	// Recur for next column! If it is solved, return true;
					return true;
				else
				{
					if(*firsttime)
					{
						*firsttime = false;
						printArray(Board);
					}
					Board[i][col] = 0;			// else, backtrack...
				}

			}
		}
	}
	else
		return true;	// We have solved the Board! Because here is where col = N, and we increment column, only if col-1 is solved :)

	return false;
}

int main()
{
	bool **Board = new bool*[N]();
	for(int i=0 ; i<=N-1 ; i++)
		Board[i] = new bool[N]();

	//Board[0][0] = 1;

	bool firsttime = true;

	if(SolveNQueen(Board,0,&firsttime))
		cout<<"\nIts solved, finally : !\n";
	else
		cout<<"\nSorry,No solution exist!\n";

	printArray(Board);

	cin.get();
	cin.get();
	return 0;
}

