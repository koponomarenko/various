#include <iostream>
using namespace std;

/*
	Define a recursive function that takes an integer argument and returns the factorial
	of that argument. Recall that 3 factorial,written 3!, equals 3 ?2!, and so on,with 0!
	defined as 1.In general,if n is greater than zero, n! = n * (n - 1)!.Test your function
	in a program that uses a loop to allow the user to enter various values for which the
	program reports the factorial.
*/

int CalcFactorial(int nNumber);

void task_05() // let it be kind a main func
{
	int nNumber = 0;

	do
	{
		cout << "Enter integer number: ";
		while (!(cin >> nNumber))
		{
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "Incorrect input. Try again: ";
		}
		cin.get();
	} while (nNumber < 0);

	cout << "Factorial of the " << nNumber << ", is " << CalcFactorial(nNumber) << endl;
}


int CalcFactorial(int nNumber)
{
	if (nNumber <= 0)
		return 1;
	else
		return CalcFactorial(nNumber - 1) * nNumber;
}