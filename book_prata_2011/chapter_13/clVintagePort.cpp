#include "clVintagePort.h"

#include <cstring>

using namespace std;


clVintagePort::clVintagePort() : clPort("none", "vintage")
{
	nickname = 0;
	year = 0;
}


clVintagePort::clVintagePort(const char * br, int b, const char * nn, int y) : clPort(br, "vintage", b)
{
	if (nn)
	{
		nickname = new char[strlen(nn) + 1];
		strcpy(nickname, nn);
	}
	else
		nickname = 0;

	year = y;
}


clVintagePort::clVintagePort(const clVintagePort & vp) : clPort(vp)
{
	if (vp.nickname)
	{
		nickname = new char[strlen(vp.nickname) + 1];
		strcpy(nickname, vp.nickname);
	}
	else
		nickname = 0;

	year = vp.year;
}


clVintagePort & clVintagePort::operator=(const clVintagePort & vp)
{
	if (this == &vp)
		return *this;

	clPort::operator=(vp);

	delete [] nickname;
	if (vp.nickname)
	{
		nickname = new char[strlen(vp.nickname) + 1];
		strcpy(nickname, vp.nickname);
	}
	else
		nickname = 0;

	year = vp.year;

	return *this;
}


void clVintagePort::Show() const
{

}


std::ostream & operator<<(std::ostream & os, const clVintagePort & vp)
{
	vp.clPort::Show();
	os << "Nickname: "<< vp.nickname << endl;
	os << "Year: " << vp.year << endl;
	return os;
}