#include <iostream>

#include "clStonewt.h"

using namespace std;

/*
	Rewrite the Stonewt class (Listings 11.16and 11.17) so that it overloads all six
	relational operators. The operators should compare the pounds members and return
	a type bool value. Write a program that declares an array of six Stonewt objects and
	initializes the first three objects in the array declaration. Then it should use a loop
	to read in values used to set the remaining three array elements. Then it should
	report the smallest element, the largest element, and how many elements are greater
	or equal to 11 stone.(The simplest approach is to create a Stonewtobject initial-
	ized to 11 stone and to compare the other objects with that object.)
*/

void task_06() // let it be kind a main func
{
	const int nSize = 6;
	clStonewt arr[nSize] = {clStonewt(110), clStonewt(120.5), clStonewt(240)};

	double nLbs = 0;
	for (int i = 3; i < nSize; ++i)
	{
		cout << "Enter weight in pounds for " << i + 1 << " person: ";
		while (!(cin >> nLbs))
		{
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "Incorrect input! Try again: ";
		}
		cin.get();

		arr[i] = nLbs;
	}


	cout << endl;
	cout << "Filled array: " << endl;
	for (int i = 0; i < nSize; ++i)
	{
		arr[i].SetState(clStonewt::STONE);
		cout << "#" << i + 1 << " : " << arr[i] << endl;
	}


	clStonewt CompareElem(11, 0);
	clStonewt Smallest, Largest;
	int nGreaterEqual_11 = 0;

	Smallest = Largest = arr[0];
	for (int i = 0; i < nSize; ++i)
	{
		if (arr[i] < Smallest)
			Smallest = arr[i];
		if (arr[i] > Largest)
			Largest = arr[i];
		if (arr[i] >= CompareElem)
			nGreaterEqual_11++;
	}

	cout << endl;
	cout << "Smallest: " << Smallest << endl;
	cout << "Largest: " << Largest << endl;
	cout << nGreaterEqual_11 << " elements are greater or equal to 11 stone." << endl;
}
