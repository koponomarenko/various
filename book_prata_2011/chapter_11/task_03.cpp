#include <iostream>
#include <cstdlib>
#include <ctime>

#include "clVector.h"

using namespace std;

/*
	Modify Listing 11.15 so that instead of reporting the results of a single trial for a
	particular target/step combination, it reports the highest, lowest, and average num-
	ber of steps for N trials, where N is an integer entered by the user.
*/

void task_03() // let it be kind a main func
{
	using VECTOR::clVector;

	srand(time(0)); // seed random-number generator
	double direction;
	clVector step;
	clVector result(0.0, 0.0);
	unsigned long steps = 0, nMaxSteps = 0, nMinSteps = 0;
	double target;
	double dstep;
	int nTrials = 0;


	cout << "Enter target distance (q to quit): ";
	while (cin >> target)
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;
		
		cout << "Enter a number of trials: ";
		nTrials = 0;
		while (!(cin >> nTrials))
		{
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "Incorrect input! Try again: ";
		}


		while (nTrials)
		{
			while (result.magval() < target)
			{
				direction = rand() % 360;
				step.reset(dstep, direction, clVector::POL);
				result = result + step;
				steps++;
			}

			result.reset(0.0, 0.0);

			if (!nMaxSteps && !nMinSteps)
				nMaxSteps = nMinSteps = steps;

			if (steps > nMaxSteps)
				nMaxSteps = steps;
			if (steps < nMinSteps)
				nMinSteps = steps;

			nTrials--;
		}


		cout << "The highest number of steps: " << nMaxSteps << endl;
		cout << "The lowest number of steps: " << nMinSteps << endl;
		cout << "The average number of steps: " << nMinSteps + (nMaxSteps - nMinSteps) / 2 << endl;


		steps = nMaxSteps = nMinSteps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance (q to quit): ";
	}

	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;
}