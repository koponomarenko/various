#include "clString.h"
#include <cctype>


// initializing static class member
int clString::num_strings = 0;

// static method
int clString::HowMany()
{
	return num_strings;
}


// class methods
clString::clString(const char * s) // construct clString from C clString
{
	len = std::strlen(s); // set size
	str = new char[len + 1]; // allot storage
	std::strcpy(str, s); // initialize pointer
	num_strings++; // set object count
}


clString::clString() // default constructor
{
	len = 1;
	str = new char[1];
	str[0] = '\0'; // default clString
	num_strings++;
}


clString::clString(const clString & st)
{
	num_strings++; // handle static member update
	len = st.len; // same length
	str = new char [len + 1]; // allot space
	std::strcpy(str, st.str); // copy clString to new location
}


clString::~clString() // necessary destructor
{
	--num_strings; // required
	delete [] str; // required
}


void clString::stringlow()
{
	for (int i = 0; i < len; ++i)
		str[i] = tolower(str[i]);
}


void clString::stringup()
{
	for (int i = 0; i < len; ++i)
		str[i] = toupper(str[i]);
}


int clString::has(char ch)
{
	int count = 0;
	for (int i = 0; i < len; ++i)
		if (str[i] == ch)
			count++;
	return count;
}


// overloaded operator methods
// assign a clString to a clString
clString & clString::operator=(const clString & st)
{
	if (this == &st)
	return *this;
	delete [] str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}


// assign a C clString to a clString
clString & clString::operator=(const char * s)
{
	delete [] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}


// read-write char access for non-const clString
char & clString::operator[](int i)
{
	return str[i];
}


// read-only char access for const clString
const char & clString::operator[](int i) const
{
	return str[i];
}


// overloaded operator friends
bool operator<(const clString &st1, const clString &st2)
{
	return (std::strcmp(st1.str, st2.str) < 0);
}


bool operator>(const clString &st1, const clString &st2)
{
	return st2 < st1;
}


bool operator==(const clString &st1, const clString &st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);
}


// simple clString output
std::ostream & operator<<(std::ostream & os, const clString & st)
{
	os << st.str;
	return os;
}


// quick and dirty clString input
std::istream & operator>>(std::istream & is, clString & st)
{
	char temp[clString::CINLIM];
	is.get(temp, clString::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;

	return is;
}

const clString operator+(const clString & str_l, const clString & str_r)
{
	char * temp = new char[std::strlen(str_l.str) + std::strlen(str_r.str) + 1];
	std::strcat(std::strcpy(temp, str_l.str), str_r.str);

	clString StringRes(temp);
	delete [] temp;

	return StringRes;
}