#include<iostream>
#include<string>
#include<conio.h>

using namespace std;

void swap(char *p,char *q)
{	
	char temp=*p;
	*p=*q;
	*q=temp;
}


void main()
{
	char s[] = "_move__the_spaces___to_left_";

	char *p,*q;
	q=s;

	int swapcounter = 0;
	int strlen = 0;

	/* My method - BRUTEFORCE :

	if(*(q+1)!='\0')
		p=q+1;



	while(*p!='\0')
	{
		if(*p=='_')
		{
			while(*q!='_')
			{
				swap(q,q+1);
				swapcounter++;
				q--;
			}
		}
		q=p-1;
		p++;
		q++;

	}

	cout<<s<<endl;
	cout<<"Total no. of SWAPS : "<<swapcounter;
	*/

	
	p=s;
	while(*p != '\0')
	{
		strlen++;
		p++;
	}
	//cout<<"String length is : "<<strlen<<endl;

	swapcounter=0;

	int i=strlen-1;
	int j=i;

	for(;j>=0;j--)
	{
		if(s[j]!='_')
		{
			swap(&s[i--],&s[j]);
			swapcounter++;
		}
	}
	cout<<"Total no. of SWAPS : "<<swapcounter;
	cout<<endl<<s;

	getch();

	

}