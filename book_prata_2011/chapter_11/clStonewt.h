#pragma once

#include <iostream>

class clStonewt
{
public:
	enum Mode { STONE, POUNDS_INT, POUNDS_FLOAT };

private:
	enum { Lbs_per_stn = 14 }; // pounds per stone

	Mode eState;
	int stone; // whole stones
	double pds_left; // fractional pounds
	double pounds; // entire weight in pounds

	void SetSoneFromPounds()
	{
		stone = int(pounds) / Lbs_per_stn;
		pds_left =  int(pounds) % Lbs_per_stn + (pounds - int(pounds));
	}

public:
	clStonewt(double lbs); // constructor for double pounds
	clStonewt(int stn, double lbs); // constructor for stone, lbs
	clStonewt(); // default constructor
	~clStonewt();

	void SetState(clStonewt::Mode m) { eState = m; }

	clStonewt operator+(double lbs) const;
	clStonewt operator-(double lbs) const;
	clStonewt operator*(int n) const;

	bool operator==(clStonewt st) const { return pounds == st.pounds; }
	bool operator!=(clStonewt st) const { return pounds != st.pounds; } // return !(*this == st.pounds)
	bool operator<(clStonewt st) const { return pounds < st.pounds; }
	bool operator>(clStonewt st) const { return pounds > st.pounds; } // return !(*this < st.pounds) && !(*this == st.pounds)
	bool operator<=(clStonewt st) const { return pounds <= st.pounds; } // return !(*this > st.pounds)
	bool operator>=(clStonewt st) const { return pounds >= st.pounds; } // return !(*this < st.pounds)

	friend std::ostream & operator<<(std::ostream & os, const clStonewt & obj);
	friend clStonewt operator+(double lbs, const clStonewt st) { return st + lbs; }
	friend clStonewt operator-(double lbs, const clStonewt st);
	friend clStonewt operator*(int n, const clStonewt st) { return st * n; };
};

