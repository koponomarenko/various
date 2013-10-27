#include <iostream>

#include "clPlorg.h"

using namespace std;

/*
	A Betelgeusean plorg has these properties:
	Data
	A plorg has a name with no more than 19 letters.
	A plorg has a contentment index (CI),which is an integer.
	Operations
	A new plorg starts out with a name and a CI of 50.
	A plorg’s CI can change.
	A plorg can report its name and CI.
	The default plorg has the name "Plorga".
	Write a Plorg class declaration (including data members and member function pro-
	totypes) that represents a plorg. Write the function definitions for the member 
	functions. Write a short program that demonstrates all the features of the Plorg class.
*/

void task_07() // let it be kind a main func
{
	clPlorg Plorg;

	Plorg.DisplayInfo();

	cout << endl;
	Plorg.SetCI(100500);
	cout << "After \"Plorg.SetCI(100500)\": " << endl;
	Plorg.DisplayInfo();
}
