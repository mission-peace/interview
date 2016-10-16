#include<iostream>
using namespace std;

void printTowerofHanoi(int N,char fromrod, char auxrod, char  torod)
{
	if(N==1)
		cout<<"Move disk 1 from "<<fromrod<<" to "<<torod<<endl;
	else
	{
		// Whatever that is in AuxRod, move to ToRod
		printTowerofHanoi(N-1,fromrod,torod,auxrod);

		// Whatever is moved, print it
		cout<<"Move disk "<<N<<" from "<<fromrod<<" to "<<torod<<endl;

		// Whatever that is in AuxRod, move to FromRod
		printTowerofHanoi(N-1,auxrod,fromrod,torod);
	}
}

int main()
{
	int N = 5;

	printTowerofHanoi(N,'A','B','C');

	cin.get();
	cin.get();
	return 0;
}