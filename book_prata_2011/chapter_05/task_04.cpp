#include <iostream>
using namespace std;

/*
	Daphne invests $100 at 10% simple interest.That is,every year,the investment earns
	10% of the original investment,or $10 each and every year:
	interest = 0.10 x original balance
	At the same time,Cleo invests $100 at 5% compound interest.That is,interest is 5%
	of the current balance,including previous additions of interest:
	interest = 0.05 x current balance
	Cleo earns 5% of $100 the first year,giving her $105.The next year she earns 5% of
	$105,or $5.25,and so on. Write a program that finds how many years it takes for
	the value of Cleo’s investment to exceed the value of Daphne’s investment and then
	displays the value of both investments at that time.
*/

void task_04() // let it be kind a main func
{
	const int nStartBalance = 100;
	int nYears = 0;
	double nDaphneBalance = nStartBalance;
	double nCleoBalance = nStartBalance;

	cout<<"Both girls inested $100\n";

	while (nDaphneBalance >= nCleoBalance)
	{
		nDaphneBalance += 0.10 * nStartBalance; // simple interest
		nCleoBalance += 0.05 * nCleoBalance; // compound interest
		++nYears;
	}

	cout<<"and after "<<nYears<<" year(s)\n";
	cout<<"Daphne Balance has "<<nDaphneBalance<<endl;
	cout<<"Cleo Balance has "<<nCleoBalance<<endl;
}