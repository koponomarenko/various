#include <iostream>
using namespace std;

/*
	Do Exercise 5 but use a two-dimensional array to store input for 3
	years of monthly sales. Report the total sales for each individual year
	and	for the	combined years.
*/

void task_06() // let it be kind a main func
{
	const int cMonthNumb = 12;
	const int cYears = 3;

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

	int arrSales[cYears][cMonthNumb] = {0};
	long nSum = 0; // total sales for the year
	long nSumPerYear[cYears] = {0};


	cout<<"Enter a monthly sales (in terms of number of books)"<<endl;
	for (int i = 0, year = 0; i < cYears; ++i, ++year)
	{
		for (int j = 0; j < cMonthNumb; ++j)
		{
			cout<<"Year #"<<year + 1<<", "<<arrMonth[j]<<": ";
			cin>>arrSales[i][j];
			while (!cin)
			{
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
				cout<<"Incorrect input. Try again: ";
				cin>>arrSales[i][j];
			}

			nSum += arrSales[i][j];
			nSumPerYear[year] += arrSales[i][j];
		}
		cout<<endl;
	}

	cout<<endl;
	cout<<"Total sales for the years: "<<nSum<<endl;
	for (int i = 0; i < cYears; ++i)
		cout<<"Sales for the year #"<<i + 1<<": "<<nSumPerYear[i]<<endl;

	cout<<endl;
}
