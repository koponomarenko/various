#include <iostream>
using namespace std;

/*
	You sell the book C++ for Fools. Write a program that has you enter a year’s worth
	of monthly sales (in terms of number of books, not of money).The program should
	use a loop to prompt you by month,using an array of char *(or an array of
	stringobjects,if you prefer) initialized to the month strings and storing the input
	data in an array of int.Then,the program should find the sum of the array con-
	tents and report the total sales for the year.
*/

void task_05() // let it be kind a main func
{
	const int cMonthNumb = 12;

	char  * arrMonth[cMonthNumb] =
	{
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"
	};

	int arrSales[cMonthNumb] = {0};
	long nSum = 0; // total sales for the year


	cout<<"Enter a year worth of monthly sales\n";
	for (int i = 0; i < cMonthNumb; ++i)
	{
		cout<<arrMonth[i]<<": ";
		cin>>arrSales[i];
		while (!cin)
		{
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout<<"Incorrect input. Try again: ";
			cin>>arrSales[i];
		}

		nSum += arrSales[i];
	}

	cout<<endl;
	cout<<"Total sales for the year: "<<nSum<<endl;
}
