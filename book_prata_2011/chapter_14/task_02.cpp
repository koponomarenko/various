#include <iostream>

#include "clWine_2.h"

using namespace std;

/*

*/

void task_02() // let it be kind a main func
{
	cout << "Enter name of Wine: ";
	char lab[50];
	cin.getline(lab, 50);

	cout << "Enter number of years: ";
	int yrs;
	cin >> yrs;

	clWine_2 holding(lab, yrs); // store label, years, give arrays yrs elements
	holding.GetBottles(); // solicit input for year, bottle count
	holding.Show(); // display object contents
	const int YRS = 3;
	int y[YRS] = {1993, 1995, 1998};
	int b[YRS] = { 48, 60, 72};

	// create new object, initialize using data in arrays y and b
	clWine_2 more("Gushing Grape Red", YRS, y, b);
	more.Show();
	cout << "Total bottles for " << more.Label() // use Label() method
		 << ": " << more.sum() << endl; // use sum() method

	cout << "Bye\n";
}