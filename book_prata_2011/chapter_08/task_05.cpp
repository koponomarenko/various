#include <iostream>
using namespace std;

/*
	Write a template function max5() that takes as its argument an array of five items
	of type T and returns the largest item in the array. (Because the size is fixed, it can
	be hard-coded into the loop instead of being passed as an argument.) Test it in a
	program that uses the function with an array of five int value and an array of five
	double values.
*/

template <typename T>
T max5(const T * pArr);

template <typename T>
inline void show(const T * pArr);

void task_05() // let it be kind a main func
{
	int ArrInt[] = {1, 7, 3, 4, 5};
	double ArrDouble[] = {1.1, 2.2, 9.3, 4.4, 5.5};
	
	cout << "Int Arr: ";
	show(ArrInt);
	cout << "Max from Int Arr: " << max5(ArrInt) << endl;
	cout << endl;
	cout << "Double Arr: ";
	show(ArrDouble);
	cout << "Max from Int Arr: " << max5(ArrDouble) << endl;
}


template <typename T>
T max5(const T * pArr)
{
	T Largest = pArr[0];

	for (int i = 0; i < 5; ++i)
		if (pArr[i] > Largest)
			Largest = pArr[i];

	return Largest;
}


template <typename T>
void show(const T * pArr)
{
	for (int i = 0; i < 5; ++i)
		cout << pArr[i] << ' ';
	cout << endl;
}