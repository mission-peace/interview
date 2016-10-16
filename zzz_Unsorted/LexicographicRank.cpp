#include<iostream>
#include<cstring>
using namespace std;

static int count;
void swap(char *a,char *b)
{
	if(a!=b)
	{
		char temp = *a;
		*a = *b;
		*b = temp;
	}
}

void printPerms(char word[],int si,int ei)
{
	if(si==ei)
	{
		cout<<word<<endl;
		count++;
	}
	else
	{
		for(int i=si ; i<=ei ; i++)
		{
			swap(&word[si],&word[i]);
			printPerms(word,si+1,ei);
			swap(&word[si],&word[i]);
		}
	}
}

int main()
{
	char word[] = "ABCDEF";
	printPerms(word,0,strlen(word)-1);
	cout<<"The total no. of perms is : "<<count<<endl;

	cin.get();
	cin.get();
	return 0;
}