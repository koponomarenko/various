#include <iostream>
#include <cmath>

#include "exc_mean_2.h"
using namespace std;

/*

*/

inline static double hmean(double a, double b);
inline static double gmean(double a, double b);

void task_03() // let it be kind a main func
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
		catch (MyException & ex)
		{
			ex.what();
			cout << "Sorry, you don't get to play any more.\n";
			break;
		} // end of catch block
	}
	cout << "Bye!\n";
}

inline double hmean(double a, double b)
{
	if (a == -b)
		throw bad_hmean("hmean(): invalid arguments: a = -b", a, b);
	return 2.0 * a * b / (a + b);
}
inline double gmean(double a, double b)
{
	if (a < 0 || b < 0)
		throw bad_gmean("gmean(): arguments should be >= 0", a, b);
	return std::sqrt(a * b);
}