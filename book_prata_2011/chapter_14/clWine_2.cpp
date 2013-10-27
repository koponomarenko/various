#include "clWine_2.h"
#include <iostream>
using namespace std;

clWine_2::clWine_2(void)
{
}

clWine_2::clWine_2(const char * l, int y, const int yr[], const int bot[]) : string(l), nYears_(y), clPair(valarray<int>(yr, y), valarray<int>(bot, y))
{
}


clWine_2::clWine_2(const char * l, int y) : string(l), nYears_(y), clPair(valarray<int>(y), valarray<int>(y))
{
}


clWine_2::~clWine_2(void)
{
}


void clWine_2::GetBottles()
{
	int year, bottle;

	cout << "Enter " << (std::string &)*this << " data for " << nYears_ << " year(s):" << endl;
	for (int i = 0; i < nYears_; ++i)
	{
		cout << "Enter year: ";
		while (!(cin >> year) || year <= 0 || year/3000)
		{
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "Incorrect input! Try again: ";
		}
		cin.get();

		cout << "Enter bottles for that year: ";
		while (!(cin >> bottle) || bottle <= 0)
		{
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "Incorrect input! Try again: ";
		}
		cin.get();

		clPair::first()[i] = year;
		clPair::second()[i] = bottle;
	}
}


void clWine_2::Show() const
{
	cout << "Wine: " << (std::string &)*this << endl;
	cout << '\t' << "Year" << '\t' << "Bottles" << endl;
	for (int i = 0; i < nYears_; ++i)
		cout << '\t' << clPair::first()[i] << '\t' << clPair::second()[i] << endl;
}