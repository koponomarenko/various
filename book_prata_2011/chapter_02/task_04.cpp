#include <iostream>
using namespace std;

/*
	Write a program that asks the user to enter his or her age.The program then should display the age in months:
	Enter your age: 29
	Your age in months is 384.
*/

void task_04() // let it be kind a main func
{
	short nAgeInYears = 0;
	
	cout<<"Enter your age: ";
	
	while (!(cin >> nAgeInYears))
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout<<"Incorrect input! Try again: ";
	}

	cout<<"Your age in months is "<<nAgeInYears * 12<<"."<<endl;
}