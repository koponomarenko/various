#pragma once

#include <iostream>
#include "clDMA.h"


class clLacksDMA : public clDMA
{
private:
	enum { COL_LEN = 40};
	char color[COL_LEN];

public:
	clLacksDMA(const char * c = "blank");

	virtual void View();
};

