#include <iostream>

#include "clBaseDMA.h"
#include "clLacksDMA.h"
#include "clHasDMA.h"

using namespace std;

/*
	Revise the baseDMA-lacksDMA-hasDMA class hierarchy so that all three classes are
	derived from an ABC.Test the result with a program similar to the one in Listing
	13.10.That is, it should feature an array of pointers to the ABC and allow the user
	to make runtime decisions as to what types of objects are created. Add virtual
	View() methods to the class definitions to handle displaying the data.
*/

const int CLIENTS = 5;

void task_03() // let it be kind a main func
{
	std::cout << "Enter number of objects in array: ";
	int nSize = 0;
	while (!(cin >> nSize) || nSize <= 0)
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		std::cout << "Incorrect input! Try again: ";
	}
	
	clDMA ** pDmaArr = new clDMA * [nSize];

	char ch = 0;
	int nFilled = 0;
	while (nFilled < nSize && ch != '4')
	{
		cout << "1.Create clBaseDMA		2.Create clLacksDMA" << endl;
		cout << "3.Create clHasDMA		4.Quit" << endl;
		cout << ">";
		cin >> ch;
		if (cin.rdbuf()->in_avail())
			cin.ignore(cin.rdbuf()->in_avail());

		switch (ch)
		{
		case '1':
			pDmaArr[nFilled++] = new clBaseDMA("Some label", 7);
			cout << "Created: clBaseDMA" << endl;
			break;

		case '2':
			pDmaArr[nFilled++] = new clLacksDMA("Some color");
			cout << "Created: clLacksDMA" << endl;
			break;

		case '3':
			pDmaArr[nFilled++] = new clHasDMA("Some style");
			cout << "Created: clHasDMA" << endl;
			break;

		case '4':
			break;

		default:
			cout << "Incorrect input!" << endl; 
		}

		cout << endl;
	}

	// display objects
	cout << "-------------------------" << endl;
	for (int i = 0; i < nFilled; ++i)
	{
		pDmaArr[i]->View();
		cout << endl;
	}


	for (int i = 0; i < nFilled; ++i)
		delete pDmaArr[i];
	delete [] pDmaArr;
}