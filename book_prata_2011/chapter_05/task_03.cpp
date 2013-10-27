#include <iostream>
using namespace std;

/*
	Write a program that asks the user to type in numbers. After each entry,the pro-
	gram should report the cumulative sum of the entries to date.The program should
	terminate when the user enters 0.
*/

void task_03() // let it be kind a main func
{
	long nSum = 0, nDigit = 0;

	cout<<"Enter \"0\" to stop\n\n";

	do
	{
		cout<<"Enter digit: ";
		cin>>nDigit;
		while (!cin)
		{
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout<<"Incorrect input. Try again: ";
			cin>>nDigit;
		}

		nSum += nDigit;
		cout<<"Total sum is "<<nSum<<endl;
	} while (nDigit != 0);
}