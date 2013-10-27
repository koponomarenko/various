#include <iostream>
#include <cmath>

#include "exc_mean.h"

using namespace std;

/*

*/

double hmean(double a, double b);
double gmean(double a, double b);


void task_02() // let it be kind a main func
{
	double x, y, z;
	cout << "Enter two numbers: ";
	while (cin >> x >> y)
	{
		try { // start of try block
			z = hmean(x,y);
			cout << "Harmonic mean of " << x << " and " << y
				 << " is " << z << endl;
			cout << "Geometric mean of " << x << " and " << y
				 << " is " << gmean(x,y) << endl;
			cout << "Enter next set of numbers <q to quit>: ";
		}// end of try block
		catch (bad_hmean & bg) // start of catch block
		{
			cout << bg.what() << endl;
			cout << "Try again.\n";
			continue;
		}
		catch (bad_gmean & hg)
		{
			cout << hg.what() << endl;
			cout << "Sorry, you don't get to play any more.\n";
			break;
		} // end of catch block
	}
	cout << "Bye!\n";
}

double hmean(double a, double b)
{
	if (a == -b)
		throw bad_hmean("hmean(): invalid arguments: a = -b");
	return 2.0 * a * b / (a + b);
}
double gmean(double a, double b)
{
	if (a < 0 || b < 0)
		throw bad_gmean("gmean(): arguments should be >= 0");
	return std::sqrt(a * b);
}