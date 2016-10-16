#include<iostream>
#include "helpers.h"
using namespace std;


void main()
{
	unsigned int playerscount = 0;
	cout<<"\nHow many players are playing ? Please enter the number! ";
	cin>>playerscount;
	
	
	while(!HELP::validateplayerscount(playerscount))
	{
		cout<<"\nInvalid players! Enter a valid number!\n";
		cin>>playerscount;
	}

	cout<<"No of PLayers : "<<playerscount;
	
	

	cin.get();
	cin.get();
	//BOARD players;
}