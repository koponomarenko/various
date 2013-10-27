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

void abstr_emp::WriteAll(fstream & fout) const
{
	fout << fname << endl;
	fout << lname << endl;
	fout << job << endl;
}

void abstr_emp::GetAll(fstream & fin)
{
	getline(fin, fname);
	getline(fin, lname);
	getline(fin, job);
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

void employee::WriteAll(fstream & fout) const
{
	abstr_emp::WriteAll(fout);
}

void employee::GetAll(fstream & fin)
{
	abstr_emp::GetAll(fin);
}

									/* manager */
manager::manager() : inchargeof(0) {}
manager::manager(const std::string & fn, const std::string & ln, const std::string & j, int ico)
	: employee(fn, ln, j), inchargeof(ico) {}

manager::manager(const employee & e, int ico) : employee(e), inchargeof(ico) {}

manager::manager(const manager & m) : employee(m), inchargeof(m.inchargeof) {}

void manager::ShowAll() const
{
	employee::ShowAll();
	cout << "Employees managed: " << inchargeof << endl;
}

void manager::SetAll()
{
	employee::SetAll();

	cout << "Enter number of employees managed: ";
	while (!(cin >> inchargeof) || inchargeof < 0)
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Incorrect input! Try again: ";
	}
	cin.ignore(cin.rdbuf()->in_avail());
}

void manager::WriteAll(fstream & fout) const
{
	abstr_emp::WriteAll(fout);
	fout << inchargeof << endl;
}

void manager::GetAll(fstream & fin)
{
	abstr_emp::GetAll(fin);
	(fin >> inchargeof).get();
}

									/* fink */
fink::fink() {}

fink::fink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo)
	: employee(fn, ln, j), reportsto(rpo) {}

fink::fink(const employee & e, const std::string & rpo) : employee(e), reportsto(rpo) {}

fink::fink(const fink & e) : employee(e), reportsto(e.reportsto) {}

void fink::ShowAll() const
{
	employee::ShowAll();
	cout << "Reports to: " << reportsto << endl;
}

void fink::SetAll()
{
	employee::SetAll();

	cout << "To whom fink reports: ";
	getline(cin, reportsto);
}

void fink::WriteAll(fstream & fout) const
{
	abstr_emp::WriteAll(fout);
	fout << reportsto << endl;
}

void fink::GetAll(fstream & fin)
{
	abstr_emp::GetAll(fin);
	getline(fin, reportsto);
}

									/* highfink */
highfink::highfink() {}

highfink::highfink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo, int ico)
	: employee(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo) {}

highfink::highfink(const employee & e, const std::string & rpo, int ico)
	: employee(e), manager(e, ico), fink(e, rpo) {}

highfink::highfink(const fink & f, int ico)
	: employee(f), manager(f, ico), fink(f) {}

highfink::highfink(const manager & m, const std::string & rpo)
	: employee(m), manager(m), fink(m, rpo) {}

highfink::highfink(const highfink & h)
	: employee(h), manager(h), fink(h) {}

void highfink::ShowAll() const
{
	employee::ShowAll();
	cout << "Employees managed: " << InChargeOf() << endl;
	cout << "Reports to: " << ReportsTo() << endl;
}

void highfink::SetAll()
{
	employee::SetAll();

	cout << "Enter number of employees managed: ";
	while (!(cin >> InChargeOf()) || InChargeOf() < 0)
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Incorrect input! Try again: ";
	}
	cin.ignore(cin.rdbuf()->in_avail());

	cout << "To whom fink reports: ";
	getline(cin, ReportsTo());
}

void highfink::WriteAll(fstream & fout) const
{
	abstr_emp::WriteAll(fout);
	fout << InChargeOf() << endl;
	fout << ReportsTo() << endl;
}

void highfink::GetAll(fstream & fin)
{
	abstr_emp::GetAll(fin);
	(fin >> InChargeOf()).get();
	getline(fin, ReportsTo());
}