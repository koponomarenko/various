#pragma once

#include <iostream>
#include "clDMA.h"


class clHasDMA : public clDMA
{
private:
	char * style;

public:
	clHasDMA(const char * s = "none");
	clHasDMA(const clHasDMA & hs);
	~clHasDMA();

	clHasDMA & operator=(const clHasDMA & rs);

	virtual void View();
};