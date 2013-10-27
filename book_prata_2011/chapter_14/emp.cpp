#include "emp.h"
using namespace std;

									/* abstr_emp */
abstr_emp::abstr_emp() {}

abstr_emp::abstr_emp(const std::string & fn, const std::string & ln, const std::string & j)
	: fname(fn), lname(ln), job(j) {}

void abstr_emp::ShowAll() const
{
	cout << "First name: " << fname << endl;
	cout << "Last name: " << lname << endl;
	cout << "Job: " << job << endl;
}

void abstr_emp::SetAll()
{
	cout << "Enter first name: ";
	getline(cin, fname);
	cout << "Enter last name: ";
	getline(cin, lname);
	cout << "Enter job: ";
	getline(cin, job);
}

std::ostream & operator<<(std::ostream & os, const abstr_emp & e)
{
	cout << "First name: " << e.fname << endl;
	cout << "Last name: " << e.lname << endl;
	return os;
}

abstr_emp::~abstr_emp() {}

									/* employee */
employee::employee() {}

employee::employee(const std::string & fn, const std::string & ln, const std::string & j)
	:abstr_emp(fn, ln, j) {}

void employee::ShowAll() const
{
	abstr_emp::ShowAll();
}

void employee::SetAll()
{
	abstr_emp::SetAll();
}

									/* manager */
manager::manager() : inchargeof(0) {}
manager::manager(const std::string & fn, const std::string & ln, const std::string & j, int ico)
	: abstr_emp(fn, ln, j), inchargeof(ico) {}

manager::manager(const abstr_emp & e, int ico) : abstr_emp(e), inchargeof(ico) {}

manager::manager(const manager & m) : abstr_emp(m), inchargeof(m.inchargeof) {}

void manager::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "Employees managed: " << inchargeof << endl;
}

void manager::SetAll()
{
	abstr_emp::SetAll();

	cout << "Enter number of employees managed: ";
	while (!(cin >> inchargeof) || inchargeof < 0)
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Incorrect input! Try again: ";
	}
	cin.get();
}

									/* fink */
fink::fink() {}

fink::fink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo)
	: abstr_emp(fn, ln, j), reportsto(rpo) {}

fink::fink(const abstr_emp & e, const std::string & rpo) : abstr_emp(e), reportsto(rpo) {}

fink::fink(const fink & e) : abstr_emp(e), reportsto(e.reportsto) {}

void fink::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "Reports to: " << reportsto << endl;
}

void fink::SetAll()
{
	abstr_emp::SetAll();

	cout << "To whom fink reports: ";
	getline(cin, reportsto);
}

									/* highfink */
highfink::highfink() {}

highfink::highfink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo, int ico)
	: abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo) {}

highfink::highfink(const abstr_emp & e, const std::string & rpo, int ico)
	: abstr_emp(e), manager(e, ico), fink(e, rpo) {}

highfink::highfink(const fink & f, int ico)
	: abstr_emp(f), manager(f, ico), fink(f) {}

highfink::highfink(const manager & m, const std::string & rpo)
	: abstr_emp(m), manager(m), fink(m, rpo) {}

highfink::highfink(const highfink & h)
	: abstr_emp(h), manager(h), fink(h) {}

void highfink::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "Employees managed: " << InChargeOf() << endl;
	cout << "Reports to: " << ReportsTo() << endl;
}

void highfink::SetAll()
{
	abstr_emp::SetAll();

	cout << "Enter number of employees managed: ";
	while (!(cin >> InChargeOf()) || InChargeOf() < 0)
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Incorrect input! Try again: ";
	}
	cin.get();

	cout << "To whom fink reports: ";
	getline(cin, ReportsTo());
}