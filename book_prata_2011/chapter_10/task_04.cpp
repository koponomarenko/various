#include <iostream>

#include "clSales.h"

using namespace std;

/*
	Do Exercise 4 from Chapter 9 but convert the Sales structure and
	its associated functions to a class and its methods.
	Replace the setSales(Sales &, double [], int) function with a constructor.
	Implement the interactive setSales(Sales &) method by using the constructor.
	Keep the class within the namespace SALES.
*/

void task_04() // let it be kind a main func
{
	using SALES::clSales;

	double arrSales[] = {245.56, 668,75};
	clSales Sales(arrSales, sizeof(arrSales) / sizeof(arrSales[0]));

	Sales.Show();
	cout << endl;

	Sales.Set();

	cout << endl;
	Sales.Show();
}