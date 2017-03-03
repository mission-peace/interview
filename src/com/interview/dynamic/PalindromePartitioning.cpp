// Dynamic Programming Solution for Palindrome Partitioning Problem
#include <stdio.h>
#include <string.h>
#include <limits.h>

// A utility function to get minimum of two integers
int min (int a, int b) { return (a < b)? a : b; }

// Returns the minimum number of cuts needed to partition a string
// such that every part is a palindrome
int minPalPartion(char *str)
{
	// Get the length of the string
	int n = strlen(str);

	/* Create two arrays to build the solution in bottom up manner
	C[i] = Minimum number of cuts needed for palindrome partitioning
				of substring str[0..i]
	P[i][j] = true if substring str[i..j] is palindrome, else false
	Note that C[i] is 0 if P[0][i] is true */
	int C[n];
	bool P[n][n];

	int i, j, k, L; // different looping variables

	// Every substring of length 1 is a palindrome
	for (i=0; i<n; i++)
	{
		P[i][i] = true;
	}

	/* L is substring length. Build the solution in bottom up manner by
	considering all substrings of length starting from 2 to n. */
	for (L=2; L<=n; L++)
	{
		// For substring of length L, set different possible starting indexes
		for (i=0; i<n-L+1; i++)
		{
			j = i+L-1; // Set ending index

			// If L is 2, then we just need to compare two characters. Else
			// need to check two corner characters and value of P[i+1][j-1]
			if (L == 2)
				P[i][j] = (str[i] == str[j]);
			else
				P[i][j] = (str[i] == str[j]) && P[i+1][j-1];
		}
	}

	for (i=0; i<n; i++)
	{
		if (P[0][i] == true)
			C[i] = 0; // zero cuts needed for palindrome
		else
		{
			C[i] = INT_MAX;
			for(j=0;j<i;j++)
			{   // keep minimum palindrome
				if(P[j+1][i] == true && 1+C[j]<C[i])
					C[i]=1+C[j];
			}
		}
	}

	// Return the min cut value for complete string. i.e., str[0..n-1]
	return C[n-1];
}

// Driver program to test above function
int main()
{
char str[] = "ababbbabbababa";
printf("Min cuts needed for Palindrome Partitioning is %d",
		minPalPartion(str));
return 0;
}
