#include "clLacksDMA.h"



clLacksDMA::clLacksDMA(const char * c)
{
	std::strncpy(color, c, 39);
	color[39] = '\0';
}


void clLacksDMA::View()
{
	std::cout << "clLacksDMA " << std::endl;
	std::cout << "Color: " << color << std::endl;
}

