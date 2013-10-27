#pragma once

#include <iostream>

class clStock
{
private:
	char * pszCompany; //std::string company;
	int shares;
	double share_val;
	double total_val;

	void set_tot() { total_val = shares * share_val; }

	

public:
	clStock(); // default constructor
	clStock(const char * co, long n = 0, double pr = 0.0);
	clStock(const clStock & s);
	~clStock();

	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	const clStock & topval(const clStock & s) const;

	clStock & operator=(const clStock & s);

	friend std::ostream & operator<<(std::ostream & os, const clStock & s);
};