#include "clStock.h"

#include <cstring>

using namespace std;


// constructors
clStock::clStock() // default constructor
{
	pszCompany = 0;
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}


clStock::clStock(const char * co, long n, double pr)
{
	if (co)
	{
		pszCompany = new char[strlen(co) + 1];
		strcpy(pszCompany, co);
	}
	else
		pszCompany = 0;
	

	if (n < 0)
	{
		cout << "Number of shares can’t be negative; "
			 << pszCompany << " shares set to 0.\n";
		shares = 0;
	}
	else
		shares = n;
	share_val = pr;
	set_tot();
}

clStock::clStock(const clStock & s)
{
	if (s.pszCompany)
	{
		pszCompany = new char[strlen(s.pszCompany) + 1];
		strcpy(pszCompany, s.pszCompany);
	}
	else
		pszCompany = 0;

	shares = s.shares;
	share_val = s.share_val;
	set_tot();
}


// class destructor
clStock::~clStock() // quiet class destructor
{
	delete [] pszCompany;
}


// other methods
void clStock::buy(long num, double price)
{
	if (num < 0)
	{
		cout << "Number of shares purchased can’t be negative. "
			 << "Transaction is aborted.\n";
	}
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}
}


void clStock::sell(long num, double price)
{
	if (num < 0)
	{
		cout << "Number of shares sold can’t be negative. "
			 << "Transaction is aborted.\n";
	}
	else if (num > shares)
	{
		cout << "You can’t sell more than you have! "
			 << "Transaction is aborted.\n";
	}
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}


void clStock::update(double price)
{
	share_val = price;
	set_tot();
}


const clStock & clStock::topval(const clStock & s) const
{
	if (s.total_val > total_val)
		return s;
	else
		return *this;
}


clStock & clStock::operator=(const clStock & s)
{
	if (this == &s)
		return *this;

	delete [] pszCompany;
	if (s.pszCompany)
	{
		pszCompany = new char[strlen(s.pszCompany) + 1];
		strcpy(pszCompany, s.pszCompany);
	}
	else
		pszCompany = 0;

	shares = s.shares;
	share_val = s.share_val;
	set_tot();
}


ostream & operator<<(ostream & os, const clStock & s)
{
	// set format to #.###
	ios_base::fmtflags orig = os.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = os.precision(3);

	os << "Company: " << s.pszCompany
		 << " Shares: " << s.shares << '\n';
	os << " Share Price: $" << s.share_val;

	// set format to #.##
	os.precision(2);
	os << " Total Worth: $" << s.total_val << '\n';

	// restore original format
	os.setf(orig, ios_base::floatfield);
	os.precision(prec);

	return os;
}

