#include "clWine_1.h"
#include <iostream>
using namespace std;

clWine_1::clWine_1(void)
{
}

clWine_1::clWine_1(const char * l, int y, const int yr[], const int bot[]) : sLabel_(l), nYears_(y), Year_Bottles_(valarray<int>(yr, nYears_), valarray<int>(bot, nYears_))
{
}


clWine_1::clWine_1(const char * l, int y) : sLabel_(l), nYears_(y), Year_Bottles_(valarray<int>(nYears_), valarray<int>(nYears_))
{
}


clWine_1::~clWine_1(void)
{
}


void clWine_1::GetBottles()
{
	int year, bottle;

	cout << "Enter " << sLabel_ << " data for " << nYears_ << " year(s):" << endl;
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

		Year_Bottles_.first()[i] = year;
		Year_Bottles_.second()[i] = bottle;
	}
}


void clWine_1::Show() const
{
	cout << "Wine: " << sLabel_ << endl;
	cout << '\t' << "Year" << '\t' << "Bottles" << endl;
	for (int i = 0; i < nYears_; ++i)
		cout << '\t' << Year_Bottles_.first()[i] << '\t' << Year_Bottles_.second()[i] << endl;
}