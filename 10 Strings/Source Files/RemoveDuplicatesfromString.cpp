#include<iostream>
using namespace std;

char *removeDuplicates(char *str)
{
	bool *visited = new bool[256]();

	int ip = 0;
	int res = 0;

	while(*(str+ip))
	{
		char temp = *(str+ip);

		if(visited[temp]==0)
		{
			visited[temp] = 1;
			*(str+res) = *(str+ip);
			res++;
		}
		ip++;
	}


	*(str+res) = '\0';
	return str;
}

int main()
{
	char str[] = "geeksforGeeks";
	
	cout<<removeDuplicates(str);

	cin.get();
	cin.get();
	return 0;
}