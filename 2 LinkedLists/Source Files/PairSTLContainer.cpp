#include<iostream>
#include<string>
#include<utility>

using namespace std;

void main()
{
	pair<int,string> emp(6,"Prasa");

	string name = emp.second;

	pair<pair<int,string>,int> empcard(emp,24);

	cout<<empcard.first.first<<empcard.first.second<<empcard.second++;


	cin.get();
	cin.get();
}