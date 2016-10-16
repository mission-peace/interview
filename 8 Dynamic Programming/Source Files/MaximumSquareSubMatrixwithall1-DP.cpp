#include<iostream>
#define R 6
#define C 5
using namespace std;

int getMaximumSquareMatrixwithall1(bool M[][C])
{
	int dp[R][C];

	for(int i=0 ; i<=R-1; i++)
		dp[i][0] = M[i][0];
	for(int j=0 ; j<=C-1 ; j++)
		dp[0][j] = M[0][j];

	int maxdimen = -1;
	for(int i=1 ; i<=R-1 ; i++)
	{
		for(int j=1 ; j<=C-1 ; j++)
		{
			if(M[i][j]==1)
			{
				dp[i][j] = 1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
				maxdimen = max(maxdimen,dp[i][j]);
			}
			else
				dp[i][j] = 0;
		}
	}
	return maxdimen;

}

int main()
{
	bool M[R][C] ={{0, 1, 1, 0, 1}, 
                   {1, 1, 1, 1, 0}, 
                   {1, 1, 1, 1, 0},
                   {1, 1, 1, 1, 0},
                   {1, 1, 1, 1, 1},
                   {0, 0, 0, 0, 0}};

	int dimen = getMaximumSquareMatrixwithall1(M);
	cout<<dimen<<"x"<<dimen;
                
	cin.get();
	cin.get();
	return 0;
}