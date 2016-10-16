#include<iostream>
using namespace std;

bool isChar(char a)
{
	int x = a-'a';
	return (x>=0 && x<=26);
}

void Swap(char *a,char *b)
{
	if(a!=b)
	{
		char temp = *a;
		*a = *b;
		*b = temp;
	}
}

void reverseNotSpecial(char *si,char *ei)
{
	if(si>=ei)
		return;
	if(isChar(*si) && !isChar(*ei))
		reverseNotSpecial(si,ei-1);
	if(!isChar(*si) && isChar(*ei))
		reverseNotSpecial(si+1,ei);
	if(isChar(*si) && isChar(*ei))
	{
		Swap(si,ei);
		reverseNotSpecial(si+1,ei-1);
	}
}

void reverseNotSpecial(char *str)
{
	char *si=str;
	char *ei=str+strlen(str)-1;

	reverseNotSpecial(si,ei);

	
}

int main()
{
	char str[] = "ab,c,de!$";

	cout<<str<<endl;
	reverseNotSpecial(str);
	cout<<endl<<str;

	cin.get();
	cin.get();
	return 0;
}