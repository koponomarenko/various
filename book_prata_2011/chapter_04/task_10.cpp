#include <iostream>
using namespace std;

/*
	Write a program that requests the user to enter three times for the 40-yd dash (or
	40-meter,if you prefer) and then displays the times and the average. Use an array
	object to hold the data. (Use a built-in array if arrayis not available.)
*/

void task_10() // let it be kind a main func
{
	float aDachRes[3] = {0};
	double nAverage = 0;

	cout<<"Enter three times for the 40-yd dash (in seconds)\n";

	cout<<"First: ";
	cin>>aDachRes[0];

	cout<<"Second: ";
	cin>>aDachRes[1];
	
	cout<<"Third: ";
	cin>>aDachRes[2];

	cout<<endl;
	cout<<"Result of 40-yd dash: ";
	for (int i = 0; i < 3; ++i)
	{
		cout<<aDachRes[i];
		nAverage += aDachRes[i];
		if (i < 2)
			cout<<", ";
		else
		{
			nAverage /= 3;
			cout<<endl;
		}
	}
	
	cout<<"Average is "<<nAverage<<endl;
}
