#include<stdio.h>

void printBits(unsigned int num)
{
    unsigned int totalbits = sizeof(num)*8;
    
    for(int i=totalbits-1 ; i>=0 ; i--)
    {
        if(num & (1<<i))
            printf("1");
        else
            printf("0");
    }
}

unsigned int reverseBits(unsigned int num)
{
	unsigned int count = sizeof(num) * 8 ;
	unsigned int res = 0;
	
	for(int i=0 ; i<=count-1 ; i++)
    {
        if(num & 1<<i)
            res = res | 1<< ((count-1)-i);
    }
	
	return res;
}

unsigned int getMSB(unsigned int num)
{
	unsigned int temp = 0;

	while(num)
	{
		temp = num;

		num = num & (num-1);
	}

	return temp;
}

int main()
{
	unsigned int x = 1245;

	printBits(x);
	printf(" = %u\n", x);

	/*
	int temp = x<<30;
    printf("On 3 left rotations : \n");
	printBits(temp);
	printf(" = %u\n",temp);
	*/

	int MSB = getMSB(x);
	printf("MSB of %u\n",x);
	printBits(MSB);
	printf(" = %u\n",MSB);

    x = reverseBits(x);
    
    printBits(x);
	printf(" = %u\n", x);
	
	x = reverseBits(x);
    
    printBits(x);
	printf(" = %u\n", x);
	
	getchar();
}
