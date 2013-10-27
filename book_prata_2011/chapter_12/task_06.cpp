#include <iostream>
#include <cstdlib>
#include <ctime>

#include "clQueue.h"

using namespace std;

/*  Sorry for garbage and bad style in this code, this is a fast solution  */

/*
	The Bank of Heather would like to know what would happen if it added a second
	ATM. Modify the simulation in this chapter so that it has two queues.Assume that
	a customer will join the first queue if it has fewer people in it than the second
	queue and that the customer will join the second queue otherwise.Again, find a
	value for number of customers per hour that leads to an average wait time of one
	minute. (Note:This is a nonlinear problem in that doubling the number of ATMs
	doesn’t double the number of customers who can be handled per hour with a oneminute
	wait maximum.)
*/

const int MIN_PER_HR = 60;

static bool newcustomer(double x); // is there a new customer?

void task_06() // let it be kind a main func
{
	long turnaways = 0; // turned away by full clQueue
	long customers = 0; // joined the clQueue
	long served = 0; // served during the simulation
	long sum_line_1, sum_line_2; // cumulative line length
	int wait_time_1, wait_time_2; // time until autoteller is free
	long line_wait_1, line_wait_2; // cumulative time in line


// setting things up
	srand(time(0)); // random initializing of rand()

	cout << "Case Study: Bank of Heather Automatic Teller\n";
	cout << "Enter maximum size of Queue: ";
	int qs;
	cin >> qs;
	clQueue line_1(qs), line_2(qs); // line clQueue holds up to qs people

	cout << "Enter the number of simulation hours: ";
	int hours; // hours of simulation
	cin >> hours;
	// simulation will run 1 cycle per minute
	long cyclelimit = MIN_PER_HR * hours; // # of cycles

	double perhour = 1; // average # of arrival per hour
	double min_per_cust; // average time between arrivals
	
	cout << "Enter the number of simulations: ";
	int nSimulationNumber = 0;
	cin >> nSimulationNumber;
	double nPerHourRez = 0.0;

	for (int i = 0; i < nSimulationNumber; ++i)
	{
		do
		{
			min_per_cust = MIN_PER_HR / perhour;
			perhour++;

			Item temp; // new customer data
			turnaways = 0; // turned away by full clQueue
			customers = 0; // joined the clQueue
			served = 0; // served during the simulation
			sum_line_1 = sum_line_2 = 0; // cumulative line length
			wait_time_1 = wait_time_2 = 0; // time until autoteller is free
			line_wait_1 = line_wait_2 = 0; // cumulative time in line

		// running the simulation
			for (int cycle = 0; cycle < cyclelimit; cycle++)
			{
				if (newcustomer(min_per_cust)) // have newcomer
				{
					if (line_1.isfull() && line_2.isfull())
						turnaways++;
					else
					{
						customers++;
						temp.set(cycle); // cycle = time of arrival
						if (line_1.queuecount() <= line_2.queuecount())
							line_1.enqueue(temp); // add newcomer to line
						else
							line_2.enqueue(temp); // add newcomer to line
					}
				}

				// first ATM
				if (wait_time_1 <= 0 && !line_1.isempty())
				{
					line_1.dequeue (temp); // attend next customer
					wait_time_1 = temp.ptime(); // for wait_time minutes
					line_wait_1 += cycle - temp.when();
					served++;
				}

				// second ATM
				if (wait_time_2 <= 0 && !line_2.isempty())
				{
					line_2.dequeue (temp); // attend next customer
					wait_time_2 = temp.ptime(); // for wait_time minutes
					line_wait_2 += cycle - temp.when();
					served++;
				}

				if (wait_time_1 > 0)
					wait_time_1--;
				if (wait_time_2 > 0)
					wait_time_2--;

				sum_line_1 += line_1.queuecount();
				sum_line_2 += line_2.queuecount();
			}
		} while (served != 0 && (double) (line_wait_1 + line_wait_2) / served < 1);

		nPerHourRez += perhour;
	}

	nPerHourRez /= nSimulationNumber; 

// reporting results
	if (customers > 0)
	{
		cout << endl;
		cout << "After " << nSimulationNumber << " number of simulations (2 ATM's)," << endl;
		cout << "in case of average wait time of one minute in queue," << endl;
		cout << "the average number of customers per hour: " << int(nPerHourRez) << endl;
	}
	else
		cout << "No customers!\n";

	cout << "Done!\n";
}


// x = average time, in minutes, between customers
// return value is true if customer shows up this minute
static bool newcustomer(double x)
{
	return (rand() * x / RAND_MAX < 1);
}