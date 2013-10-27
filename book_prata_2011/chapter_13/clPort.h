#pragma once

#include <iostream>

class clPort
{
private:
	char * brand;
	char style[20]; // i.e., tawny, ruby, vintage
	int bottles;

public:
	clPort(const char * br = "none", const char * st = "none", int b = 0);
	clPort(const clPort & p); // copy constructor
	virtual ~clPort() { delete [] brand; }

	clPort & operator=(const clPort & p);
	clPort & operator+=(int b); // adds b to bottles
	clPort & operator-=(int b); // subtracts b from bottles, if available

	int BottleCount() const { return bottles; }
	virtual void Show() const;

	friend std::ostream & operator<<(std::ostream & os, const clPort & p);
};