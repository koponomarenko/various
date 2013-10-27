#include <iostream>
#include <string>
using namespace std;

/*
	Rewrite Listing 4.4, using the C++ string class instead of char arrays.
*/

void task_02() // let it be kind a main func
{
	cout<<"Enter your name:\n";
	string sName;
	getline(cin, sName);
	
	cout<<"Enter your favorite dessert:\n";
	string sDessert;
	getline(cin, sDessert);

	cout<<"I have some delicious "<<sDessert;
	cout<<" for you, "<<sName<<".\n";
}