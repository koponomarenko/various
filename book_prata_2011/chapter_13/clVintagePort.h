#pragma once

#include "clPort.h"

class clVintagePort : public clPort // style necessarily = "vintage"
{
private:
	char * nickname; // i.e., "The Noble" or "Old Velvet", etc.
	int year; // vintage year

public:
	clVintagePort();
	clVintagePort(const char * br, int b, const char * nn, int y);
	clVintagePort(const clVintagePort & vp);
	~clVintagePort() { delete [] nickname; }

	clVintagePort & operator=(const clVintagePort & vp);
		 
	void Show() const;
	friend std::ostream & operator<<(std::ostream & os, const clVintagePort & vp);
};