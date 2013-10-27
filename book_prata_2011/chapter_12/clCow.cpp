#include "clCow.h"

#include <iostream>
#include <cstring>

clCow::clCow(void)
{
	name[0] = '\0';
	hobby = 0;
	weight = 0;
}


clCow::clCow(const char * nm, const char * ho, double wt)
{
	if (nm)
	{
		std::strncpy(name, nm, (strlen(nm) < sizeof(name)) ? strlen(nm) : sizeof(name) - 1);
		name[(strlen(nm) < sizeof(name)) ? strlen(nm) : sizeof(name) - 1] = '\0';
	}
	else
		name[0] = '\0';

	if (ho)
	{
		hobby = new char[strlen(ho) + 1];
		strcpy(hobby, ho);
	}
	else
		hobby = 0;

	weight = wt;
}


clCow::clCow(const clCow & c)
{
	if (c.name[0])
		strcpy(name, c.name);
	else
		name[0] = '\0';

	if (c.hobby)
	{
		hobby = new char[strlen(c.hobby) + 1];
		strcpy(hobby, c.hobby);
	}
	else
		hobby = 0;

	weight = c.weight;
}


clCow::~clCow(void)
{
	delete [] hobby;
}


clCow & clCow::operator=(const clCow & c)
{
	if (this == &c)
		return *this;

	if (c.name[0])
		strcpy(name, c.name);
	else
		name[0] = '\0';

	delete [] hobby;
	if (c.hobby)
	{
		hobby = new char[strlen(c.hobby) + 1];
		strcpy(hobby, c.hobby);
	}
	else
		hobby = 0;

	weight = c.weight;

	return *this;
}


void clCow::ShowCow() const
{
	std::cout << "name: " << (name[0] ? name : "none") << std::endl;
	std::cout << "hobby: " << (hobby ? hobby : "none") << std::endl;
	std::cout << "weight: " << weight << std::endl;
}