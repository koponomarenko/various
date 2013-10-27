#include "clHasDMA.h"

#include <iostream>
#include <cstring>



clHasDMA::clHasDMA(const char * s)
{
	style = new char[std::strlen(s) + 1];
	std::strcpy(style, s);
}


clHasDMA::clHasDMA(const clHasDMA & hs)
{
	style = new char[std::strlen(hs.style) + 1];
	std::strcpy(style, hs.style);
}


clHasDMA::~clHasDMA()
{
	delete [] style;
}


clHasDMA & clHasDMA::operator=(const clHasDMA & hs)
{
	if (this == &hs)
		return *this;

	delete [] style; // prepare for new style
	style = new char[std::strlen(hs.style) + 1];
	std::strcpy(style, hs.style);

	return *this;
}


void clHasDMA::View()
{
	std::cout << "clHasDMA " << std::endl;
	std::cout << "Style: " << style << std::endl;
}

