#pragma once

#include <stdexcept>
#include <string>
#include <iostream>

class MyException : public std::logic_error
{
	double v1;
	double v2;

public:
	MyException(const std::string & what_arg, double a = 0, double b = 0)
		: logic_error(what_arg), v1(a), v2(b) {}

	virtual void what()
	{
		std::cout << logic_error::what() << std::endl;
		std::cout << "Values used: " << v1 << ", " << v2 << std::endl;
	}
};

class bad_hmean : public MyException
{
public:
	bad_hmean(const std::string & what_arg, double a = 0, double b = 0)
		: MyException(what_arg, a, b) {}
};

class bad_gmean : public MyException
{
public:
	bad_gmean(const std::string & what_arg, double a = 0, double b = 0)
		: MyException(what_arg, a, b) {}
};
