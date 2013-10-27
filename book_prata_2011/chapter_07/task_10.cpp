#include <iostream>
using namespace std;

/*
	Design a function calculate() that takes two type doublevalues and a pointer to
	a function that takes two doublearguments and returns a double.The
	calculate() function should also be type double,and it should return the value
	that the pointed-to function calculates,using the double arguments to
	calculate(). For example,suppose you have this definition for the add()
	function:
		double add(double x, double y)
		{
			return x + y;
		}
	Then,the function call in the following would cause calculate()to pass the val-
	ues2.5and10.4to the add()function and then return the add()return value
	(12.9):
	double q = calculate(2.5, 10.4, add);
	Use these functions and at least one additional function in the add()mold in a
	program.The program should use a loop that allows the user to enter pairs of num-
	bers.For each pair,use calculate()to invoke add()and at least one other func-
	tion.If you are feeling adventurous,try creating an array of pointers to add()-style
	functions and use a loop to successively apply calculate()to a series of functions
	by using these pointers.
	Hint: Here’s how to declare such an array of three pointers:
	double (*pf[3])(double, double);
	You can initialize such an array by using the usual array initialization syntax and
	function names as addresses.
*/

double calculate(double one, double two, double (*pf)(double, double));
double add(double one, double two);
double subtract(double one, double two);


void task_10() // let it be kind a main func
{
	char ch = 0;

	do
	{
		cout << "Enter first digit: ";
		double one = 0;
		while (!(cin >> one))
		{
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "Incorrect input. Try again: ";
		}
		cin.get();

		cout << "Enter second digit: ";
		double two = 0;
		while (!(cin >> two))
		{
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "Incorrect input. Try again: ";
		}
		cin.get();

		cout << endl;
		cout << one << " + " << two << " = " << calculate(one, two, add) << endl;
		cout << one << " - " << two << " = " << calculate(one, two, subtract) << endl;

		cout << endl;
		cout << "Rpess any key (q for quit)";
		cin.get(ch);
		cout << endl;

		if (cin.rdbuf()->in_avail())
			cin.ignore(cin.rdbuf()->in_avail());
	} while (ch != 'q' && ch != 'Q');
}


double calculate(double one, double two, double (*pf)(double, double))
{
	return (*pf)(one, two);
}


double add(double one, double two)
{
	return one + two;
}


double subtract(double one, double two)
{
	return one - two;
}