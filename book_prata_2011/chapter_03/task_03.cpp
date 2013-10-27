#include <iostream>
using namespace std;

/*
	Write a program that asks the user to enter a latitude in degrees, minutes,
	and seconds and that then displays the latitude in decimal format.
	There are 60 seconds of arc to a minute and 60 minutes of arc to a degree; represent these values with symbolic constants.
	You should use a separate variable for each input value. A sample run should look like this:
	Enter a latitude in degrees, minutes, and seconds:
	First, enter the degrees: 37
	Next, enter the minutes of arc: 51
	Finally, enter the seconds of arc: 19
	37 degrees, 51 minutes, 19 seconds = 37.8553 degrees
*/

void task_03() // let it be kind a main func
{
	const short cSecondsOfArc = 60;
	const short cMinutesOfArc = 60;
	
	cout<<"Enter a latitude in degrees, minutes, and seconds\n";

	cout<<"First, enter the degrees: ";
	int nDegrees = 0;
	cin>>nDegrees;

	cout<<"Next, enter the minutes of arc: ";
	int nMinutes = 0;
	cin>>nMinutes;

	cout<<"Finally, enter the seconds of arc: ";
	int nSeconds = 0;
	cin>>nSeconds;

	double nTotalDegrees = (double(nSeconds) / cSecondsOfArc + nMinutes) / cMinutesOfArc + nDegrees;

	cout.setf(ios_base::fixed, ios_base::floatfield); // fixed-point
	cout<<nDegrees<<" degrees, "<<nMinutes<<" minutes, "<<nSeconds<<" seconds = "<<nTotalDegrees<<" degrees.\n";
}