#include <iostream>

#include "clGolf.h"

using namespace std;

/*
	Do Exercise 1 from Chapter 9 but replace the code shown there with
	an appropriate golf class declaration. Replace setgolf(golf &, const char*, int)
	with a constructor with the appropriate argument for providing initial values.
	Retain the interactive version of setgolf() but implement it by using the con-
	structor. (For example, for the code for setgolf(), obtain the data, pass the data to
	the constructor to create a temporary object, and assign the temporary object to the
	invoking object, which is *this.)
*/

inline void DisplayGolfArr(const clGolf * pGolf, int nSize)
{
	for (int i = 0; i < nSize; ++i)
	{
		cout << "#" << i + 1 << endl;
		pGolf[i].Show();
		cout << endl;
	}
}


void task_03() // let it be kind a main func
{
	clGolf * pGolf = NULL;

	try
	{
		cout << "Enter size of Golf objects array: ";
		int nSize = 0;
		while (!(cin >> nSize) || nSize <= 0)
		{
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "Incorrect input! Try again: ";
		}

		
		pGolf = new clGolf[nSize];
		

		// fill the array
		int nFilled = 0;
		while (nFilled < nSize)
		{
			if (!pGolf[nFilled].Set())
				break;
			++nFilled;
		}


		// display all the array
		DisplayGolfArr(pGolf, nFilled);

		// make changes
		for (int i = 0; i < nFilled; ++i)
			pGolf[i].Handicap(i + 1);
		cout << "After call \"pGolf.Handicap()\"" << endl;

		// display all the array
		DisplayGolfArr(pGolf, nFilled);

		// and i decided don't call "setgolf(golf & g, const char * name, int hc)" function
		// because it it doesn't need here
	}
	catch (bad_alloc &)
	{
		cout << "bad_alloc exception!" << endl;
		return;
	}
	catch (...)
	{
		cout << "Unknown exception!" << endl;
	}

	delete [] pGolf;
}