#include <iostream>
using namespace std;

/*
	Many state lotteries use a variation of the simple lottery portrayed by Listing7.4.
	In these variations you choose several numbers from one set and call them the field
	numbers. For example, you might select five numbers from the field of 1–47).
	You also pick a single number (called a meganumber or a powerball, etc.) from a sec-
	ond range, such as 1–27. To win the grand prize, you have to guess all the picks cor-
	rectly. The chance of winning is the product of the probability of picking all the
	field numbers times the probability of picking the meganumber. 
	For instance, the probability of winning the example described here is the product of the probability
	of picking 5 out of 47 correctly times the probability of picking 1 out of 27 correctly. 
	Modify Listing 7.4 to calculate the probability of winning this kind of lottery.
*/

long double probability(unsigned numbers, unsigned picks);

void task_04() // let it be kind a main func
{
	cout << "If you might select five numbers from the field of 1–47" << endl
		 << "and pick a single number from a second range, such as 1–27," << endl
		 << "the chance of winning is " << probability(47, 5) * probability(27, 1) << endl;
}


long double probability(unsigned numbers, unsigned picks)
{
	long double result = 1.0; // here come some local variables
	long double n;
	unsigned p;

	for (n = numbers, p = picks; p > 0; n--, p--)
		result = result * n / p ;

	return result;
}