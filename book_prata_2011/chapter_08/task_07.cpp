#include <iostream>
using namespace std;

/*
	Modify Listing 8.14 so that it uses two template functions called SumArray() to
	return the sum of the array contents instead of displaying the contents. The pro-
	gram now should report the total number of things and the sum of all the debts.
*/

template <typename T> // template A
T ShowArray(T arr[], int n);

template <typename T> // template B
T ShowArray(T * arr[], int n);

struct debts
{
	char name[50];
	double amount;
};


void task_07() // let it be kind a main func
{
	int things[6] = {13, 31, 103, 301, 310, 130};
	struct debts mr_E[3] =
	{
		{"Ima Wolfe", 2400.0},
		{"Ura Foxe", 1300.0},
		{"Iby Stout", 1800.0}
	};
	double * pd[3];

	// set pointers to the amount members of the structures in mr_E
	for (int i = 0; i < 3; i++)
		pd[i] = &mr_E[i].amount;

	cout << "template A\n";
	cout << "Total number of Mr. E's things: ";
	cout << ShowArray(things, 6) << endl; // uses template A

	cout << endl;
	cout << "template B\n";
	cout << "Sum of Mr. E's debts: ";
	cout << ShowArray(pd, 3) << endl; // uses template B (more specialized)
	cout << endl;
}


template <typename T>
T ShowArray(T arr[], int n)
{
	T Sum = 0;

	for (int i = 0; i < n; i++)
		Sum += arr[i];

	return Sum;
}


template <typename T>
T ShowArray(T * arr[], int n)
{
	T Sum = 0;

	for (int i = 0; i < n; i++)
		Sum += *arr[i];

	return Sum;
}
