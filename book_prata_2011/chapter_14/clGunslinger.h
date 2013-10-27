#pragma once

#include "clPerson.h"

class clGunslinger : virtual public clPerson
{
	double nTimeToReady_;
	int notches_;

protected:
	virtual void Set_i()
	{
		std::cout << "Enter time to ready: ";
		while (!(std::cin >> nTimeToReady_) || nTimeToReady_ < 0)
		{
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());
			std::cout << "Incorrect input! Try again: ";
		}
		std::cin.get();

		std::cout << "Enter notches on a gun: ";
		while (!(std::cin >> notches_) || nTimeToReady_ < 0)
		{
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());
			std::cout << "Incorrect input! Try again: ";
		}
	}

	virtual void Show_i() const // _i - internal
	{
		std::cout << "Time to ready: " << nTimeToReady_ << std::endl;
		std::cout << "notches_ on a gun: " << notches_ << std::endl;
	}

public:
	clGunslinger(void) : nTimeToReady_(0), notches_(0) {}
	clGunslinger(std::string sFName, std::string sLName, double nTimeToReady = 0, int notches = 0) : clPerson(sFName, sLName) {}
	virtual ~clGunslinger(void) {}

	virtual void Set()
	{
		clPerson::Set();
		Set_i();
	}

	virtual void Show() const
	{
		clPerson::Show();
		Show_i();
	}

	double Draw() { return nTimeToReady_; }
};
