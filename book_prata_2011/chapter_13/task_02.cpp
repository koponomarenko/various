#include <iostream>

#include "clClassic_2.h"

using namespace std;

/*
	Do Programming Exercise 1 but use dynamic memory allocation instead of fixedsize
	arrays for the various strings tracked by the two classes.
*/

inline void Bravo(const clCd_2 & disk)
{
	disk.Report();
}

void task_02() // let it be kind a main func
{
	clCd_2 Cd("Beatles", "Capitol", 14, 35.5);
	clClassic_2 Classic = clClassic_2("Piano Sonata in B flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);
	clCd_2 * pCd = &Cd;

	cout << "Using object directly:\n";
	Cd.Report(); // use Cd method
	Classic.Report(); // use Classic method

	cout << "Using type cd * pointer to objects:\n";
	pCd->Report(); // use Cd method for cd object
	pCd = &Classic;
	pCd->Report(); // use Classic method for classic object

	cout << "Calling a function with a Cd reference argument:\n";
	Bravo(Cd);
	Bravo(Classic);

	cout << "Testing assignment:";
	clClassic_2 ClassicCopy;
	ClassicCopy = Classic;
	ClassicCopy.Report();
}