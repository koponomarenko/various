#include <iostream>
using namespace std;

/*
	The Kingdom of Neutronia, where the unit of currency is the tvarp, has the fol-
	lowing income tax code:
	First 5,000 tvarps:0% tax
	Next 10,000 tvarps:10% tax
	Next 20,000 tvarps:15% tax
	Tvarps after 35,000:20% tax
	For example, someone earning 38,000 tvarps would owe 5,000 * 0.00 + 10,000 * 0.10 + 20,000 * 0.15 + 3,000 * 0.20,
	or 4,600 tvarps. Write a program that uses a
	loop to solicit incomes and to report tax owed. The loop should terminate when
	the user enters a negative number or non-numeric input.
*/

void task_05() // let it be kind a main func
{
	double nIncome = 0;
	double nTax = 0;
	double nTmpIncome = 0;

	cout << "Enter a negative number or non-numeric input for EXIT." << endl;
	cout << "Enter your income: ";
	while (cin >> nIncome && nIncome >= 0)
	{
		nTmpIncome = nIncome;
		nTax = 0;

		// First 5,000 tvarps: 0% tax
		if (nTmpIncome < 5000)
			nTmpIncome -= nTmpIncome;
		else
			nTmpIncome -= 5000;

		// Next 10,000 tvarps: 10% tax
		if (nTmpIncome < 10000)
		{
			nTax += nTmpIncome * 0.10;
			nTmpIncome -= nTmpIncome;
		}
		else
		{
			nTax += 10000 * 0.10;
			nTmpIncome -= 10000;
		}

		// Next 20,000 tvarps: 15% tax
		if (nTmpIncome < 20000)
		{
			nTax += nTmpIncome * 0.15;
			nTmpIncome -= nTmpIncome;
		}
		else
		{
			nTax += 20000 * 0.15;
			nTmpIncome -= 20000;
		}
		
		// Tvarps after 35,000: 20% tax
		if (nTmpIncome > 0)
			nTax += nTmpIncome * 0.20;

		
		cout << "Your tax is " << nTax << endl << endl;
		cout << "Enter your income: ";
	}

	cout << endl;
}
