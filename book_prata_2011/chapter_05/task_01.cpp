#include <iostream>
using namespace std;

/*
	Write a program that requests the user to enter two integers.The program should
	then calculate and report the sum of all the integers between and including the two
	integers. At this point,assume that the smaller integer is entered first.For example,if
	the user enters 2and9,the program should report that the sum of all the integers
	from 2 through 9 is 44.
*/

void task_01() // let it be kind a main func
{
	cout<<"Enter first integer: ";
	int nDigit1 = 0;
	cin>>nDigit1;
	while (!cin)
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout<<"Incorrect input. Try again: ";
		cin>>nDigit1;
	}

	cout<<"Enter second integer: ";
	int nDigit2 = 0;
	cin>>nDigit2;
	while (!cin)
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout<<"Incorrect input. Try again: ";
		cin>>nDigit2;
	}

	int nSum = 0;
	while (nDigit1 <= nDigit2)
	{
		nSum += nDigit1;
		++nDigit1;
	}

	cout<<endl;
	cout<<"Sum = the sum of all the integers"<<endl
		<<"between and including the two integers: "<<nSum<<endl;
}