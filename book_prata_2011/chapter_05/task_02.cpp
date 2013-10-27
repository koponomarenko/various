#include <iostream>
#include <vector>
using namespace std;

/*
	Redo Listing 5.4 using a type array object instead of a built-in array and type
	long double instead of long long. Find the value of 100!
*/

void task_02() // let it be kind a main func
{
	// in case 100! we will lose data. maximun type long double can hold 31!

	const int ArSize = 100; // example of external declaration
	vector <long double> factorials(ArSize);

	factorials[1] = factorials[0] = 1.0L;
	for (int i = 2; i < ArSize; i++)
		factorials[i] = i * factorials[i-1];

	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.precision(0);
	for (int i = 0; i < ArSize; i++)
		cout<<i<<"! = "<<factorials[i]<<endl;
}