#include<iostream>
#define max(a,b) (a>b ? a:b)
#define min(a,b) (a<b ? a:b)
using namespace std;

int OptimalStrategytoWinGame(int arr[],int i,int j)
{
	if(i==j)			// If there is just 1 coin, return its value
		return arr[i];
	if(i+1==j)			// If there are 2 coins, return the maximum out of them
		return max(arr[i],arr[j]);
	// You have 2 'Recursive Options', everytime, you can choose either 1st or last
	// The opponent chooses first/last such that you get the minimum
	// Hence, your choose whichever recursive option is the maximum! ;) Hence solved!
	// F(i,j) = Function to choose maximum amounts between i and j
	// F(i,j) = MAX( Vi+ MIN( F(i+2,j),F(i+1,j-1) )	, Vj+ MIN( F(i+1,j-1), F(i,j-2) )	)
	return max((arr[i]+min(OptimalStrategytoWinGame(arr,i+2,j),OptimalStrategytoWinGame(arr,i+1,j-1))),
				(arr[j]+min(OptimalStrategytoWinGame(arr,i+1,j-1),OptimalStrategytoWinGame(arr,i,j-2)))) ;
}

int OptimalStrategytoWinGame(int arr[],int n)
{
	int **table = new int*[n]();
	for(int i=0 ; i<=n-1 ; i++)
		table[i] = new int[n]();
	// Since table[i][j] -> max amount we can win from ith coin till jth coin
	// we need to find table[0][n-1] and return it!
	for(int coin=0 ; coin<=n-1 ; coin++)
	{
		for(int i=0,j=coin; j<=n-1 ; i++,j++)
		{
			if(i==j)
				table[i][j] = arr[i];
			else if(i+1==j)
				table[i][j] = max(arr[i],arr[j]);
			else
			{
	// We know that i must always be lesser than j!
	// table[4][0] makes no sense because table[4][0] is maximum amount possible from 4th coin till 0th coin! :(
	// check every table[a][b] satisfies a<=b!
	//int x = (i+2 <= j) ? table[i+2][j] : 0;
	//int y = (i+1 <= j-1) ? table[i+1][j-1] : 0;
	//int z = (i <= j-2) ? table[i][j-2] : 0;
	// Twist is that, we don't need the above code! Since we fill the UPPER DIAGONAL MATRIX only, i is always lesser than j!
				table[i][j] = max( arr[i]+min(table[i+2][j],table[i+1][j-1]), arr[j]+min(table[i+1][j-1],table[i][j-2])	 );
			}
		}
	}
	return table[0][n-1];
}

int main()
{
	int arr[] = {20, 30, 2, 2, 2, 10};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout<<"\nThe Maximum Possible Amount you can win is (RECURSION) : "<<OptimalStrategytoWinGame(arr,0,n-1);
	cout<<"\nThe Maximum POssible AMount you can win is (DYNAMIC PROGRAMMING) : "<<OptimalStrategytoWinGame(arr,n);

	cin.get();
	cin.get();
	return 0;
}