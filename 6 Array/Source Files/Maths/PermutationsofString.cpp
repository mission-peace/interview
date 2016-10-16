#include<iostream>
#include<string>
using namespace std;

void swap(char *a,char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

void Permute(char *str,int l,int r)
{
	//int i;
	if(l==r)
		cout<<str<<endl;
	else
	{
		for(int i=l ; i<=r ; i++)
		{
			swap(str+l,str+i);
			Permute(str,l+1,r);
			swap(str+l,str+i);
		}
	}
}

int main()
{
	char str[] = "ABC";
	int n = strlen(str);

	Permute(str,0,n-1);

	cin.get();
	return 0;
}