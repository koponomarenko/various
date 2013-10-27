#include "clMyTime.h"


clMyTime::clMyTime(void)
{
	hours = minutes = 0;
}


clMyTime::clMyTime(int h, int m )
{
	hours = h;
	minutes = m;
}


void clMyTime::AddMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}


void clMyTime::AddHr(int h)
{
	hours += h;
}


void clMyTime::Reset(int h, int m)
{
	hours = h;
	minutes = m;
}


clMyTime operator+(const clMyTime & t1, const clMyTime & t2)
{
	clMyTime sum;
	sum.minutes = t1.minutes + t2.minutes;
	sum.hours = t1.hours + t2.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}


clMyTime operator-(const clMyTime & t1, const clMyTime & t2)
{
	clMyTime diff;
	int tot1, tot2;
	tot1 = t2.minutes + 60 * t2.hours;
	tot2 = t1.minutes + 60 * t1.hours;
	diff.minutes = (tot2 - tot1) % 60;
	diff.hours = (tot2 - tot1) / 60;
	return diff;
}


clMyTime operator*(const clMyTime & t, double n)
{
	clMyTime result;
	long totalminutes = t.hours * n * 60 + t.minutes * n;
	result.hours = totalminutes / 60;
	result.minutes = totalminutes % 60;
	return result;
}


std::ostream & operator<<(std::ostream & os, const clMyTime & t)
{
	os << t.hours << " hours, " << t.minutes << " minutes";
	return os;
}