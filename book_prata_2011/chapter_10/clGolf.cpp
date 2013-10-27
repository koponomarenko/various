#include <iostream>
#include <string>

#include "clGolf.h"

clGolf::clGolf(const std::string & sName, int hc)
{
	sFullname_ = sName;
	nHandicap_ = hc;
}

// interactive version:
// function solicits name and handicap from user
// and sets the members of g to the values entered
// returns 1 if name is entered, 0 if name is empty string
bool clGolf::Set()
{
	std::string sFullname;
	int nHandicap = 0;

	// reset input buffer, just in case
	if (std::cin.rdbuf()->in_avail())
		std::cin.ignore(std::cin.rdbuf()->in_avail());

	std::cout << "Enter a name: ";
	getline(std::cin, sFullname);

	if (sFullname.size() == 0)
		return false; // name is empty

	std::cout << "Enter a handicap: ";
	while (!(std::cin >> nHandicap))
	{
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cout << "Incorrect input! Try again: ";
	}

	*this = clGolf(sFullname, nHandicap);

	return true; // sutruct filled
}

// function resets handicap to new value
void clGolf::Handicap(int hc)
{
	nHandicap_ = hc;
}

// function displays contents of golf structure
void clGolf::Show() const
{
	std::cout << "Full name: " << sFullname_ << std::endl;
	std::cout << "Handicap: " << nHandicap_ << std::endl;
}