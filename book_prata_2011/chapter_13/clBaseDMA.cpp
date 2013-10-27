#include "clBaseDMA.h"

#include <iostream>
#include <cstring>



clBaseDMA::clBaseDMA(const char * l, int r)
{
	label = new char[std::strlen(l) + 1];
	std::strcpy(label, l);
	rating = r;
}


clBaseDMA::clBaseDMA(const clBaseDMA & rs)
{
	label = new char[std::strlen(rs.label) + 1];
	std::strcpy(label, rs.label);
	rating = rs.rating;
}


clBaseDMA::~clBaseDMA()
{
	delete [] label;
}


void clBaseDMA::View()
{
	std::cout << "clBaseDMA " << std::endl;
	std::cout << "Label: " << label << std::endl;
	std::cout << "Rating: " << rating << std::endl;
}


clBaseDMA & clBaseDMA::operator=(const clBaseDMA & rs)
{
	if (this == &rs)
		return *this;

	delete [] label;
	label = new char[std::strlen(rs.label) + 1];
	std::strcpy(label, rs.label);
	rating = rs.rating;

	return *this;
}

