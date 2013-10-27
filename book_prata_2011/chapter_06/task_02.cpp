#include <iostream>
using namespace std;

/*
	Write a program that reads up to 10 donation values into an array of double. (Or, if
	you prefer, use an array template object.) The program should terminate input on
	non-numeric input.It should report the average of the numbers and also report
	how many numbers in the array are larger than the average.
*/

void task_02() // let it be kind a main func
{
	const int cArrSize = 10;
	double arrDonation[cArrSize] = {0};
	double nAverage = 0;
	
	cout << "Write up to 10 donation values:" << endl;
	cout << "Write non-numeric symbol to finish entering" << endl;

	int i = 0;
	while ( i < cArrSize && cin >> arrDonation[i])
	{
		nAverage +=  arrDonation[i];
		++i;
	}
	if (i)
		nAverage /= i;


	int nMoreThenAverage = 0;
	for (int j = 0; j < i; ++j)
		if (arrDonation[j] > nAverage)
			++nMoreThenAverage;


	cout << endl;
	cout << "The average of the numbers is " << nAverage << endl;
	cout << nMoreThenAverage <<" numbers in the array are larger than the average" << endl;
}