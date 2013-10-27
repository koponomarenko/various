#include <iostream>

#include "clSales.h"

namespace SALES
{
	using std::cin;
	using std::cout;
	using std::endl;


	

	clSales::clSales(const double ar[], int n)
	{
		const int nQuartersToFill = (n < QUARTERS) ? n : QUARTERS;

		memset(aSales_, 0, sizeof(aSales_));
		nAverage_ = 0;

		if (ar != NULL)
			for (int i = 0; i < nQuartersToFill; ++i)
				aSales_[i] = ar[i];


		/* calculation for: min, max, average */
		nMin_ = aSales_[0];
		nMax_ = aSales_[0];

		for (int i = 0; i < nQuartersToFill; ++i)
		{
			nAverage_ += aSales_[i];
			
			if (aSales_[i] < nMin_)
				nMin_ = aSales_[i];

			if (aSales_[i] > nMax_)
				nMax_ = aSales_[i];
		}
		nAverage_ /= nQuartersToFill;
	}


	void clSales::Set()
	{
		double aSales[QUARTERS];

		memset(aSales, 0, sizeof(aSales));

		// just in case, clear the input buffer
		if (cin.rdbuf()->in_avail())
			cin.ignore(cin.rdbuf()->in_avail());

		for (int i = 0; i < QUARTERS; ++i)
		{
			cout << "Enter sales in " << i + 1 << " quarter: ";
			while (!(cin >> aSales[i]))
			{
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
				cout << "Incorrect input! Try again: ";
			}
			cin.get();
		}

		*this = clSales(aSales, QUARTERS);
	}


	void clSales::Show() const
	{
		for (int i = 0; i < QUARTERS; ++i)
			cout << "Sales in " << i + 1 << " quarter: " << aSales_[i] << endl;
		cout << endl;
		cout << "min = " << nMin_ << endl;
		cout << "max = " << nMax_ << endl;
		cout << "average = " << nAverage_ << endl;
		cout << endl;
	}

}