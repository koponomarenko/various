#include <iostream>

#include "clStock.h"

using namespace std;

/*
	Rewrite the clStock class, as described in Listings 10.7 and 10.8 in Chapter 10 so
	that it uses dynamically allocated memory directly instead of using string class
	objects to hold the clStock names.Also replace the show() member function with an
	overloaded operator<<() definition.Test the new definition program in Listing
	10.9.
*/

const int STKS = 4;

void task_03() // let it be kind a main func
{
	// create an array of initialized objects
	clStock stocks[STKS] = {
		clStock("NanoSmart", 12, 20.0),
		clStock("Boffo Objects", 200, 2.0),
		clStock("Monolithic Obelisks", 130, 3.25),
		clStock("Fleep Enterprises", 60, 6.5)
	};

	std::cout << "clStock holdings:\n";
	int st;
	for (st = 0; st < STKS; st++)
		cout << stocks[st];

	// set pointer to first element
	const clStock * top = &stocks[0];
	for (st = 1; st < STKS; st++)
		top = &top->topval(stocks[st]);

	// now top points to the most valuable holding
	std::cout << "\nMost valuable holding:\n";
	cout << *top;
}