#include <iostream>

#include "golf.h"

using namespace std;

/*
	Here is a header file:
	----------------------
		// golf.h -- for pe9-1.cpp
		const int Len = 40;
		struct golf
		{
			char fullname[Len];
			int handicap;
		};

		// non-interactive version:
		// function sets golf structure to provided name, handicap
		// using values passed as arguments to the function
		void setgolf(golf & g, const char * name, int hc);

		// interactive version:
		// function solicits name and handicap from user
		// and sets the members of g to the values entered
		// returns 1 if name is entered, 0 if name is empty string
		int setgolf(golf & g);

		// function resets handicap to new value
		void handicap(golf & g, int hc);

		// function displays contents of golf structure
		void showgolf(const golf & g);
	----------------------
	Note that setgolf() is overloaded. Using the first version of set golf() would
	look like this:

	golf ann;
	setgolf(ann, "Ann Birdfree", 24);

	The function call provides the information that’s stored in the ann structure.
	Using the second version of setgolf() would look like this:

	golf andy;
	setgolf(andy);

	The function would prompt the user to enter the name and handicap and store
	them in the andy structure. This function could (but doesn’t need to) use the first
	version internally.

	Put together a multifile program based on this header. One file, named golf.cpp,
	should provide suitable function definitions to match the prototypes in the header
	file. A second file should contain main() and demonstrate all the features of the
	prototyped functions. 
	
	For example, a loop should solicit input for an array of golf
	structures and terminate when the array is full or the user enters an empty string
	for the golfer’s name. The main() function should use only the prototyped func-
	tions to access the golf structures.
*/

inline void DisplayGolfArr(const golf * pstGolf, int nSize)
{
	for (int i = 0; i < nSize; ++i)
	{
		cout << "#" << i + 1 << endl;
		showgolf(pstGolf[i]);
		cout << endl;
	}
}


void task_01() // let it be kind a main func
{
	golf * pstGolf = NULL;

	try
	{
		cout << "Enter size of array for golf stuctures: ";
		int nSize = 0;
		while (!(cin >> nSize) || nSize <= 0)
		{
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "Incorrect input! Try again: ";
		}

		
		pstGolf = new golf[nSize];
		

		// fill the array
		int nFilled = 0;
		while (nFilled < nSize)
		{
			if (!setgolf(pstGolf[nFilled]))
				break;
			++nFilled;
		}


		// display all the array
		DisplayGolfArr(pstGolf, nFilled);

		// make changes
		for (int i = 0; i < nFilled; ++i)
			handicap(pstGolf[i], i + 1);
		cout << "After call \"handicap(golf & g, int hc)\"" << endl;

		// display all the array
		DisplayGolfArr(pstGolf, nFilled);

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

	delete [] pstGolf;
}