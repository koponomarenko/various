#include <cstring>
#include <iostream>

#include "golf.h"

using namespace std;


// function sets golf structure to provided name, handicap
// using values passed as arguments to the function
void setgolf(golf & g, const char * name, int hc)
{
	strncpy(g.fullname, name, (strlen(name) < Len) ? strlen(name) : Len - 1);
	g.fullname[Len] = '\0';
	g.handicap = hc;
}

// function solicits name and handicap from user
// and sets the members of g to the values entered
// returns 1 if name is entered, 0 if name is empty string
int setgolf(golf & g)
{
	if (cin.rdbuf()->in_avail())
		cin.ignore(cin.rdbuf()->in_avail());

	cout << "Enter a name: ";
	cin.getline(g.fullname, Len);
	if (cin.rdbuf()->in_avail())
		cin.ignore(cin.rdbuf()->in_avail());

	if (!strlen(g.fullname))
		return 0; // name is empty

	cout << "Enter a handicap: ";
	while (!(cin >> g.handicap))
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Incorrect input! Try again: ";
	}

	return 1; // sutruct filled
}


// function resets handicap to new value
void handicap(golf & g, int hc)
{
	g.handicap = hc;
}

// function displays contents of golf structure
void showgolf(const golf & g)
{
	cout << "Full name: " << g.fullname << endl;
	cout << "Handicap: " << g.handicap << endl;
}