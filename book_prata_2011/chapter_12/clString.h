#pragma once

#include <iostream>

class clString
{
private:
	char * str; // pointer to clString
	int len; // length of clString
	static int num_strings; // number of objects
	static const int CINLIM = 80; // cin input limit

public:
	// constructors and other methods
	clString(const char * s); // constructor
	clString(); // default constructor
	clString(const clString &); // copy constructor
	~clString(); // destructor

	int length () const { return len; }
	void stringlow();
	void stringup();
	int has(char);

	// overloaded operator methods
	clString & operator=(const clString &);
	clString & operator=(const char *);
	char & operator[](int i);
	const char & operator[](int i) const;

	// overloaded operator friends
	friend bool operator<(const clString &st, const clString &st2);
	friend bool operator>(const clString &st1, const clString &st2);
	friend bool operator==(const clString &st, const clString &st2);
	friend std::ostream & operator<<(std::ostream & os, const clString & st);
	friend std::istream & operator>>(std::istream & is, clString & st);

	friend const clString operator+(const clString & str_l, const clString & str_r);

	// static function
	static int HowMany();
};