#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "clVector.h"

using namespace std;

/*
	Modify Listing 11.15 so that it writes the successive locations of the random walker
	into a file. Label each position with the step number. Also have the program write
	the initial conditions (target distance and step size) and the summarized results to
	the file. The file contents might look like this:

	Target Distance: 100, Step Size: 20
	0: (x,y) = (0, 0)
	1: (x,y) = (-11.4715, 16.383)
	2: (x,y) = (-8.68807, -3.42232)
	...
	26: (x,y) = (42.2919, -78.2594)
	27: (x,y) = (58.6749, -89.7309)
	After 27 steps, the subject has the following location:
	(x,y) = (58.6749, -89.7309)
	or
	(m,a) = (107.212, -56.8194)
	Average outward distance per step = 3.97081
*/

void task_01() // let it be kind a main func
{
	using VECTOR::clVector;

	srand(time(0)); // seed random-number generator
	double direction;
	clVector step;
	clVector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;

	ofstream fout;
	fout.open("task_1.txt");
	if (!fout.is_open())
		cout << "Error opening file!" << endl << endl;


	cout << "Enter target distance (q to quit): ";
	while (cin >> target)
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;

		fout << "Target Distance: " << target << ", Step Size: " << dstep << endl;
		while (result.magval() < target)
		{
			fout << steps << ": " << result << endl;

			direction = rand() % 360;
			step.reset(dstep, direction, clVector::POL);
			result = result + step;
			steps++;
		}

		/* write to File */
		fout << "After " << steps << " steps, the subject "
				"has the following location:\n";
		fout << result << endl;
		result.polar_mode(); // switch to polar mode
		fout << " or\n" << result << endl;
		fout << "Average outward distance per step = " 
			 << result.magval()/steps << endl;

		result.rect_mode();

		/* write to Display */
		cout << "After " << steps << " steps, the subject "
				"has the following location:\n";
		cout << result << endl;
		result.polar_mode(); // switch to polar mode
		cout << " or\n" << result << endl;
		cout << "Average outward distance per step = " 
			 << result.magval()/steps << endl;


		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance (q to quit): ";
	}

	cout << "Bye!\n";
	fout.close();
	cin.clear();
	while (cin.get() != '\n')
		continue;
}