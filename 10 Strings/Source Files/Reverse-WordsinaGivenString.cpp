#include<iostream>
using namespace std;

void Swap(char *a,char *b)
{
	if(a!=b)
	{
		char temp = *a;
		*a = *b;
		*b = temp;
	}
}

void reverseString(char *si,char *ei)
{
	while(si < ei)
	{ 
		Swap(si,ei);
		si++;
		ei--;
	}
}

void ReverseWords(char *s)
{
	char *si = s;
	char *ei = s;

	while(*ei)
	{
		ei++;

		if(*ei=='\0')
			reverseString(si,ei-1);
		else if(*ei==' ')
		{
			reverseString(si,ei-1);
			si = ei+1;
		}
	}
	reverseString(s,ei-1);
}


int main()
{
	char sentence[] = "i like this program very much";
	char *temp = sentence;
	ReverseWords(temp);
	cout<<endl<<sentence;

	cin.get();
	cin.get();
	return 0;
}