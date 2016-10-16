#include<iostream>
using namespace std;

void LongestBalancedString_BruteForce(char str[],int len)
{
	int maxEvenLen = 0;
	for(int i=0 ; i<=len-2 ; i++)
	{
		for(int j=1 ; j<=len-1 ; j++)
		{
			if(j-i%2==0)
				continue;

			int resL=0;
			int resR=0;
			for(int k=i ; k<=j ; k++)
			{
				int temp = str[k]-'0';

				if(k <= (i+j)/2)
					resL += temp;
				else
					resR += temp;
			}
			if(resL==resR)
				maxEvenLen = max(maxEvenLen,j-i+1);

		}
	}
	cout<<"The Maximum Even Length is  : "<<maxEvenLen<<endl;
}

void LongestBalancedString_Polynomial(char str[],int n)
{
	int L=0;
	int R=0;

	int maxEvenLen = 0;

	for(int i=0 ; i<=n-2 ; i++)
	{
		int resL=0;
		int resR=0;
		L=i;
		R=i+1;
		cout<<i<<endl;
		while(L>=0 && R<=n-1)
		{
			resL += str[L]-'0';
			resR += str[R]-'0';
			cout<<str[L]<<" "<<str[R]<<" "<<resL<<" "<<resR<<endl;
			if(resL==resR)
				maxEvenLen = max(maxEvenLen,R-L+1);
			L--;
			R++;
		}

	}

	cout<<"The Maximum Even Length is  : "<<maxEvenLen;
}


int main()
{
	char str[] = "153803";
	int n = strlen(str);

	LongestBalancedString_BruteForce(str,n);
	LongestBalancedString_Polynomial(str,n);

	cin.get();
	cin.get();
	return 0;
}