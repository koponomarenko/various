#include <iostream>
#include <string>

#include "clPerson.h"


clPerson::clPerson() :  lname("")
{
	fname[0] = '\0';
}



clPerson::clPerson(const std::string & ln, const char * fn)
{
	lname = ln;

	if (fn)
	{
		unsigned short fn_len = strlen(fn);
		strncpy(fname, fn, (fn_len < LIMIT) ? fn_len : LIMIT - 1);
		fname[(fn_len < LIMIT) ? fn_len : LIMIT - 1] = '\0';
	}
	else
		fname[0] = '\0';
}



void clPerson::Show() const
{
	std::cout << fname << " " << lname << std::endl;
}



void clPerson::FormalShow() const
{
	std::cout << lname << ", " << fname << std::endl;
}