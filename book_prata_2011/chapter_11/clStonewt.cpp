#include "clStonewt.h"


// construct clStonewt object from double value
clStonewt::clStonewt(double lbs)
{
	eState = POUNDS_FLOAT;
	pounds = lbs;
	SetSoneFromPounds();
}


// construct clStonewt object from stone, double values
clStonewt::clStonewt(int stn, double lbs)
{
	eState = POUNDS_FLOAT;
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn + lbs;
}


clStonewt::clStonewt() // default constructor, wt = 0
{
	eState = POUNDS_FLOAT;
	stone = pounds = pds_left = 0;
}


clStonewt::~clStonewt() // destructor
{
}


clStonewt clStonewt::operator+(double lbs) const
{
	clStonewt temp;

	temp.pounds = this->pounds + lbs;
	temp.SetSoneFromPounds();

	return temp;
}


clStonewt clStonewt::operator-(double lbs) const
{
	clStonewt temp;

	temp.pounds = this->pounds - lbs;
	temp.SetSoneFromPounds();

	return temp;
}


clStonewt clStonewt::operator*(int n) const
{
	clStonewt temp;

	temp.pounds = this->pounds * n;
	temp.SetSoneFromPounds();

	return temp;
}


std::ostream & operator<<(std::ostream & os, const clStonewt & obj)
{
	switch (obj.eState)
	{
	case clStonewt::STONE:
		os << obj.stone << " stone, " << obj.pds_left << " pounds";
		break;

	case clStonewt::POUNDS_INT:
		os << int(obj.pounds) << " pounds";
		break;

	case clStonewt::POUNDS_FLOAT:
		os << obj.pounds << " pounds";
		break;
	}
	return os;
}


clStonewt operator-(double lbs, const clStonewt st)
{
	clStonewt temp;

	temp.pounds = lbs - st.pounds;
	temp.SetSoneFromPounds();

	return temp;
}