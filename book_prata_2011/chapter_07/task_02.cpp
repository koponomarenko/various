#include <iostream>
using namespace std;

/*
	Write a program that asks the user to enter up to 10 golf scores, which are to be
	stored in an array. You should provide a means for the user to terminate input prior
	to entering 10 scores. The program should display all the scores on one line and
	report the average score. Handle input, display, and the average calculation with
	three separate array-processing functions.
*/

int InputScores(int * pBegin, int * pEnd);
void DisplayScores(int * pBegin, int * pEnd);
int AverageOfScores(int * pBegin, int * pEnd);

void task_02() // let it be kind a main func
{
	int aGolfScores[10] = {0};
	int nScores = 0;

	nScores = InputScores(aGolfScores, aGolfScores + 10);

	DisplayScores(aGolfScores, aGolfScores + nScores);

	cout << endl;
}


int InputScores(int * pBegin, int * pEnd)
{
	int * pt = pBegin;

	do
	{
		cout << "Enter up to 10 golf scores by spaces: " << endl;
		while (pt != pEnd && (cin >> *pt))
		{
			++pt;
			if (cin.peek() == '\n')
				break;
		}

		if (!cin) // check for bad input
		{
			cin.clear();
			cout << "Incorrect input" << endl;
			pt = pBegin;
		}

		if (cin.rdbuf()->in_avail())
			cin.ignore(cin.rdbuf()->in_avail());
	} while (pt == pBegin);

	return pt - pBegin; // number of entered digit
}


void DisplayScores(int * pBegin, int * pEnd)
{
	cout << "Scores: ";
	for (int * pt = pBegin; pt != pEnd; ++pt)
		cout << *pt << ' ';

	cout << endl;
	cout << "Average: " << AverageOfScores(pBegin, pEnd) << endl;
}


int AverageOfScores(int * pBegin, int * pEnd)
{
	int nAverage = 0;

	for (int * pt = pBegin; pt != pEnd; ++pt)
		nAverage += *pt;

	nAverage /= pEnd - pBegin;

	return nAverage;
}