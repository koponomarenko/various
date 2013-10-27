#include <iostream>
using namespace std;

/*
	Write a function that normally takes one argument, the address of a string, and
	prints that string once. However, if a second, type int, argument is provided and is
	nonzero, the function should print the string a number of times equal to the number of
	times that function has been called at that point. (Note that the number of
	times the string is printed is not equal to the value of the second argument; it is equal to
	the number of times the function has been called.) Yes, this is a silly function, but it makes
	you use some of thetechniques discussed in this chapter. Use the
	function in a simple program that demonstrates how the function works.
*/

void DisplayStr(const char * pStr, int n = 0);

void task_01() // let it be kind a main func
{
	char ch = 0;
	int n = 0;

	do
	{
		cout << "a. Call func with one argument" << endl
			 << "b. Call func with two arguments" << endl
			 << "q. Quit" << endl << endl
			 << "Make choise: ";
		cin >> ch;

		cout << endl;

		switch (ch)
		{
		case 'a':
		case 'A':
			DisplayStr("\tThis func with one argument");
			break;

		case 'b':
		case 'B':
			cout << "Enter second argument: ";
			while (!(cin >> n))
			{
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
				cout << "Incorrect input! Try again: ";
			}

			DisplayStr("\tThis func with two arguments", n);
			break;
		}

		cout << endl;

		if (cin.rdbuf()->in_avail())
			cin.ignore(cin.rdbuf()->in_avail());
	} while (ch != 'q' && ch != 'Q');
}



void DisplayStr(const char * pStr, int n)
{
	static int count = 0;

	if (n)
	{
		for (int i = 0; i < count; ++i)
			cout << pStr << endl;
	}
	else
	{
		cout << pStr << endl;
	}

	++count;
}