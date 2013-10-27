#include <iostream>
using namespace std;

/*
	Write a program that asks the user to enter the number of seconds as an integer value (use type long,or,if available,long long) 
	and that then displays the equivalent time in days, hours, minutes, and seconds. 
	Use symbolic constants to represent the number of hours in the day, the number of minutes in an hour,and the number of seconds in a minute.
	The output should look like this:
	Enter the number of seconds: 31600000
	31600000 seconds = 365 days, 17 hours, 46 minutes, 40 seconds
*/

void task_04() // let it be kind a main func
{
	const short cSecondsInMinute = 60;
	const short cMinutesInHour = 60;
	const short cHoursInDay = 24;

	cout<<"Please enter the number of seconds _\b";
	unsigned long long nNumbOfSeconds = 0;
	cin>>nNumbOfSeconds;

	unsigned long long nRemainder = nNumbOfSeconds;

	short nSec = nRemainder % cSecondsInMinute;

	nRemainder /= cSecondsInMinute; // convert to minutes
	short nMinutes = nRemainder % cMinutesInHour;

	nRemainder /= cMinutesInHour; // convert to hours
	short nHours = nRemainder % cHoursInDay;

	nRemainder /= cHoursInDay; // convert to days
	short nDays = (short)nRemainder;

	cout<<nNumbOfSeconds<<" seconds = "<<nDays<<" days, "<<nHours<<" hours, "<<nMinutes<<" minutes, "<<nSec<<" seconds.\n";
}