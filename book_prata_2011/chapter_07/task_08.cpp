#include <iostream>
using namespace std;

/*
	Redo Listing 7.15 without using the array class. Do two versions:
		a. Use an ordinary array of const char * for the strings representing the sea-
	son names, and use an ordinary array of double for the expenses.
		b. Use an ordinary array of const char * for the strings representing the sea-
	son names, and use a structure whose sole member is an ordinary array of
	double for the expenses.(This design is similar to the basic design of the
	array class.)
*/

// constant data
const int Seasons = 4;
const char * Snames[Seasons] = {"Spring", "Summer", "Fall", "Winter"};

// function to modify array object
void fill(double * pBegin, double * pEnd);
// function that uses array object without modifying it
void show(const double * pBegin, const double * pEnd);


void task_08() // let it be kind a main func
{
	/* first way */
	cout << "first way" << endl << endl;
	double expenses[Seasons] = {0};
	fill(expenses, expenses + Seasons);
	show(expenses, expenses + Seasons);


	/* second way */
	cout << endl;
	cout << "second way" << endl << endl;
	struct
	{
		double expenses[Seasons];
	} stExpenses;
	
	fill(stExpenses.expenses , stExpenses.expenses + Seasons);
	show(stExpenses.expenses, stExpenses.expenses + Seasons);
	
	cout << endl;
}


void fill(double * pBegin, double * pEnd)
{
	for (int i = 0; i < Seasons && pBegin + i != pEnd; i++)
	{
		cout << "Enter " << Snames[i] << " expenses: ";
		cin >> pBegin[i];
	}
}


void show(const double * pBegin, const double * pEnd)
{
	double total = 0.0;

	cout << "\nEXPENSES\n";	
	for (int i = 0; i < Seasons && pBegin + i != pEnd; i++)
	{
		cout << Snames[i] << ": $" << pBegin[i] << endl;
		total += pBegin[i];
	}
	cout << "Total Expenses: $" << total << endl;
}