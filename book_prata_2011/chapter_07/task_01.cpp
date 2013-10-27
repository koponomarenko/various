#include <iostream>
using namespace std;

/*
	Write a program that repeatedly asks the user to enter pairs of numbers until at
	least one of the pair is 0. For each pair, the program should use a function to calculate the harmonic mean of the numbers.
	The function should return the answer to main(), which should report the result.
	The harmonic mean of the numbers is the inverse of the average of the inverses and can be calculated as follows:
	harmonic mean = 2.0 * x * y / (x + y)
*/

double CalcHarmonicMean(double nNumber1, double nNumber2);

void task_01() // let it be kind a main func
{
	double nNumber1 = 0;
	double nNumber2 = 0;

	cout << "Program calculate the harmonic mean of the numbers" << endl << endl;

	do
	{
		cout << "Enter first number: ";
		while (!(cin >> nNumber1))
		{
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "Incorrect input. Try again: ";
		}
		cin.get();

		if (!nNumber1)
			break;

		cout << "Enter second number: ";
		while (!(cin >> nNumber2))
		{
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "Incorrect input. Try again: ";
		}
		cin.get();

		if (!nNumber2)
			break;

		cout << "Harmonic mean for " << nNumber1 << " and " << nNumber2 << " = " << CalcHarmonicMean(nNumber1, nNumber2) << endl << endl;
	} while (true);

	cout << endl;
}


double CalcHarmonicMean(double nNumber1, double nNumber2)
{
	return 2.0 * nNumber1 * nNumber2 / (nNumber1 + nNumber2);
}