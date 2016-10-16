#include <stdio.h>
#include <conio.h>
#include <vector>
#include <string.h>
#include <iostream>

using namespace std;
void main()
{













	/*
	//string str ("HelloWorldIamsofat");
	char d[] = "mmmmmmmmmNm";
	char *p = d;
	char *q = p+1;
	bool anyXORdone;

	while(*(p+1) != '\0')
	{
		anyXORdone = false;

		while(*q != '\0')
		{
			if(*q==*p)
			{
				*q = *p ^ *q;
				anyXORdone = true;
			}
			q++;
		}
		if(!anyXORdone)
		{
			cout<<"First Non occuring character in the string : "<<*p;
			break;
		}
		else
			*p^=*p;		

		while(!*p)
			p++;
		q=p+1;

	}

	*/



	getch();

}

/*
Algorithm :

Step1 : Assign two pointers such that they point next to each other
Step2 : Increment 2ndP till end and perform xor for every match
Step3 : If XOR was performed, then perform XOR of the 1st with itself, 
			//i.e we are NULLing the duplicates starting from the first char
Step4 : Go to the first character of the string which is not NULL
Step5 : Now perform from Step1


*/