#include "clPort.h"

#include <cstring>

using namespace std;

clPort::clPort(const char * br, const char * st, int b)
{
	brand = new char[strlen(br) + 1];
	strcpy(brand, br);

	strncpy(style, st, sizeof(style) - 1);
	style[sizeof(style) - 1] = '\0';

	bottles = b;
}


clPort::clPort(const clPort & p)
{
	brand = new char[strlen(p.brand) + 1];
	strcpy(brand, p.brand);

	strcpy(style, p.style);

	bottles = p.bottles;
}


clPort & clPort::operator=(const clPort & p)
{
	if (this == &p)
		return *this;

	delete [] brand;
	brand = new char[strlen(p.brand) + 1];
	strcpy(brand, p.brand);

	strcpy(style, p.style);

	bottles = p.bottles;

	return *this;
}


clPort & clPort::operator+=(int b)
{
	if (b > 0)
		bottles += b;
	return *this;
}


clPort & clPort::operator-=(int b)
{
	if (bottles - b >= 0)
		bottles -= b;
	return *this;
}


void clPort::Show() const
{
	cout << "Brand: " << brand << endl;
	cout << "Kind: " << style << endl;
	cout << "Bottles: " << bottles << endl;
}


std::ostream & operator<<(std::ostream & os, const clPort & p)
{
	return os << p.brand << ", " << p.style << ", " << p.bottles;
}
