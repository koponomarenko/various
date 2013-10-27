#pragma once

#include <cstdlib>

class Customer
{
private:
	long arrive; // arrival time for customer
	int processtime; // processing time for customer

public:
	Customer() { arrive = processtime = 0; }
	void set(long when) // time set to a random value in the range 1 - 3
	{
		processtime = std::rand() % 3 + 1;
		arrive = when;
	}

	long when() const { return arrive; }
	int ptime() const { return processtime; }
};