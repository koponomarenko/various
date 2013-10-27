#include <iostream>
using namespace std;

/*
	Write a program that asks the user to enter an hour value and a minute value.
	The main() function should then pass these two values to a type void function 
	that displays the two values in the format shown in the following sample run:
	Enter the number of hours: 9
	Enter the number of minutes: 28
	Time: 9:28
*/

inline void ShowTime(int nHours, int nMinutes)
{
	cout<<"Time: "<<nHours<<':'<<nMinutes<<endl;
}

void task_07() // let it be kind a main func
{
	const short cMinutesInHour = 60;
	int nHours = 0, nMinutes = 0;

	cout<<"Enter the number of hours: ";
	while (!(cin >> nHours) || nHours < 0)
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout<<"Incorrect input! Try again: ";
	}

	cout<<"Enter the number of minutes: ";
	while (!(cin >> nMinutes) || nMinutes < 0)
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout<<"Incorrect input! Try again: ";
	}

	if (nMinutes >= cMinutesInHour)
	{
		nHours += nMinutes / cMinutesInHour;
		nMinutes %= cMinutesInHour;
	}

	ShowTime(nHours, nMinutes);
}
