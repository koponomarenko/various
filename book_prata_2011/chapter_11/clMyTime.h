#pragma once

#include <iostream>

class clMyTime
{
private:
	int hours;
	int minutes;

public:
	clMyTime(void);
	clMyTime(int h, int m = 0);

	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h = 0, int m = 0);

	friend clMyTime operator+(const clMyTime & t1, const clMyTime & t2);
	friend clMyTime operator-(const clMyTime & t1, const clMyTime & t2);
	friend clMyTime operator*(const clMyTime & t, double n);
	friend clMyTime operator*(double m, const clMyTime & t) { return t * m; } // inline definition
	friend std::ostream & operator<<(std::ostream & os, const clMyTime & t);
};

