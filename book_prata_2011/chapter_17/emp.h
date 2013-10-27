#pragma once

#include <iostream>
#include <fstream>
#include <string>

class abstr_emp
{
public:
	enum classkind{EMPLOYEE, MANAGER, FINK, HIGHFINK}; // for identification while read/write to file
private:
	std::string fname; // abstr_emp's first name
	std::string lname; // abstr_emp's last name
	std::string job;
public:
	abstr_emp();
	abstr_emp(const std::string & fn, const std::string & ln, const std::string & j);
	virtual void ShowAll() const; // labels and shows all data
	virtual void SetAll(); // prompts user for values
	virtual void WriteAll(std::fstream & fout) const;
	virtual void GetAll(std::fstream & fin);
	friend std::ostream & operator<<(std::ostream & os, const abstr_emp & e);
	// just displays first and last name
	virtual ~abstr_emp() = 0; // virtual base class
};


class employee : public abstr_emp
{
public:
	employee();
	employee(const std::string & fn, const std::string & ln, const std::string & j);
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void WriteAll(std::fstream & fout) const;
	virtual void GetAll(std::fstream & fin);
};


class manager: virtual public employee
{
private:
	int inchargeof; // number of employees managed
protected:
	int InChargeOf() const { return inchargeof; } // output
	int & InChargeOf(){ return inchargeof; } // input
public:
	manager();
	manager(const std::string & fn, const std::string & ln, const std::string & j, int ico = 0);
	manager(const employee & e, int ico);
	manager(const manager & m);
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void WriteAll(std::fstream & fout) const;
	virtual void GetAll(std::fstream & fin);
};


class fink: virtual public employee
{
private:
	std::string reportsto; // to whom fink reports
protected:
	const std::string ReportsTo() const { return reportsto; }
	std::string & ReportsTo(){ return reportsto; }
public:
	fink();
	fink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo);
	fink(const employee & e, const std::string & rpo);
	fink(const fink & e);
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void WriteAll(std::fstream & fout) const;
	virtual void GetAll(std::fstream & fin);
};


class highfink: public manager, public fink // management fink
{
public:
	highfink();
	highfink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo, int ico);
	highfink(const employee & e, const std::string & rpo, int ico);
	highfink(const fink & f, int ico);
	highfink(const manager & m, const std::string & rpo);
	highfink(const highfink & h);
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void WriteAll(std::fstream & fout) const;
	virtual void GetAll(std::fstream & fin);
};

