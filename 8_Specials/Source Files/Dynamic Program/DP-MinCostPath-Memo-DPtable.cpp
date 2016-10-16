#include<iostream>
#define ROW 3
#define COL 3
using namespace std;

int mini(int i,int j,int k)
{
	int smallest = i;

	if(i < j)
		smallest = i;
	else
		smallest = j;
	if(k < smallest)
		smallest = k;

	return smallest;	
}

int MinCostPath_REC(int grid[][COL],int i,int j)
{
	if(i==0 && j==0)
		return grid[0][0];
	if(i<0 || j<0 || i>ROW-1 || j>COL-1)
		return 999999;
	else
		return grid[i][j] + mini(MinCostPath_REC(grid,i-1,j-1),
									MinCostPath_REC(grid,i-1,j),
										MinCostPath_REC(grid,i,j-1));

}

int MinCostPath_MEMO(int grid[][COL],int memo[][COL],int i,int j)
{
	if(memo[i][j])
		return memo[i][j];
	if(i==0 && j==0)
		return grid[0][0];
	if(i<0 || j<0 || i>ROW-1 || j>COL-1)
		return 999999;

	memo[i][j] = grid[i][j] + mini(MinCostPath_MEMO(grid,memo,i-1,j-1),
									MinCostPath_MEMO(grid,memo,i,j-1),
										MinCostPath_MEMO(grid,memo,i-1,j));
	return memo[i][j];
}

int MinCostPath_DP(int grid[][COL])
{
	int dptable[ROW][COL];

	int i,j;

	dptable[0][0] = grid[0][0];

	for(i=1 ; i<=ROW-1 ; i++)
		dptable[i][0] = dptable[i-1][0] + grid[i][0];
	for(j=1 ; j<=COL-1 ; j++)
		dptable[0][j] = dptable[0][j-1] + grid[0][j];
	for(i=1 ; i<=ROW-1 ; i++)
		for(j=1 ; j<=COL-1 ; j++)
			dptable[i][j] = grid[i][j] + mini(dptable[i-1][j-1],dptable[i][j-1],dptable[i-1][j]);

	return dptable[2][2];
}

int main()
{
	int grid[ROW][COL] = {	{1, 2, 3},
							{4, 8, 2},
							{1, 5, 3}  };

	cout<<"\n The Minimum cost to reach m,n is (RECURSION) : "<<MinCostPath_REC(grid,ROW-1,COL-1)<<endl;

	int memo[ROW][COL];
	for(int i=0 ; i<=ROW-1 ; i++)
		for(int j=0 ; j<=COL-1 ; j++)
			memo[i][j] = 0;

	cout<<"\n The Minimum cost to reach m,n is (MEMOIZATION) : "<<MinCostPath_MEMO(grid,memo,ROW-1,COL-1)<<endl;

	cout<<"\n The Minimum cost to reach m,n is (DYNAMIC PROGRAMMING) : "<<MinCostPath_DP(grid)<<endl;

	cin.get();
	cin.get();
	return 0;
}