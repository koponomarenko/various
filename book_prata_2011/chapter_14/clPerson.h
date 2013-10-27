#pragma once

#include <iostream>
#include <string>

class clPerson
{
	std::string sFirstName_;
	std::string sLastName_;

public:
	clPerson(void) : sFirstName_("none"), sLastName_("none") {}
	clPerson(std::string sFName, std::string sLName) : sFirstName_(sFName), sLastName_(sLName) {}
	virtual ~clPerson(void) {}

	virtual void Set()
	{
		std::cout << "Enter first name: ";
		std::getline(std::cin, sFirstName_);
		std::cout << "Enter last name: ";
		std::getline(std::cin, sLastName_);
	}

	virtual void Show() const
	{
		std::cout << "First name: " << sFirstName_ << std::endl;
		std::cout << "Last name: " << sLastName_ << std::endl;
	}
};
