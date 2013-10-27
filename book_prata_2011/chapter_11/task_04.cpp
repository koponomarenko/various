#include <iostream>

#include "clMyTime.h"

using namespace std;

/*
	Rewrite the final Timeclass example (Listings 11.10,11.11, and 11.12) so that all
	the overloaded operators are implemented using friend functions.
*/

void task_04() // let it be kind a main func
{
	clMyTime aida(3, 35);
	clMyTime tosca(2, 48);
	clMyTime temp;

	cout << "Aida and Tosca:\n";
	cout << aida<<"; " << tosca << endl;

	temp = aida + tosca; // operator+()
	cout << "Aida + Tosca: " << temp << endl;

	temp = aida * 1.17; // member operator*()
	cout << "Aida * 1.17: " << temp << endl;
	cout << "10.0 * Tosca: " << 10.0 * tosca << endl;
}