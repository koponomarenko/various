#include <iostream>
#include <cstring>

#include "sales.h"

namespace SALES
{
	using std::cin;
	using std::cout;
	using std::endl;

	// copies the lesser of 4 or n items from the array ar
	// to the sales member of s and computes and stores the
	// average, maximum, and minimum values of the entered items;
	// remaining elements of sales, if any, set to 0
	void setSales(Sales & s, const double ar[], int n)
	{
		const int nQuartersToFill = (n < QUARTERS) ? n : QUARTERS;

		memset(&s, 0, sizeof(Sales));

		for (int i = 0; i < nQuartersToFill; ++i)
			s.sales[i] = ar[i];


		/* calculation for: min, max, average */
		s.min = s.sales[0];
		s.max = s.sales[0];

		for (int i = 0; i < nQuartersToFill; ++i)
		{
			s.average += s.sales[i];
			
			if (s.sales[i] < s.min)
				s.min = s.sales[i];

			if (s.sales[i] > s.max)
				s.max = s.sales[i];
		}
		s.average /= nQuartersToFill;
	}



	// gathers sales for 4 quarters interactively, stores them
	// in the sales member of s and computes and stores the
	// average, maximum, and minimum values
	void setSales(Sales & s)
	{
		memset(&s, 0, sizeof(Sales));

		// just in case, clear the input buffer
		if (cin.rdbuf()->in_avail())
			cin.ignore(cin.rdbuf()->in_avail());

		for (int i = 0; i < QUARTERS; ++i)
		{
			cout << "Enter sales in " << i + 1 << " quarter: ";
			while (!(cin >> s.sales[i]))
			{
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
				cout << "Incorrect input! Try again: ";
			}
			cin.get();
		}


		/* calculation for: min, max, average */
		s.min = s.sales[0];
		s.max = s.sales[0];

		for (int i = 0; i < QUARTERS; ++i)
		{
			s.average += s.sales[i];
			
			if (s.sales[i] < s.min)
				s.min = s.sales[i];

			if (s.sales[i] > s.max)
				s.max = s.sales[i];
		}
		
		s.average /= QUARTERS;
	}



	// display all information in structure s
	void showSales(const Sales & s)
	{
		for (int i = 0; i < QUARTERS; ++i)
			cout << "Sales in " << i + 1 << " quarter: " << s.sales[i] << endl;
		cout << endl;
		cout << "min = " << s.min << endl;
		cout << "max = " << s.max << endl;
		cout << "average = " << s.average << endl;
		cout << endl;
	}
}