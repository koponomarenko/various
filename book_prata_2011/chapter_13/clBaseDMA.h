#pragma once

#include "clDMA.h"

class clBaseDMA : public clDMA
{
private:
	char * label;
	int rating;

public:
	clBaseDMA(const char * l = "null", int r = 0);
	clBaseDMA(const clBaseDMA & rs);
	virtual ~clBaseDMA();
	
	virtual void View();

	clBaseDMA & operator=(const clBaseDMA & rs);
};