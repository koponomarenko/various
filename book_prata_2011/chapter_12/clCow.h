#pragma once


class clCow
{
	char name[20];
	char * hobby;
	double weight;

public:
	clCow();
	clCow(const char * nm, const char * ho, double wt);
	clCow(const clCow &);
	~clCow();
	clCow & operator=(const clCow & c);
	void ShowCow() const; // display all clCow data
};
