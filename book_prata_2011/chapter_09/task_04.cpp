#include <iostream>

#include "sales.h"

using namespace std;

/*
	Write a three-file program based on the following namespace:
		namespace SALES
		{
			const int QUARTERS = 4;
			struct Sales
			{
				double sales[QUARTERS];
				double average;
				double max;
				double min;
			};
			// copies the lesser of 4 or n items from the array ar
			// to the sales member of s and computes and stores the
			// average, maximum, and minimum values of the entered items;
			// remaining elements of sales, if any, set to 0
			void setSales(Sales & s, const double ar[], int n);
			// gathers sales for 4 quarters interactively, stores them
			// in the sales member of s and computes and stores the
			// average, maximum, and minimum values
			void setSales(Sales & s);
			// display all information in structure s
			void showSales(const Sales & s);
		}
	The first file should be a header file that contains the namespace. 
	
	The second file	should be a source code file that extends the namespace 
	to provide definitions for the three prototyped functions. 
	
	The third file should declare two Sales objects. It	should use the 
	interactive version of setSales() to provide values for one structure
	and the non-interactive version of setSales() to provide values for the second
	structure. It should display the contents of both structures by using
	showSales().
*/

void task_04() // let it be kind a main func
{
	using SALES::setSales;
	using SALES::showSales;
	using SALES::Sales;

	double arrSales[] = {245.56, 668,75};
	Sales stSales_1, stSales_2;

	setSales(stSales_1); // the interactive version
	setSales(stSales_2, arrSales, sizeof(arrSales) / sizeof(arrSales[0])); // the non-interactive version

	showSales(stSales_1);
	showSales(stSales_2);
}