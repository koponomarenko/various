#include <iostream>
#include <cstdlib>
#include <ctime>

#include "clQueue.h"

using namespace std;

/*  Sorry for garbage and bad style in this code, this is a fast solution  */


/*
	The Bank of Heather has performed a study showing that ATM customers won’t
	wait more than one minute in line. Using the simulation from Listing 12.10, find a
	value for number of customers per hour that leads to an average wait time of one
	minute. (Use at least a 100-hour trial period.)
*/

const int MIN_PER_HR = 60;

static bool newcustomer(double x); // is there a new customer?

void task_05() // let it be kind a main func
{
	long turnaways = 0; // turned away by full clQueue
	long customers = 0; // joined the clQueue
	long served = 0; // served during the simulation
	long sum_line = 0; // cumulative line length
	int wait_time = 0; // time until autoteller is free
	long line_wait = 0; // cumulative time in line


// setting things up
	srand(time(0)); // random initializing of rand()

	cout << "Case Study: Bank of Heather Automatic Teller\n";
	cout << "Enter maximum size of Queue: ";
	int qs;
	cin >> qs;
	clQueue line(qs); // line clQueue holds up to qs people

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
			sum_line = 0; // cumulative line length
			wait_time = 0; // time until autoteller is free
			line_wait = 0; // cumulative time in line

		// running the simulation
			for (int cycle = 0; cycle < cyclelimit; cycle++)
			{
				if (newcustomer(min_per_cust)) // have newcomer
				{
					if (line.isfull())
						turnaways++;
					else
					{
						customers++;
						temp.set(cycle); // cycle = time of arrival
						line.enqueue(temp); // add newcomer to line
					}
				}

				if (wait_time <= 0 && !line.isempty())
				{
					line.dequeue (temp); // attend next customer
					wait_time = temp.ptime(); // for wait_time minutes
					line_wait += cycle - temp.when();
					served++;
				}

				if (wait_time > 0)
					wait_time--;

				sum_line += line.queuecount();
			}
		} while (served != 0 && (double) line_wait / served < 1);

		nPerHourRez += perhour;
	}

	nPerHourRez /= nSimulationNumber; 

// reporting results
	if (customers > 0)
	{
		cout << endl;
		cout << "After " << nSimulationNumber << " number of simulations (1 ATM)," << endl;
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