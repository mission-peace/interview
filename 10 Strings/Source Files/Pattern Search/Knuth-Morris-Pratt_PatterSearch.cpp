#include<iostream>
using namespace std;

void getLongPreSuf(char *,int *);

void KMPpatternsearch(char str[],char pat[])
{
	int N = strlen(str);
	int M = strlen(pat);

	// Step 1 - Preprocess the pattern
	int *LPS = new int[M]();
	getLongPreSuf(pat,LPS);
	int res=false;
	int i=0,j=0;
	for( ; i<=N-1 ; )
	{
		// Step 2 - If text and pattern match, then just increment the count 
		if(str[i]==pat[j])
		{
			i++;
			j++;
		}
		// Step 3 - If j==M, then we have matched everything of the pattern! print it!
		if(j==M)
		{
			cout<<"\nThe pattern '"<<pat<<"' is found at index : "<<i-M<<" \nof the the string '"<<str<<"'\n";
			// Step 4 - This is just resetting the search! There are chances we need to continue after 1st match to check further matches
			// refer step 6 for finer details!
			j = LPS[j-1];
			res = true;
		}

		if(str[i]!=pat[j])
		{
			// Step 5 : If j is 0, i.e at the start, just increment j without incrementing i
			if(j==0)
				i++;
			// Step 6 : If j is not 0, this is where the magic occurs! we need not check the match again starting from 0 of j
			// we can just skip how much ever j is till now!, i.e, prefix is already matched, prefix is already present in the text
			// Thus, "skip how much ever j has grown till now", i.e, j = LPS[j] technically, instead of j++!
			// since we use indexing from 0, it is j = LPS[j-1]
			else
				j = LPS[j-1];
		}
	}

	if(!res)
		cout<<"The pattern '"<<pat<<"' is not present in the string : "<<str<<"'";

}

void getLongPreSuf(char pat[],int LPS[])
{
	int M = strlen(pat);

	int i=1,len=0;

	// Step 7 - How to preprocess! Preprocessing is exactly same as pattern matching, ie, steps 2-6, but instead of
	// 2 strings, we perfrom KMP for the pattern itself, i.e, for a single string!
	for( ; i<=M-1 ; )
	{
		if(pat[i]==pat[len])
		{
			LPS[i] = ++len;		//	pat = "AAAAA" - LPS = {0,1,2,3,4}
			i++;
		}
		else
		{
			if(len==0)			//	pat = "ABCDE" - LPS = {0,0,0,0,0}
			{
				LPS[i] = len;
				i++;
			}
			else
			{
				len = LPS[len-1];	//	pat = "AAACAAA" - LPS = {0,1,2,0,1,2,3}, i.e,
									// in the event of mismatch, LPS[i] must be assigned a value
									// which is basically 'subtracting how long len has grown' till now!
			}
		}
	}

}

int main()
{
	char *str = "ABABDABACDABABCABAB";
	char *pat = "ABABCABAB";

	KMPpatternsearch(str,pat);

	cin.get();
	cin.get();
	return 0;
}