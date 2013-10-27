#include <iostream>
using namespace std;

/*
	Redo Listing 7.7, modifying the three array-handling functions to each use two
	pointer parameters to represent a range. The fill _array() function, instead of
	returning the actual number of items read, should return a pointer to the location
	after the last location filled; the other functions can use this pointer as the second
	argument to identify the end of the data.
*/

const int Max = 5;

double * fill_array(double * pBegin, double * pEnd);
void show_array(const double * pBegin, const double * pEnd); // don't change data
void revalue(double r, double * pBegin, double * pEnd);

void task_07() // let it be kind a main func
{
	double arrProperties[Max];
	double * pPropEnd = arrProperties + Max; // location after the last location

	pPropEnd = fill_array(arrProperties, pPropEnd);
	show_array(arrProperties, pPropEnd);

	if (pPropEnd - arrProperties) // size > 0
	{
		cout << "Enter revaluation factor: ";
		double factor;
		while (!(cin >> factor)) // bad input
		{
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "Bad input; Please enter a number: ";
		}

		revalue(factor, arrProperties, pPropEnd);
		show_array(arrProperties, pPropEnd);
	}

	cout << "Done.\n";
	cout << endl;
}


double * fill_array(double * pBegin, double * pEnd)
{
	double temp;
	double * pt = pBegin;

	while (pt != pEnd)
	{
		cout << "Enter value #" << (pt - pBegin + 1) << ": ";
		cin >> temp;
		if (!cin) // bad input
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input; input process terminated.\n";
			break;
		}
		else if (temp < 0) // signal to terminate
			break;

		*pt++ = temp;
	}

	return pt;
}


// the following function can use, but not alter,
// the array whose address is ar
void show_array(const double * pBegin, const double * pEnd)
{
	for (int i = 0; pBegin + i != pEnd; ++i)
	{
		cout << "Property #" << (i + 1) << ": $";
		cout << *(pBegin + i) << endl;
	}
}


// multiplies each element of ar[] by r
void revalue(double r, double * pBegin, double * pEnd)
{
	for (double * pt = pBegin; pt != pEnd; ++pt)
		*pt *= r;
}
